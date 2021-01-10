#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int s = 0; 
        int n;
        int p[1010] = {0}; 
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        sort(p + 1, p + n + 1); 
        for (int i = n; i > 0; i -= 2)
            s ^= (p[i] - p[i - 1] - 1); 
        puts(s ? "Georgia will win" : "Bob will win");
    }
    return 0;
}
