//Thomas Payne
//Assignment 7
//Chelsea Chandler

#include <iostream>
using namespace std;

class WordCounts{
public:
    WordCounts();
    ~WordCounts();
    void tallyWords(string);
    int getTally(string);
    void resetTally();
    int mostTimes(string[], int[], int);

    string lowerNopunct(string);
    int Split(string, string[]);

    string newStr;
    int arraySize; // does not equal zero because must continue to increase with each new sentence
    string actualWords[10000];
    int trackWords[10000];

    string maxWords[10000];
    int maxCount[10000];
    int tempCount[20];


    void sortArray(int[], string[], int);

private:


};

