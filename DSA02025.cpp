#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int mi = INT_MAX;
    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        vector<int> mark1(26, 0), mark2(26, 0);
        for (char c : a[i])
            mark1[c - 'A']++;
        for (char c : a[i - 1])
            mark2[c - 'A']++;

        for (int j = 0; j < 26; ++j)
            if (mark1[j] && mark2[j])
                ++cnt;
    }
    mi = min(mi, cnt);

    sort(a.begin(), a.end());
    do
    {
        cnt = 0;
        for (int i = 1; i < n; ++i)
        {

            vector<int> mark1(26, 0), mark2(26, 0);
            for (char c : a[i])
                mark1[c - 'A']++;
            for (char c : a[i - 1])
                mark2[c - 'A']++;

            for (int j = 0; j < 26; ++j)
                if (mark1[j] && mark2[j])
                    ++cnt;

            if (cnt >= mi)
                break;
        }
        mi = min(mi, cnt);
    } while (next_permutation(a.begin(), a.end()));

    cout << mi;
}