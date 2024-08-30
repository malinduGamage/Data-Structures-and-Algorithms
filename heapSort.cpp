#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int> &array)
{
    for (int elem : array)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void heapify(vector<int> &array,int i,int bound){
    if(2*i+2 < bound){
        if(array[2*i+1]== max(array[2*i+1],array[2*i+2])){
            if (array[i]<array[2*i+1]) {
                swap(array[i],array[2*i+1]);
                heapify(array,2*i+1,bound);
            }
        }
        else{
            if (array[i]<array[2*i+2]) {
                swap(array[i],array[2*i+2]);
                heapify(array,2*i+2,bound);
            }
        }
    }
    else if (2*i+1 < bound){
        if (array[i]<array[2*i+1]) {
            swap(array[i],array[2*i+1]);
            heapify(array,2*i+1,bound);
        }
    }
}

void heapSort(vector<int> &array){

    int size = array.size();
    //build max heap
    for(int i = size - 1; i >= 0; i--){
        heapify(array,i,size);
    }
    //swap and build heap
    for(int i = size - 1; i >= 0; i--){
        swap(array[0],array[i]);
        heapify(array,0,i);
    }
}

int main(){
    const int size = 50;
    vector<int> array(size); 

    for (int i = 0; i < size; ++i)
    {
        array[i] = i;
    }

    heapSort(array);

    print_array(array);
    return 0;
}