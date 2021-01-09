#include <cstdio> 
using namespace std;
int main()
{
    int p, e, i, d, n = 1;
    while (scanf("%d%d%d%d", &p, &e, &i, &d) && ~p)
    {
        int x;
        for (x = 21252; x > 0; x--)
            if (x % 23 == p % 23 && x % 28 == e % 28 && x % 33 == i % 33)
                break;
        int ans = (x > d) ? x - d : x + 21252 - d;
        printf("Case %d: the next triple peak occurs in %d days.\n", n++, ans);
    }
    return 0;
}
