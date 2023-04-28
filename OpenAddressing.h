#ifndef HASHING_OPENADDRESSING_H
#define HASHING_OPENADDRESSING_H
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
using std::cout, std::endl, std::function, std::nullopt, std::optional, std::string, std::vector;

template<typename Keyable>
class QuadraticProbing {
private:
    enum state {EMPTY, FILLED, REMOVED};
    struct hashable {
        Keyable item;
        state status;
    };
    vector<hashable> table;
    function<string(Keyable)> getKey;
    unsigned long numItems;

    unsigned long hornerHash(string key) const {
        unsigned long hashVal = 0;
        for (char letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % table.size();
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    void rehash(int& reads) {
        // Store a copy of the hash table
        vector<hashable> oldTable = table;

        // Empty the table
        table.clear();
        numItems = 0;

        // Resize the table to new size
        table.resize(nextPrime(oldTable.size() * 2));

        // Reinsert all FILLED items
        for (int i = 0; i < oldTable.size(); ++i) {
            if (oldTable[i].status == FILLED) {
                insert(oldTable[i].item, reads);
                reads++;
            }
            reads++;
        }

    }

public:
    // Constructor
    QuadraticProbing(unsigned long tableSize, function<string(Keyable)> getKey) {
        // This will fill the table with default Keyables and EMPTY statuses
        table.resize(nextPrime(tableSize));
        this->getKey = getKey;
        numItems = 0;
    }

    // Insert
    void insert(Keyable item, int& reads) {
        // Get the key from the item
        string key = getKey(item);
        if (!find(key, reads)) {
            // Hash the key to get an index
            unsigned long index = hornerHash(key);
            // Probe until we find a non-filled index
            //1 read
            int i=0;
            while (table[index].status == FILLED) {
                reads ++;
                // Add one to the index for linear probing
                //change for quadratic
                index += i*i;
                index %= table.size();
                i++;
            }
            table[index].item = item;
            //1 read
            if (table[index].status == EMPTY) {
                reads++;
                ++numItems;
                table[index].status = FILLED;
                // Rehash when more than half the table is filled
                if (numItems > table.size()/2) {
                    rehash(reads);
                }
            } else {
                table[index].status = FILLED;
            }
        }
    }

    // Find
    optional<Keyable> find(string key, int& reads) const {
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        int i=0;
        while (table[index].status != EMPTY) {
            reads ++;
            // Check the index to see if the key matches
            //1 read
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                reads++;
                return table[index].item;
            }
            reads++;
            reads++;
            // Add one to the index for linear probing
            //change for quadratic
            index += i*i;
            index %= table.size();
            i++;
        }
        // We didn't find the item
        return nullopt;
    }

    // Remove
    bool remove(string key) {
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        int i =0;
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                // Remove it
                table[index].status = REMOVED;
                table[index].item = Keyable();
                return true;
            }
            // Add one to the index for linear probing
            //change for quadratic

            index += i*i;
            index %= table.size();
            i++;
        }
        // We didn't find the item
        return false;
    }

    // Print the table
    void printTable() const {
        cout << "Beginning of table" << endl;
        for (unsigned long i = 0; i < table.size(); ++i) {
            cout << i << ": ";
            if (table[i].status == FILLED) {
                cout << table[i].item;
            } else if (table[i].status == REMOVED) {
                cout << "X";
            }
            cout << endl;
        }
        cout << "End of table" << endl;
    }
    int getTableSize(){
        return table.size();
    }
};


#endif
