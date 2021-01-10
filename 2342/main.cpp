#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 6005;
struct node
{
    int p; 
    int r; 
} T[N];
int n; 
int D[N][2];
void DFS(int u)
{
    D[u][0] = 0;
    D[u][1] = T[u].r;
    for (int v = 1; v <= n; v++)
        if (T[v].p == u)
        {
            DFS(v); 
            D[u][0] += max(D[v][0], D[v][1]);
            D[u][1] += D[v][0];
        }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &T[i].r);
        T[i].p = -1; 
    }
    int l;
    int k; 
    while (scanf("%d%d", &l, &k) && (l || k))
        T[l].p = k;
    int u;
    for (u = 1; ~T[u].p; u = T[u].p)
        ;
    DFS(u);
    printf("%d\n", max(D[u][0], D[u][1]));
    return 0;
}
