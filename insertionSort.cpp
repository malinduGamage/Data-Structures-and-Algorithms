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

void insertion__sort(vector<int> &array)
{
    for (int i = 1; i < array.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                swap(array[j], array[j - 1]);
            }
            else
                break;
        }
        print_array(array);
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
    insertion__sort(array);
    return 0;
}