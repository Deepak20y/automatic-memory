#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
vector<int> adj[20005];

void fill()
{

  for (int i = 1; i <= 20000; i++)
  {
    for (int j = i; j <= 20000; j += i)
    {
      adj[i].push_back(j);
    }
  }
}

void solve()
{

  int ans = 1e9;

  int a, b, c;
  cin >> a >> b >> c;
 // cout<<a<<" "<<b<<" "<<c<<endl;
  

  vector<int>ans2(3,-1);



  for (int i = 1; i <=c+c; i++)
  {

    for (int j = 0; j < adj[i].size() && adj[i][j] <=c+c; j++)
    {

      int p = adj[i][j];
     
      int st = c % p;
      if (c % p == 0)
      {
        int mp = abs(a - i) + abs(p - b);
        if (ans > mp)
        {
          ans2[0] = i;
          ans2[1] = p;
          ans2[2] = c;
          
          ans = mp;
        }
      }
      else
      { 
       
        int mp = abs(a - i) + abs(p - b) + p-st;
        if (ans > mp)
        {
          ans2[0] = i;
          ans2[1] = p;
          ans2[2] = c + p-st;
         
          ans = mp;
        }
         if(c/p>0)
        {mp = abs(a - i) + abs(p - b) + st;
        if (ans > mp)
        {
          ans2[0] = i;
          ans2[1] = p;
          ans2[2] = c - st;
          ans = mp;
        }

        }
      }
    }
  }
  cout << ans << endl;
  for(int i=0;i<3;i++)cout<<ans2[i]<<" ";
  cout << endl;

  return;
}

int main()
{
  fill();
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  cin >> t;
  // t=1;
  while (t--)
    solve();
  return 0;
}