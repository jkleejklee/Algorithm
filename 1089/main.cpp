#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005;
int main()
{
    int n;
    scanf("%d", &n);
    pair<int, int> a[N]; 
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    printf("%d ", a[0].first);
    int R = a[0].second; 
    for (int i = 1; i < n; i++)
    {
        if (a[i].first > R)
        {
            printf("%d\n", R);
            printf("%d ", a[i].first);
            R = a[i].second;
        }
        else
            R = max(R, a[i].second);
    }
    printf("%d\n", R);
    return 0;
}
