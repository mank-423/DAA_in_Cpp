#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void display(int ar[], int n){
    for (int i = 0; i < n; i++){
        cout << ar[i] << " ";
    }
    cout<< "\n";
}

//Bubble Sort
void bubble_sort(int ar[], int n){
    for (int i = 0 ; i < n - 1; i++){
        for (int j = 0 ; j < n - i - 1; j++){
            if (ar[j] > ar[j+1]){
                swap(ar[j], ar[j+1]);
            }
        } 
    }
}

//Selection Sort
void selection_sort(int ar[], int n){
    for (int i = 0 ; i < n; i++){
        int low_ind = i;
        for (int j = i+1 ; j < n; j++){
            if (ar[j] < ar[low_ind]){
                low_ind = j;
            }
        }
        swap(ar[i], ar[low_ind]);
    }
}

//Insertion sort
void insertion_sort(int ar[], int n)
{
    for (int i = 1; i < n; i++){
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
    }
}

int main()
{
    int size = 4;
    int ar[size];
    cout << "Enter the size of array:" << endl;
    cin >> size;

    //Input of random numbers
    for (int k = 0 ; k < size; k++){
        int input = rand();
        ar[k] = input;
    }

    //Process to check 
    display(ar,size);
    //bubble_sort(ar, size);
    //selection_sort(ar,size);
    insertion_sort(ar,size);
    display(ar, size);
    return 0;
}