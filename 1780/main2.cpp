#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000010;
const int P[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
bool edge[N][10]; 
char out[N]; 
int m, p;
void euler(int u)
{
    for (int i = 0; i < 10; i++)
        if (edge[u][i])
        {
            edge[u][i] = false;
            euler((u * 10 + i) % m);
            out[p++] = i + '0';
        }
}
int main()
{
    int n, i;
    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n - 1; i++)
            putchar('0');
        m = P[n];
        for (i = 0; i < m; i++)
            fill_n(edge[i], 10, true);
        p = 0;
        euler(0);
        for (i = p - 1; i >= 0; i--)
            putchar(out[i]);
        printf("\n");
    }
    return 0;
}
