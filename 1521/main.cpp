#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
    char a[200];
    while (gets(a))
    {
        priority_queue<int, vector<int>, greater<int> > s;
        if (!strcmp(a, "END"))
            break;
        int c[96] = {0};
        for (int i = 0; a[i]; i++)
            c[a[i]]++;
        for (int i = 65; i < 96; i++)
            if (c[i])
                s.push(c[i]);
        int n = 0;
        while (s.size() >= 2)
        {
            int u = s.top();
            s.pop();
            int v = s.top();
            s.pop();
            n += u + v;
            s.push(u + v);
        }
        int len = strlen(a);
        if (!n)
            n = len;
        printf("%d %d %.1f\n", 8 * len, n, 8.0 * len / n);
    }
}
