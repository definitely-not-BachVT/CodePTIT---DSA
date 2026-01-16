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

        vector<int> a(n), right(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && a[st.top()] <= a[i])
                st.pop();

            if (st.empty())
                right[i] = -1;
            else
                right[i] = st.top();

            st.push(i);
        }

        for (int i = 0; i < n; ++i)
            if (right[i] != -1)
                cout << a[right[i]] << " ";
            else
                cout << "-1 ";
        cout << "\n";
    }
}