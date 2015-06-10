#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
    char ch;
    cin >>ch;
    while (ch)
    {    
        cout<<(char)toupper(ch)<<endl;
        cin >>ch;
    }
}