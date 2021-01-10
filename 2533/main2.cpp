#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1001;
int main()
{
    int n;
    scanf("%d", &n);
    int s[N];
    int k = 0; 
    while (n--)
    {
        int a;
        scanf("%d", &a);
        int m = lower_bound(s, s + k, a) - s; 
        s[m] = a;
        if (m == k)
            k++;
    }
    printf("%d\n", k);
    return 0;
}
