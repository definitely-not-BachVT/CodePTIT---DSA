#include <bits/stdc++.h>
using namespace std;

long long F[105], cnt = 0;
long long fibo(int n)
{
    ++cnt;
    if (F[n] != 0)
        return F[n];
    if (n < 2)
        return n;
    long long temp = fibo(n - 1) + fibo(n - 2);
    F[n] = temp;

    return F[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cnt = 0;
    cout << fibo(n) << "\n";
    cout << "So buoc la: " << cnt;
}