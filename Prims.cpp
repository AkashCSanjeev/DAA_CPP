#include <iostream>
using namespace std;


void prims(int graph[][9],int vertex){

    int key[vertex];
    int mst[vertex];
    bool visited[vertex];

    for(int i = 0 ; i  < vertex;i++){
        key[i] = 1000;mst[i] = -1;visited[i] =false;
    }

    key[0]=0;

    for(int i = 0; i < vertex;i++){
        int min = 1000;
        int minIndex = -1;
        for(int j = 0 ; j < vertex; j++){
            if((key[j]<min)&&(visited[j]==false)){
                min = key[j];
                minIndex = j;
            }
        }

        visited[minIndex] = true;

        for(int j = 0 ; j <  vertex ;j++){

            if((graph[minIndex][j]!=0)&&(visited[j] == false)&&(graph[minIndex][j]<key[j])){
                mst[j] = minIndex;
                key[j]=graph[minIndex][j];
            }

        }


    }

    for(int i = 0 ; i < vertex;i++)
        cout<<mst[i]<<" - "<<(i+1)<<endl;

}
 
int main(){
        int graph[9][9] ={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

        prims(graph, 9);
}