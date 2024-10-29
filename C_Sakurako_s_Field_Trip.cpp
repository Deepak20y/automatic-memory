#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

void solve() {
    int n;cin>>n;
 vector<int>arr(n+1);
 for(int i=1;i<=n;i++){
    cin>>arr[i];
 }
 
   int ans = 0;
   int p1 = 1 , p2 = n;
   while(p2-p1>1){
      int curr1 = (arr[p1+1]==arr[p1]) + (arr[p2]==arr[p2-1]);
      swap(arr[p1+1] , arr[p2-1]);
      int curr2 = (arr[p1+1]==arr[p1]) + (arr[p2]==arr[p2-1]);
      if(curr1<=curr2){
         swap(arr[p1+1] , arr[p2-1]);
      }    
      ans+=min(curr1 , curr2);
      p1++;p2--;
   }
   if(p2-p1==1 && arr[p2]==arr[p1]){
     ans++;
   }
    
   cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}