/*  Project Name : Merge and Insertion Sort
    Date: 4/5/2020
    Programmer: Jacob Mast
    Description: two functions are included, one for merge sort and one for insertion sort
*/


#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

void merge_sort(int arr[], int m, int n);

void merge(int arr[], int p, int q, int r);

int main(){

    ifstream infile("data.txt");

    // steps for merge sort
    // create variable for array length
    int len;

    // In HW prompt - the first value in the input stream is the number of values to be sorted
    infile>>len;

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

    /* run merge sort function, declared above and written below
       program takes an array of unsorted positive integers and sorts into increasing order
       using the merge sort algorithm
    */    
    merge_sort( arr1, 1 , len );

    // open output file in write mode
    ofstream outfile1("merge.out");

    // write content from the sorted array into the output file
    for( i = 0 ; i <= len ; i++ ){
        outfile1<<arr1[i]<<" ";
    }   

    return 0;
}


// merge_sort function sorts an array using the merge sort alorithm

void merge_sort(int arr[],int m, int n){

    // if there is more than one value in the array
    if(m < n){

        // get mid index
        int mid = (m + n) / 2;

        // recursive call to sort the left subarray
        merge_sort(arr, m, mid);

        // recursive call to sort the right subarray
        merge_sort(arr, mid + 1, n);

        // merge the two subarrays, function is written below
        merge(arr, m, mid, n);
    }
}

// function merges two arrays, placing values in merged array in increasing order

void merge(int arr[], int p, int q, int r) {

    // length of left subarray
    int len = q - p + 1;

    // length of right subarray
    int len2 = r - q;

    // declare counter variables
    int i, j, k;

    // create two arrays left and right
    int *left = new int[len + 1];
    int *right = new int[len2 + 1];

    // fill left with contents of left subarray of arr
    for(i = 1; i < len; i++){
        left[i] = arr[p + i - 1];
    }

    // fill right w contents of right subarray of arr
    for(i = 1; i < len2; i++){
        right[i] = arr[q + i];
    }

    // set last element of each array to the max int value or infinity, which is our sentinel value
    left[len] = std::numeric_limits<int>::max();
    right[len2] = std::numeric_limits<int>::max();

    i=1;
    j=1;

    //repeat the loop below for the length of the array (r - p + 1)

    for(k = p ; k <= r; k++){

        // if the current left is smaller than current right
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }

        // else if the current left is larger than current right
        else{
            arr[k] = right[j];
            j++;
        }
    }
}