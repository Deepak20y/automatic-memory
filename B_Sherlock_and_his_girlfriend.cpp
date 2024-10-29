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
int n;
vector<bool> a;
vector<int> b;
void solve()
{

    cin >> n;
    a.resize(n + 5, 0);
     
     
     int maxp=1;
     n++;
  a.resize(n+3,false);
     for(int i=2;i<=n;i++)
     {
        if(a[i])continue;
        for(int j=2*i;j<=n;j+=i)a[j]=true;
     }

     for(int i=2;i<=n;i++)
     {
        if(!a[i]){b.push_back(1);}
        else {b.push_back(2);maxp=2;}
     }

cout<<maxp<<endl;
for(auto &x:b)cout<<x<<" ";cout<<endl;
    



    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}