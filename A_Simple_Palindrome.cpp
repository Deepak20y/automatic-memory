#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

 void solve(){
       int n;cin>>n;

       vector<char>a{'a','e','i','o','u'};

string s="";
     int j=0;
     
     
     int m=n%5;
   int i=0;
     while(s.size()<n)
     {
        int p=n/5;
        while(p--)
        {
            s.push_back(a[i]);
        }
        if(m>0){s.push_back(a[i]);m--;}

   i++;
     }

     cout<<s<<endl;
 
    



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}