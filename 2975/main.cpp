#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int k[1001]; 
        int s = 0;  
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &k[i]);
            s ^= k[i];
        }
        for (int i = 0; i < n; i++)
            if ((s ^ k[i]) < k[i])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
