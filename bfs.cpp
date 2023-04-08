#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int adj_matrix[20][20];
int size;

void make_graph(){

    //Graph making
    cout << "Enter the nodes of the graph:";
    cin >> size;

    for (int i = 0 ; i < size; i++){
        int conn;
        cout<<"Enter the no. of connections of node "<<i << ":";
        cin >> conn;

        
        for (int j = 0; j < conn; j++)
        {
            int node_conn = 0;
            cout << "Enter the connection:"<<endl;
            cin >> node_conn;
            adj_matrix[i][node_conn] = 1;
        }
        
    }

    //The adjancent matrix  
    for (int i = 0 ;  i < size; i++){
        for ( int j = 0; j < size; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void bfs(){
    //BFS
    int x; //Starting node of BFS
    int vis[size] = {0};
    queue<int> q;
    
    
    q.push(x);
    vis[x] = 1;

    for (int k = 0 ; k < size; k++){
        if (adj_matrix[x][k] == 1){
            q.push(k);
            vis[k] = 1;
        }
    }

    //Now we will go on until the queue is not empty
    while (q.empty() != true)
    {
        //Pop visited node
        cout << q.front() << " ";
        q.pop();

        x = q.front();

        for (int k = 0 ; k < size; k++){
            if (adj_matrix[x][k] == 1 && vis[k] != 1){
                q.push(k);
                vis[k] = 1;
            }
        }

    }
}



int main()
{ 
    make_graph();
    bfs();
    return 0;
}