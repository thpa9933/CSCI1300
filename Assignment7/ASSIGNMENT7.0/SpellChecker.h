//Thomas Payne
//Assignment 7
//Chelsea Chandler

#include <iostream>
using namespace std;

class SpellChecker{
public:
    SpellChecker(); //default constructor
    SpellChecker(string); //loaded constructor
    SpellChecker(string, string, string); //third constructor
    ~SpellChecker();
    bool readValidWords(string);
    bool readCorrectedWords(string);

    bool setStartMarker(char);
    bool setEndMarker(char);
    char getStartMarker();
    char getEndMarker();
    string repair(string);
    string lowerNopunct(string);
    int Split(string, string[]);

    string str1;
    string str2;
    string language;
    int count;
    int count2;

    string validWords[10000];
    string correctedWords[10000];
    string misspelledWords[10000];
    string correctThis[100];

private:
    char start_marker;
    char end_marker;


};
