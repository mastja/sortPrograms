/*  Project Name : Merge and Insertion Sort
    Date: 4/5/2020
    Programmer: Jacob Mast
    Description: two functions are included, one for merge sort and one for insertion sort
*/


#include<iostream>
#include<fstream>
using namespace std;

void insertion_sort(int arr[], int n);

int main(){

    ifstream infile("data.txt");

    //steps for insertion sort
    // create variable for array length
    int len;

    // In HW prompt - the first value in the input stream is the number of values to be sorted
    in>>len;

    // create array of size len, add 1 spot to hold integer list length value
    int arr1[len + 1];

    // store the array length as the first value of the sorted array
    arr1[0] = len;

    // counter variable
    int i;

    // read content from file, and write to the array
    for( i = 1 ; i <= len ; i++ ){
        infile>>arr1[i];
    }

    /* run insertion sort function, declared above and written below
       program takes an array of unsorted positive integers and sorts into increasing order
    */
    insertion_sort(arr1 , len + 1);
    cout<<endl;

    // open output file in write mode
    ofstream outfile1("insert.out");

    // write content from the sorted array into the output file
    for( i = 0 ; i <=len ; i++ ){
        outfile1<<arr1[i]<<" ";       
    }

    return 0;

}


/* insertion sort function
    program takes an array of unsorted positive integers and sorts into increasing order
    first value in the passed array is the length of the list of integers to be sorted
*/

void insertion_sort(int arr[], int n){

    // declare local variables
    int i, j, key;

    // counter from 1 to integer list length
    for (i = 1; i < n; i++){
        
        // place current in key
        key = arr[i]; 

        // index spot of previous value
        j = i - 1;

        // compare the key to the value indexed at previous spot, if key is less than, continue while loop
        // while loop exits when key is greater than or equal to value indexed at previous spot
        while (j >= 0 && arr[j] > key){

            // since the key is less than the value at index j, j is moved to index spot of j+1
            arr[j+1] = arr[j];

            // j is decremented so that we can compare the key to the previous spot
            j--;

            //function moves back up to test the conditionals in the while statement line
        }

        // while loop has exited, key is greater than or equal to value at index j
        // key is placed at index j + 1.
        arr[j + 1] = key;

    }

}