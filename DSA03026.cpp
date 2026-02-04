#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    if (S > 9 * N || (S == 0 && N > 1))
    {
        cout << "-1 -1";
        return 0;
    }

    int s = S;
    string mx = "";
    for (int i = 0; i < N; i++)
    {
        int digit = min(9, s);
        mx.push_back(char('0' + digit));
        s -= digit;
    }

    s = S;
    string mn = "";
    for (int i = 0; i < N; i++)
    {
        for (int d = (i == 0 ? 1 : 0); d <= 9; d++)
        {
            int remain = s - d;
            if (remain >= 0 && remain <= 9 * (N - i - 1))
            {
                mn.push_back(char('0' + d));
                s -= d;
                break;
            }
        }
    }

    cout << mn << " " << mx;
}
