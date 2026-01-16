#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> gray(int idx)
{
    if (idx == 1)
    {
        vector<string> a = {"0", "1"};
        return a;
    }

    vector<string> lst = gray(idx - 1);
    vector<string> curr;

    string tmp;
    for (string x : lst)
    {
        tmp = "0" + x;
        curr.push_back(tmp);
    }

    reverse(lst.begin(), lst.end());
    for (string x : lst)
    {
        tmp = "1" + x;
        curr.push_back(tmp);
    }

    return curr;
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
        cin >> n;

        vector<string> ans = gray(n);
        for (string x : ans)
            cout << x << " ";
        cout << "\n";
    }
}