#include<bits/stdc++.h>
using namespace std;
 #define MAXN 5000  
// #define MAXX 1000000  

vector<int>a;
 int b[2][2000000]; 


void solve() {
    int n;
    scanf("%d", &n);
  a.resize(n);
  
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(),a.end());

  
    memset(b, 0, sizeof(b));

    long long cnt = 0LL;

  
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {
            if(a[i]==a[j])
            cnt += 8LL*b[0][a[i] ^ a[j]];
            else
            {
                 cnt += 24LL*b[1][a[i] ^ a[j]];
                 cnt+=b[0][a[i]^a[j]];
                 
            }  
        }

        for (int j = i - 1; j >= 0; j--) {
             if(a[i]==a[j])
             b[0][a[i] ^ a[j]]++;
             else{
                  b[1][a[i] ^ a[j]]++;
                  
             }
        }
    }

     
    printf("%lld\n", cnt);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}

