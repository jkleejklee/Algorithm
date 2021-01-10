#include <cstdio>
#include <map>
using namespace std;
int main()
{
    map<int, int> a;
    int r;
    while (scanf("%d", &r) && r)
    {
        switch (r)
        {
        case 1:
            int k, p;
            scanf("%d%d", &k, &p);
            a[p] = k;
            break;
        case 2:
            if (a.empty())
            {
                printf("0\n");
                break;
            }
            printf("%d\n", (--a.end())->second);
            a.erase(--a.end());
            break;
        case 3:
            if (a.empty())
            {
                printf("0\n");
                break;
            }
            printf("%d\n", a.begin()->second);
            a.erase(a.begin());
            break;
        }
    }
    return 0;
}
