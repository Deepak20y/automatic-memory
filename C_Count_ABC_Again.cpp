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
int q;cin>>q;
string s;cin>>s;

int cnt=0;

for(int i=0;i<n-2;i++)
{
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')cnt++;
}

 while(q--)
 {
    int idx;cin>>idx;
    char c;cin>>c;

     idx--;
     if(s[idx]==c){cout<<cnt<<endl;continue;}
     else{

           if(idx+2<n&&s[idx]=='A'&&s[idx+1]=='B'&&s[idx+2]=='C')cnt--;
              if(idx+1<n&&idx-1>=0&&s[idx-1]=='A'&&s[idx]=='B'&&s[idx+1]=='C')cnt--;
               if(idx-2>=0&&s[idx-2]=='A'&&s[idx-1]=='B'&&s[idx]=='C')cnt--;
        s[idx]=c;
         if(c=='B')
         {
               if(idx+1<n&&idx-1>=0&&s[idx-1]=='A'&&s[idx]=='B'&&s[idx+1]=='C')cnt++;

         }
         else if(c=='A')
         { 
             if(idx+2<n&&s[idx]=='A'&&s[idx+1]=='B'&&s[idx+2]=='C')cnt++;

         }
         else{
            if(idx-2>=0&&s[idx-2]=='A'&&s[idx-1]=='B'&&s[idx]=='C')cnt++;
        
         }

         cout<<cnt<<endl;

     }


 }




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}