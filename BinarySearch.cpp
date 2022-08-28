#include <iostream>
using namespace std;

void binarySearch(int arr[],int key,int start,int end){
    int mid = (start+end)/2;

    if(key == arr[mid]){
        cout<<"Key found"<<endl;
    }else if(key>arr[mid]){
        binarySearch(arr,key,mid+1,end);
    }else{
        binarySearch(arr,key,start,mid-1);
    }

}
 
int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    binarySearch(arr,3,0,9);

}