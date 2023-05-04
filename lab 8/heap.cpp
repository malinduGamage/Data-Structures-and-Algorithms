#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int indexOfLeft = root*2+1;
  int indexOfRight = root*2+2;
  int indexOfMax = root;

  if(indexOfLeft<n && arr[indexOfLeft]>arr[root]){
   indexOfMax = indexOfLeft;
  }

  if(indexOfRight<n && arr[indexOfRight]>arr[indexOfMax]){
   indexOfMax = indexOfRight;
  }
  if(indexOfMax != root){
   swap(arr[indexOfMax],arr[root]);
   heapify(arr,n,indexOfMax);
  }
   
}


  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = (n-1)/2 ; i>=0 ; i--){
      heapify(arr,n,i);
   }
   
   // extracting elements from heap one by one
   for(int j = n; j>1 ; j--){
      swap(arr[0],arr[n-1]);
      n -= 1;
      heapify(arr,n,0);
   }
   
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int num;
   int i=0; //array index
   int heap_arr[100]; 
   cout<<"Input elements with seperated spaces\n";
   // get the inputs
   while (true) {
    cin >> num;
    heap_arr[i]=num;
    i+=1;
    
    if (cin.peek() == '\n') {
        break;
    }
    
}
   
   int n = i; //array size
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array "<<endl;
   displayArray(heap_arr, n);
}