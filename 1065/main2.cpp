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
        int n;
        scanf("%d", &n);
        pair<int, int> a[N];
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a, a + n);
        int k = 0;
        int d[N];
        for (int i = 0; i < n; i++)
        {
            int p = -1;
            int r = k;
            while (r - p > 1)
            {
                int mid = (p + r) / 2;
                if (d[mid] > a[i].second)
                    p = mid;
                else
                    r = mid;
            }
            d[r] = a[i].second; 
            if (r == k)
                k++;
        }
        printf("%d\n", k);
    }
    return 0;
}
