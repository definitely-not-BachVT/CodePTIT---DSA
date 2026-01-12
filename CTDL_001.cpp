#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        swap(s[left], s[right]);
        ++left;
        --right;
    }

    return s;
}

int n;
vector<string> res;
void sinh(string s, int idx)
{
    if (idx == 0)
    {
        if (n % 2 == 0)
        {
            res.push_back(s + rev(s));
        }

        else
        {
            res.push_back(s + "0" + rev(s));
            res.push_back(s + "1" + rev(s));
        }
        return;
    }

    sinh(s + "0", idx - 1);
    sinh(s + "1", idx - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string x = "";

    sinh(x, n / 2);

    for (string x : res)
    {
        for (char c : x)
            cout << c << " ";
        cout << "\n";
    }
}