#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
    int n;
    vector<vector<long long>> a;

    void set0()
    {
        a.assign(n, vector<long long>(n, 0));
    }

    void unit()
    {
        set0();
        for (int i = 0; i < n; ++i)
            a[i][i] = 1;
    }

    Matrix operator*(const Matrix other) const
    {
        Matrix ans;
        ans.n = n;
        ans.set0();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans.a[i][j] = (ans.a[i][j] + (a[i][k] * other.a[k][j]) % MOD) % MOD;

        return ans;
    }
};

Matrix binPow(Matrix a, long long b)
{
    Matrix ans;
    ans.n = a.n;
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
        int n, b;
        cin >> n >> b;

        Matrix a;
        a.n = n;
        a.set0();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a.a[i][j];

        Matrix ans = binPow(a, b);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << ans.a[i][j] << " ";
            cout << "\n";
        }
    }
}