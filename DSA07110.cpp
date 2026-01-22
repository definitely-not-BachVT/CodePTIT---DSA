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

        bool ok = true;

        int size = s.size();
        stack<char> st;

        for (int i = 0; i < size; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (s[i] == ']')
                {
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else
                    {
                        ok = false;
                        break;
                    }

                    continue;
                }

                if (s[i] == '}')
                {
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else
                    {
                        ok = false;
                        break;
                    }

                    continue;
                }

                if (s[i] == ')')
                {
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else
                    {
                        ok = false;
                        break;
                    }

                    continue;
                }
            }
        }

        if (!st.empty())
            ok = false;

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}