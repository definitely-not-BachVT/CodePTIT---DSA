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

        vector<string> res;
        queue<string> q;

        q.push("6");
        q.push("8");

        while (true)
        {
            string x = q.front();
            q.pop();

            if (x.size() > n)
                break;

            res.push_back(x);
            q.push(x + "6");
            q.push(x + "8");
        }

        int size = res.size();
        cout << size << "\n";
        for (int i = size - 1; i >= 0; --i)
            cout << res[i] << " ";
        cout << "\n";
    }
}