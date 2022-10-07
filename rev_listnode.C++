#include <iostream>
#include <assert.h>

class ListNode
{
   public:
    int value;
    ListNode* next;
    ListNode():value(0), next(nullptr){}
    ListNode(int val):value(val), next(nullptr){}
    ListNode(int val, ListNode* n):value(val), next(n){}
    ~ListNode(){}
};

void rev_listnode(ListNode* arr, int size)
{
    ListNode* c_arr = new ListNode [size];
    assert(c_arr);
    int j = size - 1;
    for(int i = 0; i < size; ++i)
    {
        c_arr[i].value = arr[j].value;
        --j;
    }
    for(int k = 0; k < size - 1; ++k)
    {
        c_arr[k].next = &c_arr[k + 1];
    }
    for(int k = 0; k < size; ++k)
    {
        std::cout << c_arr[k].value << " ";
    } 
   
    delete [] c_arr;
}

int main()
{
    ListNode* arr = new ListNode [5];
    assert(arr);
    for(int i = 0; i < 5; ++i)
    {
        std::cin >> arr[i].value;
    }
    for(int j = 0; j < 4; ++j)
    {
        arr[j].next = &arr[j + 1];
    }
   
    rev_listnode(arr, 5);
    delete [] arr;
   
    return 0;
}
