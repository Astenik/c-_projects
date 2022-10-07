#include <iostream>
#include "Vector.h" 
//this file is exist in classes repo.//

int bin_sum(int number)
{
   int s = 0;
   while(number != 0)
   {
       s += number % 2;
       number /= 2;
   }
   
   return s;
} 

void counting_bites(int number)
{
    Vector res;
    for(int i = 0; i <= number; ++i)
    {
        res.push_back(bin_sum(i));
    }
    for(int i = 0; i < res.get_size(); ++i)
    {
        std::cout << res[i] << " ";
    }
}

int main()
{
    int n;
    std::cin >> n;
    counting_bites(n);
   
    return 0;
}
