#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20001;
int trie[N][26]; 
int num[N];  
int pos = 1; 
void Insert(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int n = s[i] - 'a';
        if (!trie[p][n])
            trie[p][n] = pos++;
        p = trie[p][n];
        num[p]++;
    }
}
int Find(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int n = s[i] - 'a';
        if (!trie[p][n])
            return 0;
        p = trie[p][n];
    }
    return num[p];
}
int main()
{
    int cnt = 0; 
    char a[22], b[1001][22];
    while (~scanf("%s", b[cnt]))
        Insert(b[cnt++]);
    for (int i = 0; i < cnt; i++)
        for (int j = 0; b[i][j];)
        {
            strncpy(a, b[i], ++j);
            a[j] = '\0';
            if (Find(a) == 1 || !b[i][j])
            {
                printf("%s %s\n", b[i], a);
                break;
            }
        }
    return 0;
}
