#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10001;
const int M = 101;
int g[N]; 
int s[M]; 
int k;  
int mex(int x)
{
    bool v[M] = {0};
    for (int i = 0; i < k; i++)
    {
        int y = x - s[i];
        if (y >= 0)
        {
            if (g[y] == -1)
                g[y] = mex(y);
            v[g[y]] = true;
        }
    }
    int i = 0;
    while (v[i])
        i++;
    return i;
}
int main()
{
    while (scanf("%d", &k) && k)
    {
        for (int i = 0; i < k; i++)
            scanf("%d", &s[i]);
        fill(g, g + N, -1);
        int m; 
        scanf("%d", &m);
        while (m--)
        {
            int l; 
            scanf("%d", &l);
            int r = 0; 
            while (l--)
            {
                int h; 
                scanf("%d", &h);
                r ^= mex(h);
            }
            printf(r ? "W" : "L"); 
        }
        printf("\n");
    }
    return 0;
}
