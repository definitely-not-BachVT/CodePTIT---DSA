#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000000000007LL;

struct Matrix
{
    long long a[4][4];

    void set0()
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                a[i][j] = 0;
    }

    void unit()
    {
        set0();
        for (int i = 0; i < 4; ++i)
            a[i][i] = 1;
    }

    void init()
    {
        set0();
        a[0][0] = a[0][1] = a[0][2] = 1;
        a[1][0] = 1;
        a[2][1] = 1;
        a[3][0] = a[3][1] = a[3][2] = a[3][3] = 1;
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix ans;
        ans.set0();

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 4; ++k)
                    ans.a[i][j] = (ans.a[i][j] + (__int128)a[i][k] * other.a[k][j]) % MOD;

        return ans;
    }
};

Matrix binPow(Matrix a, long long b)
{
    Matrix ans;
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
        long long n;
        cin >> n;

        if (n == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        if (n == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        if (n == 2)
        {
            cout << 3 << '\n';
            continue;
        }
        if (n == 3)
        {
            cout << 6 << '\n';
            continue;
        }

        Matrix M;
        M.init();

        M = binPow(M, n - 3);

        long long res = 0;
        res = (res + M.a[3][0] * 3) % MOD;
        res = (res + M.a[3][1] * 2) % MOD;
        res = (res + M.a[3][2] * 1) % MOD;
        res = (res + M.a[3][3] * 6) % MOD;

        cout << res << '\n';
    }

    return 0;
}
