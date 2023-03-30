#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#include <iomanip>

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

void printArray(int arr[],int length){
    cout<<"["<<" ";
    for(int i=0;i<length;i++){
        
        if(i==length-1){
            cout<<arr[i]<<" ]";
        }
        else{cout<<arr[i]<<" , ";}
    }
}

int main(){
    int n;
    cout<<"Enter the size of array:: ";
    cin>>n;
    int arr[n];

    cout<<"sorted"<<"     median"<<endl;

    for(int t=0;t<n;t++){
        
      arr[t]=rand()%100;
      quickSortRecursive(arr,0,t);
      printArray(arr, t+1);
      std::cout << std::setprecision(1) << std::fixed;
      if((t+1)%2==1){
        float median=(float) arr[(t+1)/2];
        cout<<"      "<<median<<endl;
      }
      else{
        float median=(float) (arr[(t)/2]+arr[(t/2)+1])/2;
        cout<<"      "<<median<<endl;}
      }

}