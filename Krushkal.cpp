#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int source;
    int destination;
    int weight;

    Node(int sourceC,int destinationC,int weightC){

        source =sourceC;
        destination=destinationC;
        weight = weightC;

    }
};

bool comp(Node n1,Node n2){
    return n1.weight<n2.weight;
}

int findPar(int parent[],int vertex){
    if(vertex == parent[vertex]){
        return vertex;
    }else{

        return parent[vertex] = findPar(parent,parent[vertex]);
    }
}

void unionn(int parent[],int rank[],int vertex1,int vertex2){
    vertex1 = findPar(parent,vertex1);
    vertex2 = findPar(parent,vertex2);

    if(rank[vertex1]>rank[vertex2]){
        parent[vertex2] = vertex1;
    }else if(rank[vertex1]<rank[vertex2]){
        parent[vertex1] = vertex2;
    }else{
        parent[vertex2] = vertex1;
        rank[vertex1]++;
    }
}
 
int main(){
    int N=5,m=6;
	vector<Node> edges; 
	vector<Node> mst; 
	edges.push_back(Node(0,1,2));
	edges.push_back(Node(0,3,6));
	edges.push_back(Node(1,0,2));
	edges.push_back(Node(1,2,3));
	edges.push_back(Node(1,3,8));
	edges.push_back(Node(1,4,5));
	edges.push_back(Node(2,1,3));
	edges.push_back(Node(2,4,7));
	edges.push_back(Node(3,0,6));
	edges.push_back(Node(3,1,8));
	edges.push_back(Node(4,1,5));
	edges.push_back(Node(4,2,7));
	sort(edges.begin(), edges.end(), comp);    

    int parent[N] ={0,1,2,3,4};
    int rank[N]{0,0,0,0,0};

    int cost = 0;

    for(auto it:edges){

        if(findPar(parent,it.source) != findPar(parent,it.destination)){
            cost = cost + it.weight;
            mst.push_back(it);
            unionn(parent,rank,it.source,it.destination);

        }

    }

    cout<<cost<<endl;

    for(auto it:mst)
        cout<<it.source<<" - "<<it.destination<<endl;


}