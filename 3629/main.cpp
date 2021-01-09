#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    queue<int> Q;
    int a[50005]; 
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 1; i <= k; i++)
        Q.push(i);
    int m;
    for (m = 0; m < k / n; m++)
        for (int i = 1; i <= n; i++)
        {
            if (i == n)
                a[m] = Q.front();
            Q.pop();
            for (int j = 0; j < p; j++)
            {
                Q.push(Q.front());
                Q.pop();
            }
        }
    sort(a, a + m);
    for (int i = 0; i < m; i++)
        printf("%d\n", a[i]);
    return 0;
}
