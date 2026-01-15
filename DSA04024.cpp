#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
    int n;
    vector<vector<long long>> a;

    void setSize()
    {
        a.assign(n, vector<long long>(n));
    }

    void set0()
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = 0;
    }

    void unit()
    {
        set0();
        for (int i = 0; i < n; ++i)
            a[i][i] = 1;
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix ans;
        ans.n = n;
        ans.setSize();
        ans.set0();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans.a[i][j] = (ans.a[i][j] + ((a[i][k] * other.a[k][j]) % MOD)) % MOD;

        return ans;
    }
};

Matrix binPow(Matrix a, long long b)
{
    Matrix ans;
    ans.n = a.n;
    ans.setSize();
    ans.unit();

    while (b)
    {
        if (b % 2)
            ans = ans * a;
        a = a * a;

        b /= 2;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        Matrix a;
        a.n = n;
        a.setSize();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> a.a[i][j];
                a.a[i][j] %= MOD;
            }

        Matrix ans = binPow(a, k);

        long long sum = 0;
        for (int i = 0; i < n; ++i)
            sum = (sum + ans.a[i][n - 1]) % MOD;

        cout << sum << "\n";
    }
}