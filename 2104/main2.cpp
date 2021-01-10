#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    pair<int, int> a[N];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    while (m--)
    {
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        int p = 0;
        int q = 1;
        while (p < k)
        {
            if (a[q].second >= i && a[q].second <= j)
                p++;
            q++;
        }
        printf("%d\n", a[q - 1].first);
    }
    return 0;
}
