#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
typedef map<string, int> item;
int main()
{
    int n = 0;
    item a;
    string s;
    while (getline(cin, s))
    {
        n++;
        a[s]++;
    }
    for (item::iterator it = a.begin(); it != a.end(); it++)
        printf("%s %.4f\n", it->first.c_str(), it->second * 100.0 / n);
    return 0;
}
