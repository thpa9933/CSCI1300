//Thomas Payne
//Chelsea Chandler
//Assignment 6

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;


//Split Function
int Split(string str, char sep, string array[], int max)
{
    int count = 0;
    string seg = "";

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == sep)
        {
            array[count] = seg;
            count++;
            seg = "";
        }
        else
        {
        seg = seg + str[i];
        }
    }
    if(seg != "")
        {
        array[count] = seg;
        count++;
        }
    return count;
}


// Part 1
//opens file
//gets line while not at the end of file
//store the line length of each line into a integer sum
//counts the number of lines
//returns average = sum / count
float avgCharsPerLine(string filename)
{
    ifstream file(filename.c_str());
    int count = 0;
    double sum = 0;
    string line;
    if(file.fail())
    {
        cout << "Error: opening" << filename << "failed." << endl;
        return 0;
    }
    else
    {
        while(! file.eof())
        {
            getline(file, line);
            double length = line.length();
            count++;
            sum = sum + length;
        }
    }
    file.close();
    double average = sum / count;
    return average;
}


// Part 2
//opens file
//gets line while not at the end of file
//execute while loop while there is a line to get, store line in str
//skip first line
//stringstream to parse through lines, while loop to parse ss at the comma
//convert string to integer, and store in proper index in array
//increase i, j and count so it continues to loop through and count lines
//return line count
int fillArray(string filename, float array1[][5])
{
    ifstream file;
    file.open(filename);

    string str;
    string word;
    int i = 0;
    int j = 0;
    int line = 1;
    int counter = 0;
    while(getline(file, str))
    {
        if(line > 1) // skips first line
        {
            stringstream ss(str); //parses through lines
            j = 0;

            while(getline(ss, word, ',')) //parses through ss and deliminates at comma
            {
                array1[i][j] = stof(word);
                j++;
            }
            i++;
            counter++;
        }
        else //add one to get to second line of file
        {
            line++;
        }
    }
    return counter;
}


// Part 3
//open file
//call fillarray to determine how many lines to loop through
//loops through rows and loop through columns
//if statements to loop through odd columns
//fills numbers array with values in odd columns
//loop through rows and loop through columns again
//if column is odd, create temp variable that sums up the index stored in numbers array
//find the means of each column by dividing by number of lines
//find total sum by adding the means of the columns and the total row sum
float arrayStats(string filename, float numbers[][5])
{
    ifstream dataFile(filename.c_str());
    if (dataFile.fail())
    {
        cout << "Error: Opening" << filename << "failed." << endl;
        return 0;
    }
    else
    {
        double col_sum1 = 0.0;
        double col_sum2 = 0.0;
        double row_sum = 0.0;
        double total_row_sum = 0.0;

        int lines = fillArray(filename, numbers); //determines how many rows to loop through

        for(int row = 0; row < lines; row++)
        {
            for(int col = 0; col < 5; col++) //sums the values in column one and column three
            {
                if(col == 1)
                {
                    double temp_col1; //create temp variable to build up the sum of the columns
                    temp_col1 = numbers[row][1];
                    col_sum1 = col_sum1 + temp_col1;
                }
                if(col == 3)
                {
                    double temp_col2;
                    temp_col2 = numbers[row][3];
                    col_sum2 = col_sum2 + temp_col2;
                }
            }
        }

        for(int row = 0; row < lines; row++) //loops through newly filled numbers array
        {
            for(int col = 0; col < 5; col++) //sums the values in the rows
            {
                if(row%2 != 0) //if the row is odd add to the sum of rows
                {
                    double temp_row_sum;
                    temp_row_sum = numbers[row][col];
                    row_sum = row_sum + temp_row_sum;
                }
            }
            double mean_row = row_sum/5; //find mean by dividing by total columns
            row_sum = 0;
            total_row_sum = total_row_sum + mean_row;
        }

        double mean_col1 = col_sum1 / lines; //finds the means in column one and column three
        double mean_col2 = col_sum2 / lines;
        double total_sum = mean_col1 + mean_col2 + total_row_sum; //add the total values
        return total_sum;
    }
    dataFile.close();
}

int search(string array[], int size, string target)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == target)
        {
            return i;
        }
    }
    return -1;
}
// Part 4
//open the file, and begin to parse out the data
//use stringstream and get line to parse the data, which each getline, stringstream ss gets smaller, eventually only accessing the last integer(rating)
//once the data is parsed, call the search function to see if the users is already in the users array
//if they are not, add them and update the ratings array
//if they are, just update the ratings array

void addBookRatings(string filename, string users[], int ratings[][50])
{
    ifstream dataFile;
    dataFile.open(filename);
    string line = "";
    int counter = 0;
    for(int i = 0; i < 50; i++) //clears all data in users and ratings array
    {
        users[i] = "";
    }
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            ratings[i][j] = 0;
        }
    }

    int i = 0;
    getline(dataFile,line);
    while(getline(dataFile,line)) //runs while there is a line go get
    {
        counter++;
        int number_rows = counter;
        stringstream ss(line);
        string name, orating, obook_id; //essentialy temporary variables to be later converted
        getline(ss,name,','); //parses and stores in name until it reaches comma
        getline(ss,obook_id, ','); //parses and stores in obook_id until it reaches comma
        getline(ss, orating); //parses the rest and stores in orating, no comma at the end
        int book_id = stoi(obook_id); //converts string to int
        int rating = stoi(orating);

        int index = search(users, 100, name); //called to determine if the name is already in the user array
        if(index == -1) //fill the array with name if it is not already in there
        {
            users[i] = name; // put found name into users array and update ratings array;
            ratings[i][book_id] = rating;
            i++;
        }
        else
        {
            ratings[index][book_id] = rating; // otherwise just update the ratings array
        }
    }
}




