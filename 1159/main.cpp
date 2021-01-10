#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    string s1;
    cin >> n >> s1;
    string s2 = s1;
    reverse(s1.begin(), s1.end()); //将s1反转
    int c[2][5005] = {0};          //可以将c数组进行空间压缩，只需要两行就可以
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
                c[i & 1][j] = c[(i - 1) & 1][j - 1] + 1;
            else
                c[i & 1][j] = max(c[(i - 1) & 1][j], c[i & 1][j - 1]);
    cout << n - c[n & 1][n] << endl;
    return 0;
}
