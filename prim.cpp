#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int adj_matrix[10][10] = {
        {0,2,3,0,0},
        {2,0,1,4,6},
        {3,1,0,5,7},
        {0,4,5,0,8},
        {0,6,7,8,0}
};

int size;


//Prim
void prim()
{
    int size = 5;
    int parent[size];
    int key[size];
    int mst[size];
    int count = 0;

    int adj_matrix[size][size] = 
    {
        {0,2,3,0,0},
        {2,0,1,4,6},
        {3,1,0,5,7},
        {0,4,5,0,8},
        {0,6,7,8,0}
    };


    for (int i = 0 ; i < size; i++){
        mst[i] = 0;
        key[i] = INT_MAX;
    }

    //Starting node is 0
    int x = 0;
    int cost = 0;
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0 ; i < size ; i++){
        
        cout << x << " ";

        //Insert values in key and parent to the nodes
        for (int j = 1 ; j < size; j++){
            if (adj_matrix[i][j]!= 0 && adj_matrix[i][j] < key[j]){
                key[j] = adj_matrix[i][j];
                parent[j] = x;
            }
        }

        //Now choosing the minimum node to start again
        int low = 100; int low_node;
        for (int j = 1; j < size; j++){
            if (low > key[j] && mst[j] != 1){
                low = key[j];
                low_node = j;
            }
        }

        if (low == 100){
            low = 0;
        }

        cost += low;
        x = low_node;
        mst[low_node] = 1;
       
    }

    cout << endl;
    cout << "Cost of MST:" << cost;   
}


int main()
{
    //make_graph();
    prim(); 
    return 0;
}