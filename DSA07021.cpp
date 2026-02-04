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
        string s;
        cin >> s;

        stack<int> st;
        st.push(-1);

        int sz = s.size();
        int mx = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                st.pop();

                if (st.empty())
                    st.push(i);
                else
                    mx = max(mx, i - st.top());
            }
        }

        cout << mx << "\n";
    }
}