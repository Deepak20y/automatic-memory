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
       

     int n,k,m,t;
     cin>>n>>k>>m>>t;
     int sz=n;
    // cout<<n<<" "<<k<<" "<<m<<" "<<t<<endl;
     while(t--)
     {
          
        int a,b;
        cin>>a>>b;

        if(a==0)
        {
             if(k<=b)n=b;
             else{

                k=k-b;
                n=n-b;
             }
        }
        else{
              
             if(k<b)n++;
             else{
                 k++;
                 n++;

             }


        }

        cout<<n<<" "<<k<<endl;


     }





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}