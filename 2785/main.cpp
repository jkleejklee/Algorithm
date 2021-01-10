#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1e7 + 7;   
const int MAX = (2 << 28) + 1; 
int H[M];
int C[M];
int Hash(int x)
{
    return (x + MAX) % M;
}
void Insert(int x)
{
    int y = Hash(x);
    while (H[y] != MAX && H[y] != x)
        y = (y + 1) % M;
    H[y] = x;
    C[y]++;
}
int Find(int x)
{
    int y = Hash(x);
    while (H[y] != MAX && H[y] != x)
        y = (y + 1) % M;
    return (H[y] == MAX) ? 0 : C[y];
}
int main()
{
    fill(H, H + M, MAX);
    int n;
    scanf("%d", &n);
    int a[4005][4];
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= 4; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Insert(a[i][1] + a[j][2]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += Find(-a[i][3] - a[j][4]);
    printf("%d\n", ans);
    return 0;
}
