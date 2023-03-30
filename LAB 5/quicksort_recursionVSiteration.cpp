#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void quickSortRecursive(int arr[] ,int start,int end){

    if(end<=start){return;}
    int pivot = arr[end];
    int i = start -1;
    int temp;

    for(int j = start;j<=end;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    i++;
    temp=arr[i];
    arr[i]=pivot;
    arr[end]=temp;

    quickSortRecursive(arr,start,i-1);
    quickSortRecursive(arr,i+1,end);
}

void quickSortIterative(int arr[] ,int start,int end){

    int stack[end - start + 1];
    int top = -1;
  
    
    stack[++top] = start;
    stack[++top] = end;
  
    
    while (top >= 0) {
       
        end = stack[top--];
        start = stack[top--];
  
        
    if(end<=start){return;}
    int pivot = arr[end];
    int i = start -1;
    int temp;

    for(int j = start;j<=end;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    i++;
    temp=arr[i];
    arr[i]=pivot;
    arr[end]=temp;
        

    if (i - 1 > start) {
        stack[++top] = start;
        stack[++top] = i - 1;
    }

    
    if (i + 1 < end) {
        stack[++top] = i + 1;
        stack[++top] = end;
    }
    }

}

int main(){

    int n;
    cout<<"Enter the size of array::";
    cin>>n;
    int arr1[n],arr2[n];

    for(int t=0;t<n;t++){
      arr1[t]=rand()%100;
      arr2[t]=arr1[t];
      }


    auto start = high_resolution_clock::now();
    quickSortRecursive(arr1,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by recursion : "<< duration.count() << " microseconds\n";

    start = high_resolution_clock::now();
    quickSortIterative(arr2,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by iteration : "<< duration.count() << " microseconds\n";

    


}