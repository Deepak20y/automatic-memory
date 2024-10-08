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
       int k;cin>>k;
       vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];
     
    
       
       // if current is the winning state then i want to give when the next is a losing stage

       vector<int>dp(k+2,2);

      for(int i=1;i<=k;i++)
      {
        for(int j=0;j<n;j++)
        {
               
               if(a[j]>i)continue;

               if(dp[i-a[j]]==2)dp[i]=1;

        }  
           

      }
    //  for(auto x:dp)cout<<x<<" ";cout<<endl;

       if(dp[k]==1)cout<<"First"<<endl;
       else cout<<"Second"<<endl;

       






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// // {
    
// // } // namespace name

// int main()
// {
//     int no_of_moves, no_of_stones;
//     cin >> no_of_moves >> no_of_stones;

//     vector <int> move(no_of_moves + 1);
//     for(int i = 1; i <= no_of_moves; i++)
//         cin >> move[i];

//     vector <int> winner(no_of_stones + 1, 2);
//     for(int i = 1; i <= no_of_stones; i++)
//     {
//         for(int j = 1; j <= no_of_moves; j++)
//         {
//             if(move[j] > i) continue;

//             if(winner[i - move[j]] == 2)
//                 winner[i] = 1;
//         }
//     }

//     cout << (winner[no_of_stones] == 1 ? "First\n" : "Second\n");
//     return 0;
// }