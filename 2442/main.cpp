#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        priority_queue<int> Q;
        int m, n;
        scanf("%d%d", &m, &n);
        int a[105][2005];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
            sort(a[i], a[i] + n);
            for (int j = 0; i && j < n; j++)
                for (int k = 0; k < n; k++)
                {
                    if (j)
                    {
                        if (Q.top() > a[i][j] + a[0][k])
                            Q.pop();
                        else
                            break;
                    }
                    Q.push(a[i][j] + a[0][k]);
                }
            for (int k = n - 1; i && k >= 0; k--)
            {
                a[0][k] = Q.top();
                Q.pop();
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d ", a[0][i]);
        printf("\n");
    }
    return 0;
}
