
#include <iostream>
#include "Assignment4.cpp"
using namespace std;


int main()
{
    //part 1
    string sequence1;
    string sequence2;

    cout << "Input two DNA sequences:" << endl;
    cin >> sequence1;
    cin >> sequence2;

    float result = similarityScore(sequence1, sequence2);
    cout << result << endl;

    //part 2
    string genome;
    cout << "Enter a genome: " << endl;
    cin >> genome;

    float min_score;
    cout << "Enter a min score: " << endl;
    cin >> min_score;

    //part 3
    string seq;
    cout << "Enter a sequence: " << endl;
    cin >> seq;

    //part 4
    string genome1;
    cout << "Enter genome one: " << endl;
    cin >> genome1;

    string genome2;
    cout << "Enter genome two: " << endl;
    cin >> genome2;

    string genome3;
    cout << "enter genome three: " << endl;

}

