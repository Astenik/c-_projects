#include <iostream>
#include <assert.h>
using namespace std;
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
/*this function returns the number where the two nodelists are intersected*/
string intesrected_lists(ListNode* n1, ListNode* n2, int s1, int s2)
{
    for(int i = 0; i < s1; ++i)
    {
        for(int j = 0; j < s2; ++j)
        {
            if(n1[i].next == n2[j].next)
            {
                return to_string(n1[i].value);
            }
        }
    }
    return "no intersection";
}
