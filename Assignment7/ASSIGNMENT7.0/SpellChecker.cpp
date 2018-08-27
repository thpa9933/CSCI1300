//Thomas Payne
//Assignment 7
//Chelsea Chandler

#include <iostream>
#include <fstream>
#include "SpellChecker.h"
using namespace std;

SpellChecker::SpellChecker()
{
language="";
    for(int i = 0; i < 10000; i++)
    {
    validWords[i] = "";
    misspelledWords[i]="";
    correctedWords[i]="";
    }
}

SpellChecker::SpellChecker(string x)
{
    language = x;
}

//reading in files, parsing the files using getline and storing them in correct array
//second file is split at the tab, before the tab is stored in misspelled, after the tab is stored in corrected
//function determines the amount of length of the future arrays (count , count 2)
SpellChecker::SpellChecker(string x, string validFilename, string correctedFilename)
{
    language = x;
    ifstream inStream;
    inStream.open(validFilename);

    count = 0;
    while(getline(inStream, str1))
    {
        validWords[count] = str1;
        count++;
    }
    inStream.close();

    ifstream file2;
    file2.open(correctedFilename);
    count2 = 0;

    while(getline(file2, str2))
    {
        for(int j = 0; j < str2.length(); j++)
        {
            if(str2[j] == '\t')
            {
                misspelledWords[count2] = str2.substr(0,j);
                str2.erase(0, j+1);
                correctedWords[count2] = str2;
                count2++;
            }
        }
    }

    file2.close();
    readValidWords(validFilename);
    readCorrectedWords(correctedFilename);
}

SpellChecker::~SpellChecker()
{
//dtor
}


//adds words from file into validWords
//return true if it worked
bool SpellChecker::readValidWords(string validFilename)
{
    ifstream dataFile1;
    dataFile1.open(validFilename);
    if(dataFile1.is_open())
    {
        string str;
        while(getline(dataFile1, str))
        {
            validWords[count] = str;
            count++;
        }
    dataFile1.close();
    return true;
    }
    else
        return false;
}


//reads word from file
//gets line
//parses words at tab
//deletes the word and space(k+1)from the line
//stores the word in correct array
//returns true if it worked
bool SpellChecker::readCorrectedWords(string correctedFilename)
{
    ifstream dataFile2;
    dataFile2.open(correctedFilename);
    if(dataFile2.is_open())
    {
        string str0;
        while(getline(dataFile2, str0))
        {
            for(int k = 0; k < str0.length(); k++)
            {
                if(str0[k] == '\t')
                {
                    misspelledWords[count2] = str0.substr(0, k);
                    str0.erase(0, k+1);
                    correctedWords[count2] = str0;
                    count2++;
                }
            }
        }

    dataFile2.close();
    return true;
    }
    else
        return false;
}


//takes in start marker from private 
//return true if it worked
bool SpellChecker::setStartMarker(char start)
{
    start_marker = start;
    if(start_marker == start)
        return true;
    else
        return false;
}

//takes in end marker from private
//return true it worked
bool SpellChecker::setEndMarker(char finish)
{
    end_marker = finish;
    if(end_marker == finish)
        return true;
    else
        return false;
}

//access .h to get private variables
char SpellChecker::getStartMarker()
{
    return start_marker;
}


char SpellChecker::getEndMarker()
{
    return end_marker;
}

//this was a pain in the butt 
//essentially takes in a string, makes it lowercase
//removes punct from the left side up until an alphabetical character
//removes punct from the right side up until an alphabetical character
//stores these into the a temp string 
//build a sentence from the temp string 
string SpellChecker::lowerNopunct(string str)
{
    for(int i = 0; i <= str.length(); i++)
    {
        str[i] = tolower(str[i]); // make lowercase
    }

    string sentence = "";
    string temp;
    string punct = "!@#$%^&?*()_-+=></|;'{}[],.~:";
    for(int j = 0; j <= str.length(); j++) //increments through str 
    {
        temp = ""; //resets temp string because we dont want it to add on to the previous temp 
        if(j == str.length()) //if were at end of string
        {                                       
            temp = str;
            //cout << temp <<endl;
        }
        else if(str[j] == ' ') //if j reaches a space, were going to want to remove everything before that space 
        {                      //and store it into temp, then remove those characters including the space .erase(0,j+1)
            temp = str.substr(0,j);
            str.erase(0, j+1); 
            j = 0; //starts j at the beginning of the string, after the 'temp' string and the space
            //cout << temp <<endl;
        }

        if(temp.length() > 0) // this is where we start to remove the frontend punct 
        {
            int h = 0; //to start at beginning of punct again(from prior loops, we dont want to increment where we left off)
            while(h <= punct.length())
            {
                if(temp[0] == punct[h]) //if beginning of temp is a punct
                {
                    temp.erase(0,1); //erase just one character(punct character)
                    h = 0; //start punct over
                }
                else
                {
                    h++; //otherwise continue to loop through punct length
                }
            }

            int f = 0;
            int g;
            while(f <= punct.length()) //this is where we start to remove the backend punct
            {
                g = temp.length() - 1; // variable to start at the end of temp string (-1 to account for starting at 0)
                if(temp[g] == punct[f])
                {
                    temp.erase(g, 1); //erase the character at g
                    f = 0;//start punct over again 
                }
                else
                {
                    f++;
                }
            }
            temp += ' '; //must make sure there spaces in front of your new word, but now there will be a space at the last word:(
        }
        sentence += temp; //builds the sentence off all the temp 
    }
      for(int b = 0; b < sentence.length(); b++) //the last word will have a space at the end, remove that 
        {
            if(b == sentence.length())
                sentence.erase(b-1,1); //b-1 because we start at 0, otherwise sentence length would be one too long 
        }
   return sentence; //return that mug 
}

//called in from other assignments, modified so it only takes in an array 
int SpellChecker::Split(string str, string array[])
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


//gets a sentences, removes punct, and splits into array
//loops through that array and comapirs values to the values in the three other arrays containing the valid, misspelled and corrected words 
string SpellChecker::repair(string sentence)
{
    string str = lowerNopunct(sentence); // lowerNoPunct returns a string lower w/ no punct
    string newStr = "";
    int size = Split(str, correctThis);

    for(int i = 0; i < size; i++) //iterate through correctThis
    {
        for(int j = 0; j <= count; j++) //count is amount in validWords file
        {                                   
            if(correctThis[i] == validWords[j]) //checks the whole validword file first
            {
                newStr += correctThis[i] + " "; //if its matches, add to the array
                break; //move on to next word
            }
            else if(j == count) //looped through the whole valid array, not equal, so do this 
            {
                for(int h = 0; h <= count2; h++) // = to 0 because the there is a word at count = 0;
                {
                    if(correctThis[i] == misspelledWords[h]) //compairs to to all values in mispelled 
                    {
                        newStr += correctedWords[h] + " "; //add to string 
                        break; //move on to next word
                    }

                    if(h == count2) //if it gets to the end of count2, its in none of the files, goofy word
                    {
                        string temp2 = ""; //simply adds the set start/end characters at the beginning and end of the word
                        temp2 += start_marker;
                        temp2 += correctThis[i];
                        temp2 += end_marker;
                        newStr += temp2 + " ";
                        break;
                    }
                }
            }
        }
    }
    return newStr;
}




