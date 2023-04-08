#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void display(int ar[], int n){
    for (int i = 0 ; i < n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
}

void displayheap(int ar[], int n){
    for (int i = 1 ; i < n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
}

//QUICK SORT
int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l + 1;
    int j = h;

    do {
        while (A[i] <= pivot){
            i++;
        }
        while (A[j] > pivot){
            j--;
        }

        if ( i < j){
            swap(A[i], A[j]);
        }
    }while ( i < j);

    swap(A[l], A[j]);
    return j;
}

void quickSort(int A[], int l , int h){
    int partInd;
    if (l < h){
        partInd = partition(A, l, h);
        quickSort(A, l ,partInd - 1);
        quickSort(A, partInd + 1 ,h);
    }
}

//MERGE SORT
void merge(int A[], int l, int mid, int h){
    int i, j, k;
    int B[h+1];
    i = k = l;
    j = mid + 1;

    while (i <= mid && j <= h){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;k++;
        }
        
        if (A[i] > A[j]){
            B[k] = A[j];
            k++;j++;
        }

        while (i <= mid){
            B[k] = A[i];
            k++;i++;
        }
        while (j <= h){
            B[j] = A[j];
            k++;j++;
        }
    }

    for (int i = l; i <= h; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int l ,int h){
    int mid;
    if (l < h){
        mid = (l + h)/ 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

//HEAP SORT
void heapify(int A[], int n, int i){
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && A[l] > A[largest]){
        largest = l;
    }

    if (r <= n && A[r] > A[largest]){
        largest = r;
    }

    if (largest != i){
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void buildheap(int A[], int n){
    for (int i = n/2; i > 0; i--){
        heapify(A, n, i);
    }
}

void heapSort(int A[], int n){
    buildheap(A, n);
    for (int i = n; i > 1; i--){
        swap(A[1], A[i]);
        heapify(A, i-1, 1);
    }
}

int main()
{
    int ar[5] = {10,2,5,1,6};
    int ar1[5 + 1] = {00,2,5,10,1,6};
    displayheap(ar1, 6);
    heapSort(ar1, 6);
    displayheap(ar1, 6);

    // display(ar, 5);
    //quickSort(ar, 0, 5 - 1);
    //mergeSort(ar, 0, 5 - 1);
    // display(ar, 5);
    
    return 0;
}