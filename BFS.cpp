#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> graph[],int numOfVertex,int startIndex){

    vector<int> bfs;
    bool visited[numOfVertex+1];
    for(int i =0; i < numOfVertex+1;i++){
        visited[i] = false;
    }
    queue<int> q;

    q.push(startIndex);
    visited[startIndex] = true;

    while(!q.empty()){

        int index = q.front();
        q.pop();
        bfs.push_back(index);

        for(int i: graph[index]){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
            }
        }

    }

    for (int i = 0; i < bfs.size(); i++) {
        // Printing the element at
        // index 'i' of vector
        cout << bfs[i] << " ";
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

    BFS(graph,9,1);

}