#include <iostream>
using namespace std;

void toh(int numOfDisk, string start,string aux,string end){

    if(numOfDisk == 1) 
        cout<<"move disk from "<<start<<" to "<<end<<endl;
    else{
        toh(numOfDisk-1,start,end,aux);
        cout<<"move disk from "<<start<<" to "<<end<<endl;
        toh(numOfDisk-1,aux,start,end);
    }

}

 
int main(){

    toh(3,"A","B","C");

}