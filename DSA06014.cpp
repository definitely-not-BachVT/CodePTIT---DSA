#include <bits/stdc++.h>
using namespace std;

vector<int> isPrime(1e6 + 3, 1);
vector<int> snt;
void sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1e6 + 3; ++i)
        if (isPrime[i])
            for (int j = i * i; j < 1e6 + 3; j += i)
                isPrime[j] = 0;

    for (int i = 2; i < 1e6 + 3; ++i)
        if (isPrime[i])
            snt.push_back(i);
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
        int n;
        cin >> n;

        bool found = false;
        for (int x : snt)
        {
            if (x >= n)
                break;

            if (isPrime[n - x])
            {
                found = true;
                cout << x << " " << n - x << "\n";
                break;
            }
        }

        if (!found)
            cout << "-1\n";
    }
}