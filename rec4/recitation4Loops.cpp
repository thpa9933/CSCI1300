#include <iostream>
using namespace std;

int addNumbers(int firstnum, int secondnum)
{
    int a = firstnum;
    int b = secondnum;
    int x;
    x = a + b;
    return x;
}
void swapTwoNumbers()
{
    int a = 5, b = 10, temp;
    temp = a;
    a = b;
    b = temp;

    cout << "Before swapping." << endl;
    cout << "a = " << a << ", b = " << b << endl;

    cout << "\nAfter swapping." << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

void loopsOfNumbers(int n)
{

    while (n >= 0)
    {
        cout << n * n << endl;
        n = n - 1;
    }
}

int main(){
    //~~~~~~~~~~~ Loops and Numbers ~~~~~~~~~~~~~~~~~~~~~
    cout << "Enter a number: " << endl;
    int numbers;
    cin >> numbers;
    cout << endl;
    loopsOfNumbers(numbers);

    //~~~~~~~~~~~~ Swapping Numbers ~~~~~~~~~~~~~~~~~~~~~
    swapTwoNumbers();

    //~~~~~~~~~~~~ Adding Numbers ~~~~~~~~~~~~~~~~~~~~~~~
    cout<< "Let’s perform some addition." << endl;
    cout << "Please enter the First number:" <<endl;
    int firstnum;
    cin >> firstnum;
    cout << "Please enter the Second number:" << endl;
    int secondnum;
    cin >> secondnum;
    int res = addNumbers(firstnum,secondnum);
    cout  << "The Sum of Two numbers is " << res << endl;
    return 0;
}


