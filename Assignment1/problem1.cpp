#include <iostream>
using namespace std;

// Author: <Thomas Payne>
// Recitation: <#102 Chelsea Chandler>
//
// Assignment 3
// Problem <1>


void menu();
void story1();
void story2();
void story3();


/*
Receives an input, when the input is selected, the function enters a while loop.
The while loop is only executed if x does not equal q, this allows return "good bye".
When in the while loop, the function determines what further function should be executed.
After a function is called, the menu returns the first question again, allowing for recursive play.
*/
void menu(void)
{
    string x;
    cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: ";
    cin >> x;
    while(x != "q")
    {
        if(x == "1")
        {
            story1();
        }
        else if(x == "2")
        {
            story2();
        }
        else if(x == "3")
        {
            story3();
        }
        else
        {
            cout << "Valid choice not selected";
        }
        cout << "Which story would you like to play? Enter the number of story (1, 2, or 3) or type q to quit: ";
        cin >> x;
    }
     if (x == "q")
        {
            cout << "good bye";
        }
}

/*
Receives multiple inputs.
Returns the inputs into one 'madlib' string.
*/
void story1(void)
{
    string a, b, c, d;

    cout << "Enter a plural noun: ";
    cin >> a;
    cout << endl;

    cout << "Enter an occupation: ";
    cin >> b;
    cout << endl;

    cout << "Enter an animal name: ";
    cin >> c;
    cout << endl;

    cout << "Enter a place: ";
    cin >> d;
    cout << endl;

    cout << "In the book War of the " << a << ", the main character is an anonymous " << b << " who records the arrival of the " << c << "s in " << d << "." << endl;

}

/*
Receives multiple inputs.
Returns the inputs into one 'madlib' string.
*/
void story2(void)
{
    string a, b;

    cout << "Enter a name: ";
    cin >> a;
    cout << endl;

    cout << "Enter a state/country: ";
    cin >> b;
    cout << endl;

    cout << a << ", I've got a feeling we're not in " << b << " anymore." << endl;

}

/*
Receives multiple inputs.
Returns the inputs into one 'madlib' string.
*/
void story3(void)
{
    string a, b, c;

    cout << "Enter a first name: ";
    cin >> a;
    cout << endl;

    cout << "Enter a relative: ";
    cin >> b;
    cout << endl;

    cout << "Enter a verb: ";
    cin >> c;
    cout << endl;


    cout << "Hello. My name is " << a << ". You killed my " << b << ". Prepare to " << c << "." << endl;
}

int main()
{
    menu();
}
