#include <iostream>
#include <assert.h>

int sum_of_sqr(int num)
{
    int sum = 0;
    int n;
    
    while(num != 0)
    {
        n = num % 10;
        sum += n*n;
        num /= 10;
    }
    return sum;
}

bool is_happy(int number)
{
    int n = sum_of_sqr(number);
    int count = 0;
    while(n != 1)
    {
        number = n;
        n = sum_of_sqr(number);
        ++count;
        if(count == 100)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << is_happy(n) << std::endl;
    
    return 0;
}
