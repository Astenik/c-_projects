#include <iostream>
#include <assert.h>

class ListNode
{
  public:
     int value;
     ListNode* next;
     ListNode():value(0), next(nullptr){}
     ListNode(int val):value(val), next(nullptr){}
     ListNode(int val, ListNode* n): value(val), next(n){}
    ~ListNode(){ delete next; }
};

void merge_lists(ListNode* nums1, ListNode* nums2, int s1, int s2)
{
    int s = s1 + s2;
    int k = 0, i, j;
    ListNode* nums = new ListNode [s];
  
    for(i = 0; i < s1; )
    {
        for(j = 0; j < s2; )
        {
            if(nums1[i].value < nums2[j].value)
            {
                nums[k] = nums1[i];
                ++i;
            }
            else
            {
                nums[k] = nums2[j];
                ++j;
            }
            ++k;
        }
    }
    if(s1 > s2)
    {
        while(i < s1)
        {
            nums[k] = nums1[i];
            ++i;
            ++k;
        }
    }
    else
    {
        while(j < s2)
        {
            nums[k] = nums2[j];
            ++j;
            ++k;
        }
    }
  
    for(int d = 0; d < s - 1; ++d)
    {
        nums[d].next = &nums[d + 1];
    }
    nums[s - 1].next = nullptr;
    for(int d = 0; d < s; ++d)
    {
        std::cout << nums[d].value << " ";
    }
}

int main()
{
    ListNode* n1 = new ListNode [3];
    ListNode* n2 = new ListNode [4];
    for(int i = 0; i < 3; ++i)
         std::cin >> n1[i].value;
  
    for(int i = 0; i < 4; ++i)
         std::cin >> n2[i].value;
  
    for(int i = 0; i < 2; ++i)
         n1[i].next = &n1[i+1];
    n1[2].next = nullptr;
  
    for(int i = 0; i < 3; ++i)
         n2[i].next = &n2[i+1];
    n2[3].next = nullptr;
  
    merge_lists(n1, n2, 3, 4);
  
    return 0;
}
