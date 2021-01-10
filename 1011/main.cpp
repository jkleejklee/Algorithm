#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[64];
int u[64];
int x;
bool cmp(const int &x, const int &y)
{
    return x > y;
}
int DFS(int i, int s, int m)
{
    if (s == x)
    {
        if (m == n)
            return 1;
        s = 0;
        i = 0;
    }
    for (int k = i; k < n; k++) 
    {
        if (u[k])
            continue;
        if (s + a[k] > x) 
            continue;
        u[k] = 1;
        if (DFS(k + 1, s + a[k], m + 1))
            return 1;
        u[k] = 0;
        if (s == 0)
            return 0; 
        while (k < n && a[k + 1] == a[k])
            k++; 
    }
    return 0;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n, cmp); 
        for (x = a[0]; x <= sum; x++) 
        {
            if (sum % x) 
                continue;
            fill(u, u + n, 0);
            if (DFS(0, 0, 0))
                break;
        }
        printf("%d\n", x);
    }
    return 0;
}
