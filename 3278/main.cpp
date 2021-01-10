#include <cstdio>
#include <queue>
using namespace std;
const int N = 100001;
int main()
{
    int n, k, i;
    int a[N] = {0};
    queue<int> Q;
    scanf("%d%d", &n, &k);
    Q.push(n);
    do
    {
        i = Q.front();
        Q.pop();
        if (i > 0 && !a[i - 1])
        {
            a[i - 1] = a[i] + 1;
            Q.push(i - 1);
        }
        if (i + 1 < N && !a[i + 1])
        {
            a[i + 1] = a[i] + 1;
            Q.push(i + 1);
        }
        if (i * 2 < N && !a[i * 2])
        {
            a[i * 2] = a[i] + 1;
            Q.push(i * 2);
        }
    } while (i != k);
    printf("%d\n", a[k]);
    return 0;
}
