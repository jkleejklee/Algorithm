#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int v[5][5] =
    {
        5, -1, -2, -1, -3,
        -1, 5, -3, -2, -4,
        -2, -3, 5, -2, -2,
        -1, -2, -2, 5, -1,
        -3, -4, -2, -1, 0};
int main()
{
    int s[N];
    s['A'] = 0;
    s['C'] = 1;
    s['G'] = 2;
    s['T'] = 3;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char A[N], B[N];
        int m, n;
        scanf("%d %s%d %s", &m, A, &n, B);
        int D[N][N];
        for (int i = 1; i <= m; i++)
            D[i][0] = D[i - 1][0] + v[s[A[i - 1]]][4]; 
        for (int j = 1; j <= n; j++)
            D[0][j] = D[0][j - 1] + v[s[B[j - 1]]][4]; 
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = max(
                    max(D[i - 1][j] + v[s[A[i - 1]]][4],
                        D[i][j - 1] + v[s[B[j - 1]]][4]),
                    D[i - 1][j - 1] + v[s[A[i - 1]]][s[B[j - 1]]]);
        printf("%d\n", D[m][n]);
    }
    return 0;
}
