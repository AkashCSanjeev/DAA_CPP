#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void depth(int vertex ,vector<int> graph[],bool visited[],vector<int> &dfs){

    visited[vertex] = true;
    dfs.push_back(vertex);

    for(int i : graph[vertex]){
        if(visited[i] == false){
            depth(i,graph,visited,dfs);
        }
    }

}

void DFS(vector<int> graph[],int numOfVertex,int startVertex){

    vector<int> dfs;
    bool visited[numOfVertex+1];
    for(int i = 0 ; i< numOfVertex+1;i++)
        visited[i] = false;

    depth(startVertex,graph,visited,dfs);

    // cout<<dfs.size();

    for (int i = 0; i < dfs.size(); i++) {
        // Printing the element at
        // index 'i' of vector
        cout << dfs[i] << " ";
    }

}


int main(){

    vector<int> graph[10];

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(6);
    graph[6].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[2].push_back(4);
    graph[4].push_back(2);

    graph[5].push_back(4);
    graph[4].push_back(5);

    graph[5].push_back(8);
    graph[8].push_back(5);

    graph[7].push_back(8);
    graph[8].push_back(7);

    graph[7].push_back(6);
    graph[6].push_back(7);

    graph[9].push_back(6);
    graph[6].push_back(9);

    DFS(graph,9,1);

}