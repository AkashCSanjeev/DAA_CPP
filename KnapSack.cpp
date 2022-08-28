#include <iostream>
using namespace std;
 
int main(){
    float profit[]={ 10, 5, 15, 7, 6, 18, 3 };
    float weight[] = {2, 3, 5, 7, 1, 4, 1};
    bool taken[7]={false};
    float soln[7]={0};
    float pw[7];

    int bagWeight = 15;

    for(int i = 0 ; i < 7;i++)
        pw[i] =profit[i]/weight[i];

    while(bagWeight>0){
        float minValue =0;
        int minIndex;
        for(int i = 0 ; i < 7;i++){
            if((minValue<pw[i]) && (taken[i] == false)){
                minValue = pw[i];
                minIndex = i;
            }
        }
        taken[minIndex] = true;

        if(bagWeight<=0)break;
        if(weight[minIndex] <= bagWeight ){
            bagWeight = bagWeight - weight[minIndex];
            soln[minIndex] = 1;
        }else{
            soln[minIndex] = bagWeight/weight[minIndex];
            bagWeight = 0;
            
        }

    }
    for(int i = 0 ; i <7;i++)
        cout<<soln[i]<<" ";

}