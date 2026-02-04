// Test mau khong dung

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        // Next Greater Element
        vector<int> right(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && a[i] >= a[st.top()])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        // Next Smaller Element
        vector<int> left(n, -1);
        stack<int> st2;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st2.empty() && a[i] <= a[st2.top()])
                st2.pop();
            if (!st2.empty())
                left[i] = st2.top();
            st2.push(i);
        }

        // Output
        for (int i = 0; i < n; ++i)
        {
            if (right[i] == -1 || left[right[i]] == -1)
                cout << "-1 ";
            else
                cout << a[left[right[i]]] << " ";
        }
        cout << "\n";
    }
}
