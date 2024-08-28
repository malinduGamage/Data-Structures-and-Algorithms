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

void bubble__sort(vector<int> &array)
{
    int size = array.size();
    bool changed ;
    int x=0,y=0;

    for (int i = 0; i < size-1; i++)
    {
        x++;
        changed = false;
        for (int j = 0; j < size-i-1 ; j++)
        {
            y++;
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                changed = true;
            }
        }
        if ( !changed ) break;
    }
    cout << "number of iterations : " << x << " x " << (int)y/x << endl;
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
    bubble__sort(array);
    print_array(array);
    return 0;
}