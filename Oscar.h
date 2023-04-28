//
// Created by Henry Kuzma on 1/27/2023.
//

#ifndef PROJECT1_OSCAR_H
#define PROJECT1_OSCAR_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl, std::ifstream, std::left, std::ostream;
using std::right, std::setw, std::string, std::vector;

class Oscar {
private:
    string row;
    int year_release;
    int ceremony;
    string category;
    string name;
    string film;
    string winner;
public:
    //constructor
    Oscar(){
        row = "";
        year_release = 0;
        ceremony = 0;
        category = "";
        name = "";
        film ="";
        winner="";
    }
    Oscar(string row, int year, int ceremony, string category, string name, string film, string winner) {

        //set variable values

        this->row = row;
        year_release = year;
        this->ceremony = ceremony;
        this->category = category;
        this->name = name;
        this->film = film;
        this->winner = winner;

    }

    //getters
    string getRow() const {
        return row;
    }

    int getYear() const {
        return year_release;
    }

    int getCeremony() const {
        return ceremony;
    }

    string getCategory() const {
        return category;
    }

    string getName() const {
        return name;
    }

    string getFilm() const {
        return film;
    }

    string getWinner() const {
        return winner;
    }

    //setters
    void setRow(string row) {
        this->row = row;
    }

    void setYear(int year) {
        year_release = year;
    }

    void setCeremony(int ceremony) {
        this->ceremony = ceremony;
    }

    void setCategory(string category) {
        this->category = category;
    }

    void setFilm(string film) {
        this->film = film;
    }

    void setWinner(string winner) {
        this->winner = winner;
    }
};

void getDataFromFile(string filename, vector<Oscar>& oscars){
    //create file
    ifstream inFile;
    //open file
    inFile.open(filename);

    //variables to read into
    string header = "", headerStorage;
    int year_release = -1, ceremony = -1 , intjunk = -1;
    string category = "", name = "", film = "", winner = "", junk = "", row ="";
    char comma, quote;

    //check file is good to read
    if (inFile) {
        //get header
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, junk, ',');
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        //cout << header << " " << "\n";
    }

    //while file can be read from and not at end of file
    while(inFile && inFile.peek() != EOF){

        //row
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile,row, '"');
            inFile >> comma;
        }else{
            getline(inFile, row, ',');
        }

        //year_release
        inFile >> year_release >> comma;

        //don't take ceremony year
        inFile >> intjunk >> comma;

        //ceremony
        inFile >> ceremony >> comma;

        //category
        getline(inFile, category, ',');

        //name
        if(inFile.peek() == '"'){
            inFile >> quote;
            getline(inFile, name, '"');
            inFile >> comma;
        }
        else {
            getline(inFile, name, ',');
        }

        //film
        getline(inFile, film, ',');

        //winner
        getline(inFile, winner, '\n');
        //create oscar object and place into vector
        oscars.push_back(Oscar(row, year_release, ceremony, category, name, film, winner));
    }

    //CLOSE FILE
    inFile.close();
}

void checkMostWins(){

}





#endif //PROJECT1_OSCAR_H
