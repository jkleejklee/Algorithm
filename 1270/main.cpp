#include <cstdio>
#include <cstring>
using namespace std;
int m;
int d[123];  
char t[22];  
bool a[123][123]; 
void Toposort(int n)
{
    if (n == m)
        puts(t);
    for (int i = 97; i <= 122; i++)
        if (!d[i])
        {
            t[n] = i;
            d[i]--;
            for (int j = 97; j <= 122; j++)
                if (a[i][j])
                    d[j]--;
            Toposort(n + 1);
            d[i]++;
            for (int j = 97; j <= 122; j++)
                if (a[i][j])
                    d[j]++;
        }
}
int main()
{
    unsigned int i;
    char s[210];
    while (gets(s) != NULL)
    {
        memset(a, 0, sizeof(a));
        memset(d, -1, sizeof(d));
        memset(t, 0, sizeof(t));
        for (i = 0; i < strlen(s); i += 2)
            d[s[i]]++;
        m = i / 2;
        gets(s);
        for (i = 0; i < strlen(s); i += 4)
            if (!a[s[i]][s[i + 2]])
            {
                a[s[i]][s[i + 2]] = true;
                d[s[i + 2]]++;
            }
        Toposort(0);
        printf("\n");
    }
}
