#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int adj_matrix[20][20];
int vis[5] = {0,0,0,0,0};
int size;

void make_graph(){
    //Graph making
    // cout << "Enter the nodes of the graph:";
    // cin >> size;

    for (int i = 0 ; i < 5; i++){
        int conn;
        cout<<"Enter the no. of connections of node "<<i << ":";
        cin >> conn;

        cout << "Enter the connection:"<<endl;
        for (int j = 0; j < conn; j++)
        {
            int node_conn = 0;
            cin >> node_conn;
            adj_matrix[i][node_conn] = 1;
        }
        
    }

}


void dfs(int i){
    vis[i] = 1;
    cout << i << " ";

    for (int j = 0; j < 5; j++)
    {
        if (adj_matrix[i][j] ==1 && vis[j]!=1){
            dfs(j);
        }
    }
}


int main()
{
    make_graph();
    dfs(0);
    return 0;
}