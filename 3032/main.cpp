#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        queue<int> Q;
        int a[15]; 
        int k = 1; 
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            Q.push(i); 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                Q.push(Q.front());
                Q.pop();
            }
            a[Q.front()] = k++;
            Q.pop();
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
