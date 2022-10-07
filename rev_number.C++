#include <iostream>
#include <assert.h>

int base(int, int);
int reverse_bites(char*);

int main()
{
    char* n = new char [32];
    assert(n);
    for(int i = 0; i < 32; ++i)
    {
       std:cin >> n[i];
    }
    std::cout << reverse_bites(n);
    delete [] n;
    
    return 0;
}

int base(int n, int k)
{
    if(k == 0){ return 1; }
    int s = 1, i = 1;
    while(i <= k)
    {
        s *= n;
        ++i;
    }
    return s;
}

int reverse_bites(char* name)
{
    int sum = 0;
    char* n = new char[32];
    assert(n);
    int j = 0;
    for(int i = 31; i >= 0; --i)
    {
        n[j] = name[i];
        ++j;
    }
     int k = 31;
    for(int i = 0; i < 32; ++i)
    {
        if(n[i] == '1')
        {
            sum += base(2, k);
        }
        k--;
    }
    delete [] n;
    
    return sum;
}
