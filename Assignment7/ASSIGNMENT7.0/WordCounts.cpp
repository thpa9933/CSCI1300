//Thomas Payne
//Assignment 7
//Chelsea Chandler

#include <iostream>
#include <fstream>
#include <sstream>
#include "WordCounts.h"
#include "SpellChecker.h"
using namespace std;

WordCounts::WordCounts()
{

    for(int i = 0; i < 10000; i++)
    {
        trackWords[i] = 0;
        actualWords[i] = "";
    }
    arraySize = 0;
}

WordCounts::~WordCounts()
{

}


string WordCounts::lowerNopunct(string str)
{
    for(int i = 0; i <= str.length(); i++)
    {
        str[i] = tolower(str[i]); // make lowercase
    }

    string sentence = "";
    string temp;
    string punct = "!@#$%^&?*()_-+=></|;'{}[].~:";
    for(int j = 0; j <= str.length(); j++)
    {
        temp = "";
        if(j == str.length()) //if were at end of string
        {
            temp = str;
            // << temp <<endl;
        }
        else if(str[j] == ' ')
        {
            temp = str.substr(0,j);
            str.erase(0, j+1);
            j = 0;
            // << temp <<endl;
        }

        if(temp.length() > 0) // if there is something in the string
        {
            int h = 0; //to start at beginning of punct again
            while(h <= punct.length())
            {
                if(temp[0] == punct[h]) //if beginning of temp is a punct
                {
                    temp.erase(0,1);
                    h = 0; //start punct over
                }
                else
                {
                    h++; //otherwise continue to loop through punct length
                }
            }

            int f = 0;
            int g;
            while(f <= punct.length())
            {
                g = temp.length() - 1; // get the end of the string
                if(temp[g] == punct[f])
                {
                    temp.erase(g, 1); //just erasing the position
                    f = 0;
                }
                else
                {
                    f++;
                }
            }
            temp += ' ';
        }
        sentence += temp;
    }
      for(int b = 0; b < sentence.length(); b++) //removing space at the last end
        {
            if(b = sentence.length())
                sentence.erase(b-1,1);
        }
   return sentence;
}


int WordCounts::Split(string str, string array[])
{
    int a = 0;
    int b = 0;
    char sep = ' ';

    if(str.length() == 0)
    {
    return 0;
    }

    string seg;
    for(int i = 0; i <= str.length(); i++)
    {
        if((str[i] == sep) || (i == str.length()))
        {
            seg = str.substr(a, i-a);
            a = i + 1;
            array[b] = seg;
            b++;
        }
    }
    return b;
}

//create an array to use in your split funciton
//unpunct and split the sentence
//determine if word is already in the words array, if so, just increase the count
//if not, add the word to the array and increase the count 
void WordCounts::tallyWords(string sentence1)
{
    string splitArray[10000];
    newStr = lowerNopunct(sentence1);
    
    int lines = Split(newStr, splitArray); //split returns values for size of array
    //cout << sentence1 << endl; 

    for(int i = 0; i < lines; i++) 
    {
       //cout << splitArray[i] << endl; 
        splitArray[i] = lowerNopunct(splitArray[i]); //fills splitArray with modified words  

        bool isfound = false; //set false so it enters the loop 
        for(int j = 0; j < arraySize; j++) //loop through size (initially 0)
        {
            if(splitArray[i] == actualWords[j]) //if already in the array 
            {
                trackWords[j] = trackWords[j] + 1; //increase the count 
                isfound = true; //make true so we can make it false again 

            }
        }

        if(isfound == false) //if its not in the array
        {
            actualWords[arraySize] = splitArray[i]; //add to the array and make the count 1
            trackWords[arraySize] = 1;
            arraySize++; //increase the array size because a new word was added (only place where arraysize is increased)
        }
    }
    
}


//loops through array size and because actualWords and trackWords index's match up, you can just return the count at that word 
int WordCounts::getTally(string word)
{
    for(int i = 0; i < arraySize; i++)
    {
        if(actualWords[i] == word)
        {
            return trackWords[i];
        }
       
    }
    return 0; 
}

//make all counts = 0 if this is called
void WordCounts::resetTally()
{
    for(int i = 0; i < arraySize; i++){ //make trackWords all 0
        trackWords[i] = 0;
    }
}

//use this array for the next array
//because trackWords and actualWords are at the same index, when you swap trackWords, you can just swap actual words
//even though actual words is a string 
void WordCounts::sortArray(int trackWords[], string actualWords[], int size)
{

    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i = 0; i < arraySize-1; i++)
            if(trackWords[i] < trackWords[i + 1])
            {
                int temp = trackWords[i];
                string strTemp = actualWords[i];
                trackWords[i] = trackWords[i + 1];
                trackWords[i + 1] = temp;
                actualWords[i + 1] = strTemp;
                sorted = false;
            }
    }
}

//call sortArray
//now that array are sorted, just fill the paramater arrays with the first n values of the actual and trackWords array
int WordCounts::mostTimes(string maxWords[], int maxCount[], int n)
{
    for(int i = 0; i < n; i++)
    {
        maxWords[i] = actualWords[i];
        maxCount[i] = trackWords[i];
    }
    
    if(arraySize < n) //cant really fill the arrays because there not enough words to fill it with 
    {
        return arraySize; 
    } 
    else
    {
        return n; 
    }
    return 0;
}

