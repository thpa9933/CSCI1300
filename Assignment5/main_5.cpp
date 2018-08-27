#include <iostream>
#include "Assignment5.cpp"
using namespace std;

int main()
{
//Problem 1
int array1[] = {9, 50, 75, 64, 20, 7, 97, 91, 61, 62, 36, 40, 78, 87};
//sumArray(array1, 14);

//Problem 2
int array2[] = {9, 50, 75, 64, 20, 7, 97, 91, 61, 62, 36, 40, 78, 87};
//search(array2[], 14, 75);

//Problem 3
int a[] = {9, 50, 75, 64, 20, 7, 97, 91, 61, 62, 36, 40, 78, 87};
int b[] = {87, 78, 40, 36, 62, 61, 91, 97, 7, 20, 64, 75, 50, 9};
//calculateDifference(a[], b[], 14);

//Problem 4
//float unsortedArray[] = {9, 50, 75, 64, 20, 7, 97, 91, 61, 62, 36, 40, 78, 87};
float unsortedArray[] = {1, 3, 2, 3};
sortArray(unsortedArray, 4);
for( int i = 0 ; i < 4; i++)
{
    cout << unsortedArray[i];
    cout << endl;
}



//Problem 5
float source[] = {9, 50, 75, 64, 20, 7, 97, 91, 61, 62, 36, 40, 78, 87};
//float dest[];
//copyArray(source[], 14, dest[]);

//Problem 6
int rating[] = {0, 5, 3, 0, -5, -3, 3};
//string text[];
//convert(rating[], text[], 7);

//Problem 7
//float array[] = {9, 50, 75, 64, 20, 7, 97, 91, 61, 62, 36, 40, 78, 87};
//float array[] = {3, 1, 2, 3};
//cout << findMedian(array, 4) << endl;
return 0;
}
