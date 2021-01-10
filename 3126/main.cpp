#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
const int N = 10000;
bool isPrime[N];
void prime()
{
    fill(isPrime + 2, isPrime + N, true);
    for (int x = 4; x < N; x++)
    {
        if (x % 6 != 1 && x % 6 != 5)
            isPrime[x] = false;
        for (int i = 5; i * i <= x; i += 6)
            if (x % i == 0 || x % (i + 2) == 0)
                isPrime[x] = false;
    }
}
void itos(int a, char *b)
{
    b[0] = a / 1000 + '0';
    a %= 1000;
    b[1] = a / 100 + '0';
    a %= 100;
    b[2] = a / 10 + '0';
    a %= 10;
    b[3] = a + '0';
}
int stoi(char *a)
{
    return (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
}
int BFS(int x, int y)
{
    int v[N];
    fill(v, v + N, INT_MAX);
    queue<int> Q;
    Q.push(x);
    v[x] = 0;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        if (p == y)
            printf("%d\n", v[p]);
        for (int i = 0; i < 4; i++)
            for (char j = '0'; j <= '9'; j++)
            {
                char s[4];
                int q = p;
                itos(q, s);
                s[i] = j;
                q = stoi(s);
                if (q > 1000 && isPrime[q] && v[p] + 1 < v[q])
                {
                    v[q] = v[p] + 1;
                    Q.push(q);
                }
            }
    }
    return 0;
}
int main()
{
    prime();
    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        BFS(x, y);
    }
    return 0;
}
