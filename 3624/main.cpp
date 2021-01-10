#include <cstdio>
using namespace std;
#define MAX(a, b) (a > b ? a : b)
int F[15000], V;
void zeroonePack(int c, int w)
{
    for (int v = V; v >= c; v--)
        F[v] = MAX(F[v], F[v - c] + w);
}
int main()
{
    int n;
    scanf("%d%d", &n, &V);
    while (n--)
    {
        int w, d;
        scanf("%d%d", &w, &d);
        zeroonePack(w, d); 
    }
    printf("%d\n", F[V]);
    return 0;
}
