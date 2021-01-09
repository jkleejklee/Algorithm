#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005];
int partition(int left, int right)
{
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (a[j] < a[right])
        {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i;
}
void quickSort(int left, int right)
{
    if (left < right)
    {
        int i = partition(left, right);
        quickSort(left, i - 1);
        quickSort(i + 1, right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    quickSort(1, n);
    printf("%d\n", a[(n + 1) / 2]);
    return 0;
}
