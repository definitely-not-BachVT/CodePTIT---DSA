#include <bits/stdc++.h>
using namespace std;

int n, p, s, st, ed;
vector<long long> isPrime(1e6 + 3, 1);
vector<long long> snt;

void sieve()
{
    for (long long i = 2; i < 1e6 + 3; ++i)
        if (isPrime[i])
            for (long long j = i * i; j < 1e6 + 3; j += i)
                isPrime[j] = 0;

    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < 1e6 + 3; ++i)
        if (isPrime[i])
            snt.push_back(i);
}

vector<int> curr;
set<string> res;
void Try(long long sum, int idx, int cnt)
{
    if (sum == s)
    {
        if (cnt == n)
        {
            string tmp = "";
            for (int i = 0; i < n; ++i)
                tmp = tmp + to_string(curr[i]) + " ";
            res.insert(tmp);
        }

        return;
    }

    for (int i = idx; i < ed; ++i)
    {
        if (sum + snt[i] <= s && cnt < n)
        {
            curr.push_back(snt[i]);
            Try(sum + snt[i], i + 1, cnt + 1);
            curr.pop_back();
        }
        else
            break;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    sieve();

    while (t--)
    {
        curr.clear();
        res.clear();

        // cout << "ok";

        cin >> n >> p >> s;
        st = upper_bound(snt.begin(), snt.end(), p) - snt.begin();
        ed = upper_bound(snt.begin(), snt.end(), s) - snt.begin() + 2;

        // cout << st << " " << ed;

        Try(0, st, 0);

        cout << res.size() << "\n";
        for (auto x : res)
        {
            for (auto y : x)
                cout << y;
            cout << "\n";
        }
    }
}