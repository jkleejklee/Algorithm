#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1001;
int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1;
    int D[N];
    for (int i = 0; i < n; i++)
    {
        int a[N];
        scanf("%d", &a[i]);
        D[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) 
                D[i] = max(D[i], D[j] + 1);
        ans = max(ans, D[i]);
    }
    printf("%d\n", ans);
    return 0;
}
