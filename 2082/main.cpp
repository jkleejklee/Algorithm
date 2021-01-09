#include <cstdio>
#include <stack>
using namespace std;
struct Rectangle
{
    int w;
    int h;
};
int W; 
int ans; 
stack<Rectangle> s;
void scan(int h)
{
    W = 0;
    while (!s.empty() && s.top().h > h)
    {
        W += s.top().w;
        ans = max(ans, W * s.top().h);
        s.pop();
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) && ~n)
    {
        ans = 0;
        int H = 0; 
        while (n--)
        {
            Rectangle r;
            scanf("%d%d", &r.w, &r.h);
            if (r.h < H)
            {
                scan(r.h);
                W += r.w;
                r.w = W;
            }
            s.push(r);
            H = r.h;
        }
        scan(0); 
        printf("%d\n", ans);
    }
    return 0;
}
