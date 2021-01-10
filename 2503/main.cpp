#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100003 * 2;
char A[N][11]; 
char H[N][11]; 
unsigned int BKDRhash(const char *key)
{
    unsigned int seed = 31, h = 0;
    while (*key)
        h = h * seed + (*key++);
    return h & 0x7fffffff;
}
void Insert(char *f, char *e)
{
    int y = BKDRhash(e) % N;
    while (strcmp(H[y], e) && H[y][0])
        y = (y + 1) % N;
    strcpy(A[y], f);
    strcpy(H[y], e);
}
void Find(char *x)
{
    int y = BKDRhash(x) % N;
    while (strcmp(H[y], x) && H[y][0])
        y = (y + 1) % N;
    puts(H[y][0] ? A[y] : "eh");
}
int main()
{
    char s[22];
    char f[11]; 
    char e[11]; 
    while (gets(s) && s[0])
    {
        sscanf(s, "%s %s", f, e);
        Insert(f, e);
    }
    while (gets(f) && f[0])
        Find(f);
    return 0;
}
