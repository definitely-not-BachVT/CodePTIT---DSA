#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> oddPos, evenPos;
    for (int i = 0; i < n; ++i)
    {
        if ((i + 1) % 2 == 1)
            oddPos.push_back(a[i]);
        else
            evenPos.push_back(a[i]);
    }

    sort(oddPos.begin(), oddPos.end());                         // tăng dần
    sort(evenPos.begin(), evenPos.end(), greater<long long>()); // giảm dần

    int iOdd = 0, iEven = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((i + 1) % 2)
            cout << oddPos[iOdd++] << " ";
        else
            cout << evenPos[iEven++] << " ";
    }

    return 0;
}
