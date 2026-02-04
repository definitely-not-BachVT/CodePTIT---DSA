#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long)1e9 + 7;

long long phi(long long n)
{
    long long cnt = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            cnt = cnt - n / i;
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        cnt -= 1;
    return cnt;
}

int mxS(vector<int> &a, int m)
{
    vector<int> left(m);
    stack<int> st;

    for (int i = 0; i < m; ++i)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.top();

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    vector<int> right(m);
    for (int i = m - 1; i >= 0; --i)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (st.empty())
            right[i] = m;
        else
            right[i] = st.top();

        st.push(i);
    }

    int mx = 0;
    for (int i = 0; i < m; ++i)
        mx = max(mx, a[i] * (right[i] - left[i] - 1));
    return mx;
}

long long binPow(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long half = binPow(a, b / 2);
    long long res = (half * half) % MOD;

    if (b % 2)
        res = (res * (a % MOD)) % MOD;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    stack<char> left, right;

    for (char c : s)
    {
        if (c == '-')
        {
            if (!left.empty())
                left.pop();
        }
        else if (c == '<')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (c == '>')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else
            left.push(c);
    }

    string ans = "";
    while (!left.empty())
    {
        ans.push_back(left.top());
        left.pop();
    }
    reverse(ans.begin(), ans.end());

    while (!right.empty())
    {
        ans.push_back(right.top());
        right.pop();
    }

    cout << ans;
}