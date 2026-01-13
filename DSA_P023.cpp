#include <bits/stdc++.h>
using namespace std;

vector<int> isPrime(1e5 + 2, 1);
vector<int> snt;
void sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i < 1e5 + 2; ++i)
        if (isPrime[i])
            for (int j = i * i; j < 1e5 + 2; j += i)
                isPrime[j] = 0;

    // for (int i = 2; i < 1e6 + 2; ++i)
    //     if (isPrime[i])
    //         snt.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int n, k, idx = 2;
    cin >> n >> k;

    vector<int> a(n, 0);
    for (int i = 0; i < k; ++i)
        a[i] = 1;

    while (prev_permutation(a.begin(), a.end()))
    {
        if (isPrime[idx])
        {
            cout << idx << ": ";
            for (int i = 0; i < n; ++i)
                if (a[i])
                    cout << i + 1 << " ";
            cout << "\n";
        }

        ++idx;
    }
}