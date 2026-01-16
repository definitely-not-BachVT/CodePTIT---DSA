#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        stack<string> st;
        stringstream ss(s);

        while (ss >> s)
            st.push(s);

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        cout << "\n";
    }
}