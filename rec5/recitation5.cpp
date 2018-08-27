#include <iostream>
using namespace std;

/*
Example 1
-----------
rows = 6
          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
* * * * * * * * * * *

Example 2
-----------
rows = 4
      *
    * * *
  * * * * *
* * * * * * *

Notice how many asterisks are on each line:
1 first row, 3 second row, 5 third row, ...
*/

int main ()
{
    int n_rows;
    cout << "Enter number of rows: ";
    cin >> n_rows;


    int row = 0;
    while (row < n_rows)
    {
        // start from bottom to find in space
        // run if the space is larger than 2xrow
        // decrement the spaces to cover all spaces
        int space = 2*n_rows - 3;
        while (space >= 2*row)
        {
            cout << " ";
            space --;
        }

        // output the asterisks
        int asterisk = 1;
        while (asterisk <= 2*row + 1)
	    {
            cout << "* ";
            asterisk++;
	    }

        cout << endl;
        ++row;
    }

  return 0;
}
