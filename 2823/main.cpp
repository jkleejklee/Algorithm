#include <cstdio>
#include <queue>
using namespace std;
int a[1000005];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    deque<int> minQ;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        while (!minQ.empty() && a[i] < a[minQ.back()])
            minQ.pop_back();
        minQ.push_back(i);
        while (minQ.front() < i - k + 1)
            minQ.pop_front();
        if (i >= k)
            printf("%d ", a[minQ.front()]);
    }
    printf("\n");
    deque<int> maxQ;
    for (int i = 1; i <= n; i++)
    {
        while (!maxQ.empty() && a[i] > a[maxQ.back()])
            maxQ.pop_back();
        maxQ.push_back(i);
        while (maxQ.front() < i - k + 1)
            maxQ.pop_front();
        if (i >= k)
            printf("%d ", a[maxQ.front()]);
    }
    printf("\n");
    return 0;
}
