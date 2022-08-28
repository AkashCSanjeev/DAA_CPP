#include <iostream>
using namespace std;

int partition(int arr[],int low,int high){

    int i =low+1;
    int j = high;
    int pivot = low;
    int length = sizeof(arr)+1;

    while(i<=j){
        while(arr[i]<=arr[pivot]){
            if(i>length-1)
                break;
            i++;
        }

        while(arr[j]>arr[pivot]){
            j--;
        }

    if(j>=i){
int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
        
    }

    int temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;


    return j;
}

void quickSort(int arr[],int low,int high){

    

    if(low<high){

        int part = partition(arr,low,high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);

    }

}
 
int main(){
    int arr[] = {5,4,3,2,1};
    quickSort(arr,0,4);
    cout<<"Array"<<endl;
    for(int i = 0 ; i <= 4;i++)
        cout<<arr[i]<<" ";
}