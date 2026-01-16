#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s = "9";
        queue<string> q;

        q.push(s);
        while (true)
        {
            string tmp = q.front();
            q.pop();

            long long x = stoll(tmp);
            if (x % n == 0)
            {
                cout << x << "\n";
                break;
            }

            string tmp1 = tmp + "0";
            string tmp2 = tmp + "9";

            q.push(tmp1);
            q.push(tmp2);
        }
    }
}