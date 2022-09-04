#include <iostream>
#include <assert.h>
using namespace std;
int max_profit(int*, int);
int max(int&, int&);
int main(){
    int size;
    cin>>size;
    int* arr = new int [size];
    assert(arr);
    for(int i = 0; i < size; ++i)
    {
        cin>>arr[i];
    }
    cout<<max_profit(arr, size)<<endl;
    delete [] arr;
    return 0;
}
int max(int& x, int& y)
{
    return x > y ? x : y;
}
int max_profit(int* arr, int size)
{
    int _max = 0;
    for(int i = 0; i < size; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            _max = max(_max, (arr[j] - arr[i]));
        }
    }
    return _max;
}
