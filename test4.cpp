#include <stdio.h>
#include <climits>
double max(double a, double b)
{
     if (a > b)
          return a;
     else
          return b;
}

double min(double a, double b)
{
     if (a > b)
          return b;
     else
          return a;
}

int main()
{

     int n, k;
     scanf("%d %d", &n, &k);

     double a[n];
     double mi = LLONG_MAX, mx = LLONG_MIN;

     for (int i = 0; i < n; ++i)
     {
          scanf("%lf", &a[i]);
          mx = max(mx, a[i]);
          mi = min(mi, a[i]);
     }

     double alpha = 1.0 - k / 100.0;

     double low = mi, high = mx;
     while (high - low > 1e-7)
     {
          double mid = (low + high) / 2.0;
          double du = 0.0, thieu = 0.0;

          for (int j = 0; j < n; ++j)
          {
               if (a[j] > mid)
                    du = du + a[j] - mid;
               else
                    thieu = thieu + mid - a[j];
          }

          if (alpha * du >= thieu)
               low = mid;
          else
               high = mid;
     }

     printf("%.6lf", low);
}
