#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
const int N = 362890;
int Cantor(char a[])
{
    int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int res = 0;
    bool has[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        int x = a[i] - '0';
        int y = 0;
        for (int j = 1; j < x; j++)
            if (!has[j])
                y++;
        res += y * fac[8 - i];
        has[x] = true;
    }
    return res;
}
int getH(char a[])
{
    int res = 0;
    for (int i = 0; i < 9; i++)
        res += abs(i + 1 - a[i] + '0');
    return res;
}
struct Node
{
    string a; 
    int k; 
    int g;   
    int h;   
    string s; 
    Node(char a[], int b, string c) : a(a), k(b), g(Cantor(a)), h(getH(a)), s(c) {}
    bool operator<(const Node &a) const
    {
        return h > a.h;
    }
};
int main()
{
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
    char d[] = "rudl";
    bool v[N];
    priority_queue<Node> Q;
    char a[9];
    int b;
    string c;
    for (int i = 0; i < 9; i++)
    {
        scanf("%c%*c", &a[i]);
        if (a[i] == 'x')
        {
            a[i] = '9';
            b = i;
        }
    }
    Q.push(Node(a, b, c));
    while (1)
    {
        Node p = Q.top();
        if (!p.g) 
        {
            puts(p.s.c_str());
            break;
        }
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = p.k / 3 + dx[i];
            int y = p.k % 3 + dy[i];
            if (x < 0 || x > 2 || y < 0 || y > 2)
                continue;
            char a[9];
            strcpy(a, p.a.c_str());
            swap(a[p.k], a[x * 3 + y]);
            Node q = Node(a, x * 3 + y, p.s + d[i]);
            if (!v[q.g])
            {
                Q.push(q);
                v[q.g] = true;
            }
        }
    }
    return 0;
}
