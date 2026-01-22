#include <bits/stdc++.h>
using namespace std;

bool snt(long long n)
{
	if (n == 2 || n == 3)
		return true;
	if (n < 2 || n % 3 == 0 || n % 2 == 0)
		return false;

	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

long long tongcs(long long n)
{
	long long ans = 0;
	while (n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

long long solve(long long n)
{
	if (snt(n))
		return tongcs(n);

	long long ans = 0;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			ans = ans + solve(i) + solve(n / i);
			if (i * i == n)
				ans -= solve(i);
		}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> a(10);
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	a.clear();
	cout << a.size() << " ";
}