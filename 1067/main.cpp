#include <cstdio>
#include <algorithm>
using namespace std;
const double phi = 1.61803399;
int main()
{
    int a, b;
    while (~scanf("%d%d", &a, &b))
        printf("%d\n", min(a, b) != (int)(abs(b - a) * phi));
    return 0;
}
