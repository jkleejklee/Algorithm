#include <cstdio>
using namespace std;
const int N = 500005;
int a[N], b[N];
long long cnt;
void merge(int left, int mid, int right)
{
    int i = left; 
    int j = mid + 1; 
    int k = 0; 
    while (i <= mid && j <= right)
    {
        if (a[i] > a[j])
        {
            b[k++] = a[j++];
            cnt += mid - i + 1; 
        }
        else
            b[k++] = a[i++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= right)
        b[k++] = a[j++];
    while (k--)
        a[left + k] = b[k];
}
void mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        cnt = 0;
        mergeSort(0, n - 1);
        printf("%lld\n", cnt);
    }
    return 0;
}
