#include <iostream>
#include <string>

using namespace std;

int n;

void f(string a, int b)
{
     if (a.length() == b)
     {
          if (a.back() == '2')
               return;

          bool c = false, d = false, e = false, g = false;
          for (char x : a)
          {
               if (x == '2')
                    c = true;
               if (x == '3')
                    d = true;
               if (x == '5')
                    e = true;
               if (x == '7')
                    g = true;
          }

          if (c && d && e && g)
          {
               cout << a << '\n';
          }
          return;
     }

     f(a + "2", b);
     f(a + "3", b);
     f(a + "5", b);
     f(a + "7", b);
}

int main()
{
     cin >> n;
     for (int i = 4; i <= n; i++)
          f("", i);
     return 0;
}