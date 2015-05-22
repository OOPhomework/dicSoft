#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


int main()
{
	std::vector<int> v;
    for (int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    for (int i =0;i < v.size();i++)
    {
        cout <<v[i]<<endl;
    }
    v.erase(v.begin()+3);
    for (int i =0;i < v.size();i++)
    {
        cout <<v[i]<<endl;
    }

	return 0;
}