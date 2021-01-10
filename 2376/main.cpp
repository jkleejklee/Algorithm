#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int N, T;
    pair<int, int> a[25005]; 
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a + 1, a + N + 1); 
    int k = 0;
    int R = 0; 
    int ans = 0;
    while (R < T)
    {
        int maxR = 0; 
        while (a[k = k + 1].first <= R + 1)
            maxR = max(maxR, a[k].second);
        if (!maxR)
        {
            ans = -1;
            break;
        }
        ans++;
        R = maxR;
        k--;
    }
    printf("%d\n", ans);
    return 0;
}
