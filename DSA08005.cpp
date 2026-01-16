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

        queue<string> q;
        q.push("1");

        while (true)
        {
            string x = q.front();
            q.pop();

            long long sum = 0;
            for (char c : x)
                sum = sum * 2 + (c - '0');
            if (sum > n)
                break;

            cout << x << " ";
            q.push(x + "0");
            q.push(x + "1");
        }

        cout << "\n";
    }
}