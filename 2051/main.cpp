#include <cstdio>
#include <queue>
using namespace std;
struct Data
{
    int n; 
    int p; 
    int t; 
    Data(int a, int b) : n(a), p(b), t(b) {}
    bool operator<(const Data &a) const
    {
        return (t > a.t) || (t == a.t && n > a.n);
    }
};
int main()
{
    priority_queue<Data> Q;
    char s[10];
    while (scanf("%s", s) && s[0] != '#')
    {
        int n, p;
        scanf("%d%d", &n, &p);
        Q.push(Data(n, p));
    }
    int k;
    scanf("%d", &k);
    while (k--)
    {
        Data a = Q.top();
        Q.pop();
        printf("%d\n", a.n);
        a.t += a.p;
        Q.push(a);
    }
    return 0;
}
