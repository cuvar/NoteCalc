//============================================================================
// Name        : NoteCalculator.cpp
// Author      : cuvar
// Version     : 2.0
// Description : Calculator for notes
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "..\..\helper.h"

using namespace std;



string proveString(string);
void bestPoints();
void getInput();
float calcNotes();
float calcClasstests();
float calcAverage();



string pcText;
float pc;
vector<int> notes, classtests;



//Main
//
int main() {

	string text = "";
	float average = 0;

	//Loop for getting calculating notes
    while(true) {
        cout << "--------------------NoteCalculator--------------------" << endl;

        //get notes and subject
        cout << "Text: ";
        getline(cin, text);

        if(text == "b" || text == "best"){
        	bestPoints();
        }

        else {
        	//gets every variable
        	getInput();

        	//calcs notes-, classtests- and general average
            average = calcAverage();

            if(average != -1){
            	cout << "Average: " << average << endl << endl << endl;
            } else {
            	cout << endl << "Error: Invalid input!" << endl;
            }
        }
    }
}



//gets every variable
//
void getInput(){
	string nText, ctText;

	//Percentage
	//
	cout << "Percentage: ";
    getline(cin, pcText);

    if (pcText == ""){
    	pc = 0;
    }
    else {
    	pc = stod(pcText) / 100;
    }



    //Notes
    //

	//getting notes from cli
	cout << "Notes: ";
	getline(cin, nText);

	//if classtests were written
	if(nText != ""){
		//removing every spaces at begin/end
		nText = proveString(nText);

		//splitting in string vector
		vector<string> n = split(nText, ' ');

		//formating in int vector
		for(string s : n){
			notes.push_back(stoi(s));
		}
	}



	//Classtests
	//

	//getting notes from cli
	cout << "Classtests: ";
	getline(cin, ctText);

	//if classtests were written
	if(ctText != ""){
		//removing every spaces at begin/end
		ctText = proveString(ctText);

		//splitting in string vector
		vector<string> ct = split(ctText, ' ');

		//forming in int vector
		for(string s : ct){
			classtests.push_back(stoi(s));
		}
	}
}



//Gets notes from cli and calcs average
//
float calcNotes(){
	float av = 0;
	int k = 0;

	if(notes.size() > 0){
		//calculating notes with percentage
		for(int i : notes){
			if(i > 15 || i < 0){
				return -1;
			}
			else{
				av += i;
				k++;
			}
		}

		av = (av / k) * (1 - pc);
		return av;
	}
	else {
		return 0;
	}
}



//Gets classtests from cli and calcs average
//
float calcClasstests(){
	float av = 0;
	int k = 0;

	if(classtests.size() > 0){
		//calculating notes with percentage
		for(int i : classtests){
			if(i > 15 || i < 0){
				return -1;
			}
			else{
				av += i;
				k++;
			}
		}

		av = (av / k) * pc;
		return av;
	}
	else {
		return 0;
	}
}



//calcs average
//
float calcAverage(){
	float notesAv, classtestAv, av;

	notesAv = classtestAv = av = -1;

	//calcs notes and classtests
    if(notes.size() == 0){
    	notesAv = 0;
    } else {
    	notesAv = calcNotes();
    }

    if(classtests.size() == 0){
    	classtestAv = 0;
    } else {
    	classtestAv = calcClasstests();
    }


    //wenn zahl > 15 || < 0 eingegeben wird
    // -> Fehlermeldung
    if(notesAv == -1 || classtestAv == -1){
    	return av;
    }

    else {
    	av = notesAv + classtestAv;
    	//av = roundf(average * 100) / 100;
    	return av;
    }
}



//searches best points for getting over a certain average
//
void bestPoints(){
	float av, limit;
	int i, j, k;
	string s;
	bool greater = false;

	i = j = k = av = limit = 0;

	getInput();

	//getting limit
	cout << "Limit: ";
	getline(cin, s);
	cout << endl;
	limit = stof(s);

	//getting average
	av = calcAverage();

	//checking average
	if(av >= limit){
		cout << "You are already over your limit!" << endl << endl;
	}

	else {
		for(i = limit; i <= 15; i++){
			notes.push_back(i);

			av = calcAverage();
			if(av >= limit){
				greater = true;
				notes.pop_back();
				break;
			}
			notes.pop_back();
		}

		if(greater){
			cout << "Needed normal points: " << i << endl << endl;
		}

		else {
			cout << "Not possible" << endl;
		}

	}

}



//Proves if s has spaces at the beginning/ end
//
string proveString(string s){
    A:{
        if(s[0] == ' '){
            s.erase(s.begin());
            goto A;
        }
        if(s[s.length()-1] == ' '){
            s.erase(s.end() - 1);
            goto A;
        }
    }

    return s;
}
