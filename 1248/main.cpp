#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t; 
char s[15];
int v[15]; 
void solve(int len)
{
    for (int a = 0; a < len; a++)
        for (int b = 0; b < len; b++)
            for (int c = 0; c < len; c++)
                for (int d = 0; d < len; d++)
                    for (int e = 0; e < len; e++)
                        if (a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e)
                            if (v[a] - v[b] * v[b] + v[c] * v[c] * v[c] - v[d] * v[d] * v[d] * v[d] + v[e] * v[e] * v[e] * v[e] * v[e] == t)
                            {
                                printf("%c%c%c%c%c\n", s[a], s[b], s[c], s[d], s[e]);
                                return;
                            }
    printf("no solution\n");
}
bool cmp(char a, char b)
{
    return a > b;
}
int main()
{
    while (~scanf("%d %s", &t, s))
    {
        if (!t && !strcmp(s, "END"))
            return 0;
        int len = strlen(s);
        sort(s, s + len, cmp);
        for (int i = 0; i < len; i++)
            v[i] = s[i] - 'A' + 1;
        solve(len);
    }
    return 0;
}
