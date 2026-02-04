#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<long long> st;
    int siz = 0;
    string s;

    while (cin >> s)
    {
        if (s == "push")
        {
            long long x;
            cin >> x;

            st.push_back(x);
            ++siz;

            continue;
        }
        else if (s == "show")
        {
            if (siz == 0)
            {
                cout << "empty\n";
                continue;
            }
            else
                for (int i = 0; i < siz; ++i)
                    cout << st[i] << " ";
            cout << "\n";
        }
        else if (s == "pop")
        {
            st.pop_back();
            --siz;
        }
    }
}
