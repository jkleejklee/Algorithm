#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t, w;
    scanf("%d%d", &t, &w);
    int D[35] = {0};
    while (t--)
    {
        int x;
        scanf("%d", &x);
        D[0] += x % 2; 
        for (int i = 1; i <= w; i++)
            D[i] = max(D[i], D[i - 1]) + (i + x) % 2;
    }
    printf("%d\n", D[w]);
    return 0;
}
