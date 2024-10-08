#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

void sol() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    double log3 = log(3);  
    

    for (int i = a; i <= b; i++) {
      
      int c = static_cast<int>(log(i) / log3 + 1e-9);

        ans += c + 1; 
       
        
    }
      int c = static_cast<int>(log(a) / log3 + 1e-9);

       ans+=(c+1);
     

    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test;
    cin >> test;
    while (test--)
        sol();
    
    return 0;
}