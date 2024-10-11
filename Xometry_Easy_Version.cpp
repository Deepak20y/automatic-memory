#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5000  
#define MAXX 1000000  

int a[MAXN];
int b[MAXX];  

void solve() {
    int n;
    scanf("%d", &n);

  
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

  
    memset(b, 0, sizeof(b));

    long long cnt = 0LL;

  
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt += b[a[i] ^ a[j]];  
        }

        for (int j = i - 1; j >= 0; j--) {
            b[a[i] ^ a[j]]++;
        }
    }

    cnt *= 24LL;  
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
