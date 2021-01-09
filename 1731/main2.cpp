#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char s[200];
    gets(s);
    sort(s, s + strlen(s));
    puts(s);
    while (next_permutation(s, s + strlen(s)))
        puts(s);
    return 0;
}
