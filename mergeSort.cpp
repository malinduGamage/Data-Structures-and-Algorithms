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

void merge__sort(vector<int> &array, int start, int middle, int end)
{
   
    if (end <= start) return;
    merge__sort(array, start, (int)(middle+start)/2, middle);
    merge__sort(array, middle+1, (int)(end+middle)/2, end);

    vector<int> temp(end-start+1); 
    int i = start, j = middle+1 , k = 0;

    while (i<=middle and j<=end){
        if(array[i]<array[j]) {
            
            temp[k]=array[i];
            i++;
        }
        else {
            temp[k]=array[j];
            j++;
        }
        k++;
    }

    while(i<=middle){
        temp[k]=array[i];
        i++;
        k++;
    }

    while(j<=end){
        temp[k]=array[j];
        j++;
        k++;
    }

    i = start;
    for(int elem : temp){
        array[i] = elem;
        i++;
    }
}

int main()
{
    const int size = 50;
    vector<int> array(size); 

    for (int i = 0; i < size; ++i)
    {
        array[i] = size - i;
    }
    print_array(array);
    merge__sort(array, 0, (int)(size-1)/2,  size-1);
    print_array(array); 
    return 0;
}