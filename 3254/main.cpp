#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 15;
const int M = 2731;
const int MOD = 100000000;
int m, n;
vector<int> a[N]; 
int read()
{
    int x = 0, a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        x <<= 1;
        x += a;
    }
    return x;
}
void init()
{
    for (int i = 0; i < m; i++)
    {
        int y = read();
        for (int x = 0; x < (1 << n); x++)
            if (x == (x & y) && !(x & x << 1)) 
                a[i].push_back(x);
    }
}
int main()
{
    int D[N][M];
    int ans = 0;
    scanf("%d%d", &m, &n);
    init();
    fill(D[0], D[0] + a[0].size(), 1);
    for (int i = 1; i < m; i++)
        for (unsigned int j = 0; j < a[i].size(); j++)
            for (unsigned int k = 0; k < a[i - 1].size(); k++)
                if (!(a[i][j] & a[i - 1][k])) 
                    D[i][j] += D[i - 1][k];
    for (unsigned int j = 0; j < a[m - 1].size(); j++)
        ans += D[m - 1][j];
    printf("%d\n", ans % MOD);
    return 0;
}
