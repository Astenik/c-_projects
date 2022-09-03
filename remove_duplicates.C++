#include <iostream>
#include <assert.h>
using namespace std;
void remove_duplicates(int*, int);
int main(){
    int* arr = new int[6];
    assert(arr);
    for(int i = 0; i < 6; ++i)
    {
        cin>>arr[i];
    }
    remove_duplicates(arr, 6);
    delete [] arr;
    return 0;
}
void remove_duplicates(int* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size - 1; ++j)
        {
            if(arr[j] == arr[j + 1])
            {  
                for(int k = j + 1; k < size; ++k)
                {
                    arr[k] = arr[k + 1];
                }
                arr[size - 1] = -0;
            }
        }
    }
    for(int i = 0; i < size; ++i)
    {
       cout<<arr[i]<<" ";
    }
    
}
