#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100005;
int n;
int D[N][20];
void ST(int *B)
{
    for (int i = 1; i <= n; i++)
        D[i][0] = B[i];
    for (int j = 1; j <= log(n) / log(2); j++)    
        for (int i = 1; i + (1 << (j - 1)) <= n; i++) 
            D[i][j] = max(D[i][j - 1], D[i + (1 << (j - 1))][j - 1]);
}
int query(int i, int j)
{
    int k = log(j - i + 1) / log(2);
    return max(D[i][k], D[j - (1 << k) + 1][k]);
}
int main()
{
    int q;
    int A[N], B[N];
    while (scanf("%d", &n) && n)
    {
        scanf("%d", &q);
        A[0] = -10;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
            if (A[i] == A[i - 1])
            {
                B[i] = B[i - 1] + 1;
                B[i - 1] = 0;
            }
            else
                B[i] = 1;
        }
        ST(B); 
        while (q--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            int l = upper_bound(A + i, A + j, A[i]) - A;
            int r = (lower_bound(A + i, A + j, A[j]) - A) - 1;
            int ans = max(l - i, j - r);
            printf("%d\n", (r < l) ? ans : max(ans, query(l, r)));
        }
    }
    return 0;
}
