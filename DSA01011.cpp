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
        int test;
        string s;

        cin >> test >> s;
        if (next_permutation(s.begin(), s.end()))
            cout << test << " " << s << "\n";
        else
            cout << test << " " << "BIGGEST\n";
    }
}