#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<string> F, B;
    string URL = "http://www.acm.org/";
    string C;
    do
    {
        cin >> C;
        switch (C[0])
        {
        case 'V':
            B.push(URL);
            while (!F.empty())
                F.pop();
            cin >> URL;
            cout << URL << endl;
            break;
        case 'B':
            if (B.empty())
                cout << "Ignored" << endl;
            else
            {
                F.push(URL);
                URL = B.top();
                B.pop();
                cout << URL << endl;
            }
            break;
        case 'F':
            if (F.empty())
                cout << "Ignored" << endl;
            else
            {
                B.push(URL);
                URL = F.top();
                F.pop();
                cout << URL << endl;
            }
            break;
        }
    } while (C[0] != 'Q');
    return 0;
}
