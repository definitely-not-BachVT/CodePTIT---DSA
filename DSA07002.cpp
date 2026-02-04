#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    stack<long long> st;
    while (n--)
    {
        string s;
        cin >> s;

        if (s == "PUSH")
        {
            long long x;
            cin >> x;

            st.push(x);
            continue;
        }

        if (s == "POP")
        {
            if (!st.empty())
                st.pop();
            continue;
        }

        if (s == "PRINT")
        {
            if (st.empty())
                cout << "NONE\n";
            else
                cout << st.top() << "\n";
            continue;
        }
    }
}