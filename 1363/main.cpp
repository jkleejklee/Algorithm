#include <cstdio>
#include <stack>
using namespace std;
bool solve(int n)
{
    int a = 1;
    bool p = true; 
    stack<int> S;
    while (n--)
    {
        int b; 
        scanf("%d", &b);
        if (!b)
            return false;
        while (a <= b)
            S.push(a++);
        if (!S.empty() && S.top() == b)
            S.pop();
        else
            p = false;
    }
    printf(p ? "Yes\n" : "No\n");
    return true;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        while (solve(n))
            ;
        printf("\n");
    }
    return 0;
}
