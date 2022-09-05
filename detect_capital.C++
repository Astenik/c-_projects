#include <iostream>
#include <assert.h>
using namespace std;
bool detect_capital(char* name, int size)
{
    if(name[0] >= 'A' && name[0] <= 'Z')
    {
        int i, j;
        for(i = 1; i < size; ++i)
        {
            if(name[i] >= 'a' && name[i] <= 'z') {  continue; }
            else { break; }
        }
        if(i == size){  return true; }
        for(j = 1; j < size; ++j)
        {
            if(name[j] >= 'A' && name[j] <= 'Z') {  continue; }
            else { break; }
        }
        if(j == size) { return true; }
        else { return false; }
    }
    for(int k = 0; k < size; ++k)
    {
        if(name[k] >= 'A' && name[k] <= 'Z') { return false; }
        
    }
    return true;
}
