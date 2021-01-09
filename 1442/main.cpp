#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> R; 
    priority_queue<int, vector<int>, greater<int>> L; 
    int m, n;
    scanf("%d%d", &m, &n);
    int a[30005];
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    int i = 0;
    while (n--)
    {
        int u;
        scanf("%d", &u);
        while (i < u)
            L.push(a[i++]);
        while (!R.empty() && R.top() > L.top())
        {
            int t = R.top();
            R.pop();
            R.push(L.top());
            L.pop();
            L.push(t);
        }
        printf("%d\n", L.top());
        R.push(L.top());
        L.pop();
    }
    return 0;
}
