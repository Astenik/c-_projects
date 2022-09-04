#include <iostream>
#include <assert.h>
using namespace std;
void intersection_of_arrays(int*, int*, int, int);
int main()
{   int size1, size2;
     cout<<"input size1"<<endl;
     cin>>size1;
     cout<<"input size2"<<endl;
     cin>>size2;
    int* nums1 = new int [size1];
    assert(nums1);
    int* nums2 = new int [size2];
    assert(nums2);
     for(int i = 0; i < size1; ++i)
     {
         cout<<"input the member of nums1";
         cin>>nums1[i];
     }
     for(int i = 0; i < size2; ++i)
     {
         cout<<"input the member of nums2";
         cin>>nums2[i];
     }
     intersection_of_arrays(nums1, nums2, size1, size2);
     delete [] nums1;
     delete [] nums2;
     return 0;
}
void intersection_of_arrays(int* v1, int* v2, int s1, int s2)
{
    int s = s1 > s2 ? s2 : s1;
    int* v = new int [s];
    int q = 0;
    for(int i = 0; i < s1; ++i)
    {
