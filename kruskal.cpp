#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int source;
        int dest;
        int weight;
};

//Increasing order of sort using weights 
bool compare(Edge  e1, Edge e2){
    return e1.weight < e2.weight;
}

//Find parent fucntion
int findParent(int v, int *parent){
    if (parent[v] == v){
        return v;
    }
    return findParent(parent[v], parent);
}


//Kruskal function
void kruskals(Edge *input, int E, int n){
    
    //Sort input array in ascneding order
    sort(input, input + E, compare); // two iterarors

    Edge *output = new Edge[n - 1];

    //Parent array and value as its index
    int *parent = new int[n];
    for (int i = 0 ; i < n; i++){
        parent[i] = i;
    }
   
    int count = 0; //helps us for n-1 edges conditions
    int i = 0;

    while (count != n - 1){
        Edge currentedge = input[i]; //Current edge in graph

        //Check if we can add the current edge in MST or not
        int sourceParent = findParent(currentedge.source, parent);
        int destParent = findParent(currentedge.dest, parent);

        //Condition to check 
        if (sourceParent != destParent){
            output[count] = currentedge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++; //Counter for size time loop
    }


    
    for (int i = 0; i < n-1; i++){

        if (output[i].source < output[i].dest){
            cout << output[i].source << " " << output[i].dest << " "
            << output[i].weight << endl;
        }

        else{
            cout << output[i].dest << " " << output[i].source << " "
            << output[i].weight << endl;
        }
    }
}

int main()
{

    //input n-node, E- edges
    int n, E;
    cin >> n >> E; 
    Edge *input = new Edge[E];


    for (int i = 0; i < E; i++){
        int s,d,w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    cout << "The MST:"<<endl;
    kruskals(input, E, n);

    return 0;
}   