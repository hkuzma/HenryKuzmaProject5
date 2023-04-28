#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Oscar.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Examples of getKey functions
 *
 * If your unique attribute is a string:
 * string getLecturerName(Lecturer lec) {
 *     return lec.getName();
 * }
 *
 * If your unique attribute is not a string:
 * string getEmployeeID(Employee e) {
 *     return to_string(e.getID());
 * }
 *
 * If you only have one unique field in your class,
 * concatenate it with another field for your second key:
 * string getLecturerClassName(Lecturer lec) {
 *     return to_string(lec.getClass1()) + lec.getName();
 * }
 * */

//Hash function 1
string getOscarRow(Oscar e) {
    return e.getRow();
}
//hash function 2
string getOscarFilmCategory(Oscar e){
    return (e.getFilm() + e.getWinner());
}

int main() {

    vector <Oscar> oscars;
    getDataFromFile("../oscar_data.csv", oscars);

    int reads;
    //Separate Chaining first function
    SeparateChaining<Oscar> SeparateChainingGetOscarRow[5] = {
            SeparateChaining<Oscar>(11500,getOscarRow),
            SeparateChaining<Oscar>(15000,getOscarRow),
            SeparateChaining<Oscar>(17500,getOscarRow),
            SeparateChaining<Oscar>(22000,getOscarRow),
            SeparateChaining<Oscar>(25000,getOscarRow)

    };
    //Separate Chaining second function
    SeparateChaining<Oscar> SeparateChainingGetOscarFilmCategory[5] = {
            SeparateChaining<Oscar>(11500,getOscarFilmCategory),
            SeparateChaining<Oscar>(15000,getOscarFilmCategory),
            SeparateChaining<Oscar>(17500,getOscarFilmCategory),
            SeparateChaining<Oscar>(22000,getOscarFilmCategory),
            SeparateChaining<Oscar>(25000,getOscarFilmCategory)

    };
    //Open Addressing first function
    QuadraticProbing<Oscar> OpenAddressingGetOscarRow[5] = {
            QuadraticProbing<Oscar>(11500, getOscarRow),
            QuadraticProbing<Oscar>(15000,getOscarRow),
            QuadraticProbing<Oscar>(17500,getOscarRow),
            QuadraticProbing<Oscar>(22000,getOscarRow),
            QuadraticProbing<Oscar>(25000,getOscarRow)

    };
    //Open Addressing second function
    QuadraticProbing<Oscar> OpenAddressingGetOscarFilmCategory[5] = {
            QuadraticProbing<Oscar>(11500,getOscarFilmCategory),
            QuadraticProbing<Oscar>(15000,getOscarFilmCategory),
            QuadraticProbing<Oscar>(17500,getOscarFilmCategory),
            QuadraticProbing<Oscar>(22000,getOscarFilmCategory),
            QuadraticProbing<Oscar>(25000,getOscarFilmCategory)

    };
    ofstream outFile1;
    ofstream outFile2;
    ofstream outFile3;
    ofstream outFile4;
    ofstream outFile5;
    ofstream outFile6;
    ofstream outFile7;
    ofstream outFile8;
    ofstream outFile9;
    ofstream outFile10;
    ofstream outFile11;
    ofstream outFile12;
    ofstream outFile13;
    ofstream outFile14;
    ofstream outFile15;
    ofstream outFile16;
    ofstream outFile17;
    ofstream outFile18;
    ofstream outFile19;
    ofstream outFile20;


    outFile1.open("../SCRow1Reads.txt");
    outFile2.open("../SCRow2Reads.txt");
    outFile3.open("../SCRow3Reads.txt");
    outFile4.open("../SCRow4Reads.txt");
    outFile5.open("../SCRow5Reads.txt");

    outFile6.open("../SCFilmCat1Reads.txt");
    outFile7.open("../SCFilmCat2Reads.txt");
    outFile8.open("../SCFilmCat3Reads.txt");
    outFile9.open("../SCFilmCat4Reads.txt");
    outFile10.open("../SCFilmCat5Reads.txt");

    outFile11.open("../OARow1Reads.txt");
    outFile12.open("../OARow2Reads.txt");
    outFile13.open("../OARow3Reads.txt");
    outFile14.open("../OARow4Reads.txt");
    outFile15.open("../OARow5Reads.txt");

    outFile16.open("../OAFilmCat1Reads.txt");
    outFile17.open("../OAFilmCat2Reads.txt");
    outFile18.open("../OAFilmCat3Reads.txt");
    outFile19.open("../OAFilmCat4Reads.txt");
    outFile20.open("../OAFilmCat5Reads.txt");

    for(int i=0;i<10759; i++){

        reads = 0;
        SeparateChainingGetOscarRow[0].insert(oscars[i], reads);
        outFile1 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarRow[1].insert(oscars[i], reads);
        outFile2 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarRow[2].insert(oscars[i], reads);
        outFile3 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarRow[3].insert(oscars[i], reads);
        outFile4 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarRow[4].insert(oscars[i], reads);
        outFile5 << reads << "\n";

        reads = 0;
        SeparateChainingGetOscarFilmCategory[0].insert(oscars[i], reads);
        outFile6 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarFilmCategory[1].insert(oscars[i], reads);
        outFile7 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarFilmCategory[2].insert(oscars[i], reads);
        outFile8 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarFilmCategory[3].insert(oscars[i], reads);
        outFile9 << reads << "\n";
        reads = 0;
        SeparateChainingGetOscarFilmCategory[4].insert(oscars[i], reads);
        outFile10 << reads << "\n";

        reads = 0;
        OpenAddressingGetOscarRow[0].insert(oscars[i], reads);
        outFile11 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarRow[1].insert(oscars[i], reads);
        outFile12 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarRow[2].insert(oscars[i], reads);
        outFile13 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarRow[3].insert(oscars[i], reads);
        outFile14 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarRow[4].insert(oscars[i], reads);
        outFile15 << reads << "\n";


        reads = 0;
        OpenAddressingGetOscarFilmCategory[0].insert(oscars[i], reads);
        outFile16 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarFilmCategory[1].insert(oscars[i], reads);
        outFile17 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarFilmCategory[2].insert(oscars[i], reads);
        outFile18 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarFilmCategory[3].insert(oscars[i], reads);
        outFile19 << reads << "\n";
        reads = 0;
        OpenAddressingGetOscarFilmCategory[4].insert(oscars[i], reads);
        outFile20 << reads << "\n";

    }
    cout << "Row(1): " << OpenAddressingGetOscarRow[0].getTableSize() << "\n";
    cout << "Row(2): " << OpenAddressingGetOscarRow[1].getTableSize() << "\n";
    cout << "Row(3): " << OpenAddressingGetOscarRow[2].getTableSize() << "\n";
    cout << "Row(4): " << OpenAddressingGetOscarRow[3].getTableSize() << "\n";
    cout << "Row(5): " << OpenAddressingGetOscarRow[4].getTableSize() << "\n";

    cout << "FilmCAT(1): " << OpenAddressingGetOscarFilmCategory[0].getTableSize() << "\n";
    cout << "FilmCAT(2): " << OpenAddressingGetOscarFilmCategory[1].getTableSize() << "\n";
    cout << "FilmCAT(3): " << OpenAddressingGetOscarFilmCategory[2].getTableSize() << "\n";
    cout << "FilmCAT(4): " << OpenAddressingGetOscarFilmCategory[3].getTableSize() << "\n";
    cout << "FilmCAT(5): " << OpenAddressingGetOscarFilmCategory[4].getTableSize() << "\n";



    outFile1.close();
    outFile2.close();
    outFile3.close();
    outFile4.close();
    outFile5.close();
    outFile6.close();
    outFile7.close();
    outFile8.close();
    outFile9.close();
    outFile10.close();
    outFile11.close();
    outFile12.close();
    outFile13.close();
    outFile14.close();
    outFile15.close();
    outFile16.close();
    outFile17.close();
    outFile18.close();
    outFile19.close();
    outFile20.close();


    return 0;
}
