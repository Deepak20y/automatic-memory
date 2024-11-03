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
 bool ask(int a,int b)
 {
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();

    int p;cin>>p;
    return p;
 }


 void solve(){
       int n;cin>>n;

       vector<int>parent(n,0);
        int pc=1;

        int pt=0;

       for(int i=2;i<n;i++)
       { 

        if(ask(pc,i))
        {
             parent[i]=pc;
             
        }
        else{
            parent[i]=pt;
        }






       }





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