#include <iostream>
#include <math.h>
using namespace std;

// Problem 1
// increment through the array
// add the current index to the previous index
// return the sum after the array has been incremented through once
float sumArray(float array[], int size)
{
    float sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}


// Problem 2
// increment through the array
// determine if the current index is equal to the target value
// if so return index, otherwise return -1
int search(int array[], int size, int target)
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


// Problem 3
// increment through both arrays with one index 'i'
// create a variable 'sum' and use the power function to find the square between them
// create a variable 'result' and add the current sum to the previous sum
// return the 'result'
float calculateDifference(int a[], int b[], int size)
{
    float result = 0;
    for(int i = 0; i < size; i++)
    {
        float sum = pow((a[i] - b[i]), 2);
        result += sum;
    }
    return result;
}


// Problem 4
// create a bool variable that is initially false, so the while loop executes
// bool = true
// increment through array, if the fist index is greater than the last index, switch them
// loop until everything is sorted
void sortArray(float unsortedArray[], int size)
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i = 0; i < size-1; i++)
            if(unsortedArray[i] > unsortedArray[i + 1])
            {
                float temp = unsortedArray[i];
                unsortedArray[i] = unsortedArray[i + 1];
                unsortedArray[i + 1] = temp;
                sorted = false;
            }

    }
}

// Problem 5
// increment through both arrays with int i
// replace value of i in first array with value of i in second array
void copyArray(float source[], int size, float dest[])
{
    for(int i = 0; i < size; i++)
    {
        dest[i] = source[i]; //not source = dest because then you would have two empty arrays, you want two full arrays
    }
}

//Problem 6
// increment through both arrays with int i
// indicate what values in the string array equal that in the int array.
void convert(int rating[], string text[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(rating[i] == 0)
        {
            text[i] = "Not-read";
        }
        else if(rating[i] == -5)
        {
            text[i] = "Terrible";
        }
        else if(rating[i] == -3)
        {
            text[i] = "Disliked";
        }
        else if(rating[i] == 1)
        {
            text[i] = "Average";
        }
        else if(rating[i] == 3)
        {
            text[i] = "Good";
        }
        else if(rating[i] == 5)
        {
            text[i] = "Excellent";
        }
        else
        {
            text[i] = "INVALID";
        }
    }
}

// Problem 7
// make variable for new array
// sort and copy the given into a new array
// make variable for median
// if size is odd divide by array by two and return the value
// if size is even divide the array by two
// take the last index and last index - 1
// add and divide by two, return median
float findMedian(float arr[], int size)
{
    float median;
    float array[size];
    copyArray(arr, size, array);

    sortArray(array, size);

    if(size%2 != 0)
    {
        median = array[size/2];
        return median;
    }
    else
    {
        median = (array[size/2] + array[(size/2) - 1])/2.0;
        return median;
    }
}






















