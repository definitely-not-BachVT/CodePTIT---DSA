#include <bits/stdc++.h>
using namespace std;

struct Point
{
     double x, y;
};

bool cmpX(const Point &a, const Point &b)
{
     if (a.x != b.x)
          return a.x < b.x;
     return a.y < b.y;
}

bool cmpY(const Point &a, const Point &b)
{
     return a.y < b.y;
}

double distSq(const Point &p1, const Point &p2)
{
     return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Point strip[100005];
double closestPair(vector<Point> &a, int left, int right)
{

     // Bài toán nhỏ nhất
     if (right - left <= 3)
     {
          double min_dist = 1e18; // Vô cùng lớn
          for (int i = left; i <= right; ++i)
               for (int j = i + 1; j <= right; ++j)
                    min_dist = min(min_dist, distSq(a[i], a[j]));

          return min_dist;
     }

     // Chia để trị
     int mid = left + (right - left) / 2;
     Point midPoint = a[mid];

     double dl = closestPair(a, left, mid);
     double dr = closestPair(a, mid + 1, right);

     // Kết hợp các bài toán con
     double d = min(dl, dr);

     int stripCount = 0;
     for (int i = left; i <= right; i++)
          if (abs(a[i].x - midPoint.x) * abs(a[i].x - midPoint.x) < d)
               strip[stripCount++] = a[i];
     sort(strip, strip + stripCount, cmpY);

     for (int i = 0; i < stripCount; ++i)
          for (int j = i + 1; j < stripCount; ++j)
               if ((strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d)
                    d = min(d, distSq(strip[i], strip[j]));
               else
                    break;

     return d;
}

void solve()
{
     int n;
     cin >> n;

     vector<Point> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i].x >> a[i].y;

     sort(a.begin(), a.end(), cmpX);

     double ans = closestPair(a, 0, n - 1);
     cout << fixed << setprecision(6) << sqrt(ans) << "\n";
}

int main()
{
     // Tối ưu I/O cực đại
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int t;
     if (cin >> t)
     {
          while (t--)
          {
               solve();
          }
     }

     return 0;
}