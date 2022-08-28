#include <iostream>
using namespace std;

void merge(int arr[],int high,int mid,int low){

    int l[mid-low+1];
    int r[high - mid];
    // int i=0,j=0,k=low;

    for (int i = 0; i < mid-low+1; i++) {
            l[i] = arr[low + i];
        }
        for (int i = 0; i < high - mid; i++) {
            r[i] = arr[mid + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = low;

        while ((i < mid-low+1) && (j < high - mid)) {

            if (l[i] <= r[j]) {
                arr[k] = l[i];
                i++;
                k++;
            } else {
                arr[k] = r[j];
                j++;
                k++;
            }

        }

        while (i < mid-low+1) {
            arr[k] = l[i];
            i++;
            k++;
        }
        while (j < high - mid) {
            arr[k] = r[j];
            j++;
            k++;
        }
}

void mergeSort(int arr[],int low,int high){
    

    if(low<high){
        
        int mid = (low + high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,high,mid,low);
        // cout<<"k";
    }
}
 
int main(){

    int arr[] = {5,4,3,2,1};
    mergeSort(arr,0,4);
    cout<<"Array"<<endl;
    for(int i = 0 ; i <= 4;i++)
        cout<<arr[i]<<" ";

}