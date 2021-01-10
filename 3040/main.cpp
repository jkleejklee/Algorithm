#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100005;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    int n; 
    int c; 
    scanf("%d%d", &n, &c);
    pair<int, int> a[25]; 
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n, cmp); 
    int s = 0;  
    int tmp;
    int ans = 0;
    while (s < n && a[s].first >= c)
        ans += a[s++].second;
    do
    {
        tmp = c;
        for (int i = s; i < n; i++)
            if (a[i].second)
            {
                int k = min(tmp / a[i].first, a[i].second);
                a[i].second -= k;
                tmp -= k * a[i].first;
            }
        for (int i = n - 1; i >= s && tmp > 0; i--)
            if (a[i].second)
            {
                int k = tmp / a[i].first;
                k = min(a[i].second, (tmp % a[i].first) ? k + 1 : k);
                a[i].second -= k;
                tmp -= k * a[i].first;
            }
        if (tmp <= 0)
            ans++;
    } while (tmp <= 0);
    printf("%d\n", ans);
    return 0;
}
