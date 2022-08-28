#include <iostream>
using namespace std;
 
int main(){
    int profit[] = { 35, 30, 25, 20, 15, 12, 5 };
    int deadlines[] = { 3, 4, 4, 2, 3, 1, 2 };
    int deadline = 4;
    int jobs=0;
    int maxProfit=0;
    int soln[4] = {-1,-1,-1,-1};

    for(int i = 0; i<  7;i++){

       for(int j =0  ; j <deadlines[i] ; j ++) {
        if(soln[deadlines[i]-1-j] == -1){
            soln[deadlines[i]-1-j] = i+1;
            maxProfit = maxProfit + profit[i];
            jobs++;
            break;
            
        }
       }
            if(jobs == 4)break;
    }

    for(int i = 0 ; i < 4;i++)
        cout<<soln[i]<<" ";
}