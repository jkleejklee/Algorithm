#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, string> D;
    char s[22], f[11], e[11];
    while (gets(s) && s[0])
    {
        sscanf(s, "%s %s", f, e);
        D[e] = f;
    }
    while (gets(f) && f[0])
        puts(D[f].size() ? D[f].c_str() : "eh");
    return 0;
}
