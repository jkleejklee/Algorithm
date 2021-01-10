#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10001;
const int M = 1000001;
int next[N];
int ans;
void getnext(char *a, int len)
{
    next[0] = next[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int j = next[i];
        while (j && a[j] != a[i])
            j = next[j];
        next[i + 1] = (a[j] == a[i]) ? j + 1 : 0;
    }
}
void KMP(char *S, char *P)
{
    int len = strlen(P);
    getnext(P, len);
    for (int i = 0, j = 0; S[i]; i++)
    {
        while (j && S[i] != P[j])
            j = next[j];
        if (S[i] == P[j])
            j++;
        if (j == len)
            ans++;
    }
}
int main()
{
    int n;
    char W[N], T[M];
    scanf("%d", &n);
    while (n--)
    {
        ans = 0;
        scanf("%s", W);
        scanf("%s", T);
        KMP(T, W);
        printf("%d\n", ans);
    }
    return 0;
}
