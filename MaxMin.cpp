#include <iostream>
using namespace std;

void findMaxMin(int arr[], int low, int high, int maxMin[]) {

        if (low == high) {
            if (maxMin[0] < arr[low]) { // comparison 1
                maxMin[0] = arr[low];
            }

            if (maxMin[1] > arr[low]) { // comparison 2
                maxMin[1] = arr[low];
            }

            return;

        }
        if (low == high - 1) {
            if (arr[low] < arr[high]) // comparison 1
            {
                if (maxMin[1] > arr[low]) { // comparison 2
                    maxMin[1] = arr[low];
                }

                if (maxMin[0] < arr[high]) { // comparison 3
                    maxMin[0] = arr[high];
                }
            } else {
                if (maxMin[1] > arr[high]) { // comparison 2
                    maxMin[1] = arr[high];
                }

                if (maxMin[0] < arr[low]) { // comparison 3
                    maxMin[0] = arr[low];
                }
            }
            return;
        }

        int mid = (low + high) / 2;

        findMaxMin(arr, low, mid, maxMin);
        findMaxMin(arr, mid + 1, high, maxMin);
    }
 
int main(){
    int arr[] = {5,4,3,2,1};
    int maxMin[] = {-1000,100 };
    findMaxMin(arr, 0, 4, maxMin);

    cout<<maxMin[0]<<" "<<maxMin[1];

}