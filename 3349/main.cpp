#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100007;
const int M = N * 2;
int a[N][6];  
int h[M];  
bool found = false; 
int Hash(int *a)
{
    return (a[0] + a[1] + a[2] + a[3] + a[4] + a[5]) * 10 % M;
}
bool same(int *a, int *b)
{
    for (int i = 0; i < 6; i++)
    {
        int k = 0;
        while (a[k] == b[(i + k) % 6] && k < 6)
            k++;
        if (k == 6)
            return true;
        k = 0;
        while (a[k] == b[(i + 6 - k) % 6] && k < 6)
            k++;
        if (k == 6)
            return true;
    }
    return false;
}
void Insert(int i)
{
    int t = Hash(a[i]);
    if (h[t] != 0)
    {
        while (h[t] != 0 && !same(a[i], a[h[t]]))
            t = (t + 1) % M;
        found = h[t];
    }
    h[t] = i;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 6; j++)
            scanf("%d", &a[i][j]);
        if (!found)
            Insert(i);
    }
    printf(found ? "Twin snowflakes found.\n" : "No two snowflakes are alike.\n");
    return 0;
}
