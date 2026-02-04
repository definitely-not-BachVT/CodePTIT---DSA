#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> p;
string s;
void sinh(string x, int idx)
{
    if (idx == n)
    {
        p.push_back(x);
        return;
    }

    string notad = x;
    string ad = x;
    ad.push_back(s[idx]);

    sinh(ad, idx + 1);
    sinh(notad, idx + 1);
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
        p.clear();

        cin >> n;
        string tmp = "";
        cin >> s;
        sinh(tmp, 0);

        sort(p.begin(), p.end());
        int sz = p.size();

        for (int i = 1; i < sz; ++i)
            cout << p[i] << " ";
        cout << "\n";
    }
}