#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5001;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 1;
        int n;
        scanf("%d", &n);
        pair<int, int> a[N];
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a, a + n);
        int D[N];
        for (int i = 0; i < n; i++)
        {
            D[i] = 1;
            for (int j = 0; j < i; j++)
                if (a[j].second > a[i].second)
                    D[i] = max(D[i], D[j] + 1);
            ans = max(ans, D[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
