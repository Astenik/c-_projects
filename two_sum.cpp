#include <iostream>
#include <assert.h>

void two_sum(int*, int, int);

/*given an array of integers nums and an integer
target, this function prints indices of two number such that they add up to target.*/

int main()
{
    int size, target;
    std::cin >> size; 
    std::cin >> target;
    
    int* arr = new int [size];
    assert(arr);
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    two_sum(arr, size, target);
    delete [] arr;
    
    return 0;
}
void two_sum(int* nums, int s, int target)
{
    for(int i = 0; i < s - 1; ++i)
    {
        for(int j = i + 1; j < s; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                std::cout << "[ "<< i << ", "<< j << "]" << std::endl;
                break;
            }
        if(j != s)
            break;
        }
    }
}
