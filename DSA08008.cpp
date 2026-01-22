#include <bits/stdc++.h>
using namespace std;

long long n, siz;
vector<long long> res;

void sinh()
{
    queue<string> q;
    q.push("1");

    while (!q.empty())
    {
        string x = q.front();
        q.pop();

        res.push_back(stoll(x));

        if (x.size() < 19)
        {
            q.push(x + "0");
            q.push(x + "1");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    sinh();
    siz = res.size();

    while (t--)
    {
        cin >> n;

        long long pos = lower_bound(res.begin(), res.end(), n) - res.begin();
        for (long long i = pos; i < siz; ++i)
            if (res[i] % n == 0)
            {
                cout << res[i] << "\n";
                break;
            }
    }
}