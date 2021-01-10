#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1501;
int n;  
int P[N]; 
int D[N][2];
int s[N]; 
void DFS(int u)
{
    D[u][0] = 0;
    D[u][1] = 1;
    if (!s[u])
        return;
    for (int v = 0; v < n; v++)
        if (P[v] == u)
        {
            DFS(v); 
            D[u][0] += D[v][1];
            D[u][1] += min(D[v][1], D[v][0]);
        }
}
int main()
{
    while (~scanf("%d", &n))
    {
        fill(P, P + N, -1); 
        for (int i = 0; i < n; i++)
        {
            int u, m;
            scanf("%d:(%d)", &u, &m);
            s[u] = m;
            while (m--)
            {
                int v;
                scanf("%d", &v);
                P[v] = u; 
            }
        }
        int u;
        for (u = 0; ~P[u]; u = P[u])
            ;
        DFS(u); 
        printf("%d\n", min(D[u][0], D[u][1]));
    }
    return 0;
}
