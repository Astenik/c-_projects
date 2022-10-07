#include <iostream>
#include <assert.h>

void intersection_of_arrays(int*, int*, int, int);

int main()
{  
     int size1, size2;
     
     std::cout << "input size1" << std::endl;
     std::cin >> size1;
     
     std::cout << "input size2" << std::endl;
     std::cin >> size2;
     
    int* nums1 = new int [size1];
    assert(nums1);
     
    int* nums2 = new int [size2];
    assert(nums2);
     
     for(int i = 0; i < size1; ++i)
     {
         std::cout << "input the member of nums1";
         std::cin >> nums1[i];
     }
     
     for(int i = 0; i < size2; ++i)
     {
         std::cout << "input the member of nums2";
         std::cin >> nums2[i];
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
       for(int j = 0; i < s2; ++j)
       {
           if(v1[i] == v2[j])
           {
                v[q] = v1[i];
                ++q;
           }
       }
    }
}
            
           
           
           
           
           
           
           
           
           
