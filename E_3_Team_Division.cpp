#include<bits/stdc++.h>
using namespace std;
#define y1 y101
#define ff first
#define ss second
#define den(a) cout << #a << " = " << a << "\n";
#define deg(a) cout << #a << " = " << a << " ";
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
const int N = 2e5 + 10, M = 2e5 + 10, mod = 1e9 + 7, inf = 0x3f3f3f3f, mox = 21817;
ll n, m;
int a[N];
string s;
bool st[N];



int f[110][510][510];

void solve() {
    cin >> n;
    memset(f, 0x3f, sizeof f);
    f[0][0][0] = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        sum += b;
        for(int j = 0; j <= 500; j++) {
            for(int k = 0; k <= 500; k++) {
                if(a == 1) {
                    if(j >= b) f[i][j][k] = min(f[i][j][k], f[i - 1][j - b][k]);
                    if(k >= b) {
                        f[i][j][k] = min(f[i][j][k], f[i - 1][j][k - b] + 1);
                    }
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + 1);
                } else if(a == 2) {
                    if(j >= b) f[i][j][k] = min(f[i][j][k], f[i - 1][j - b][k] + 1);
                    if(k >= b) {
                        f[i][j][k] = min(f[i][j][k], f[i - 1][j][k - b]);
                    }
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + 1);

                } else {
                    if(j >= b) f[i][j][k] = min(f[i][j][k], f[i - 1][j - b][k] + 1);
                    if(k >= b) {
                        f[i][j][k] = min(f[i][j][k], f[i - 1][j][k - b] + 1);
                    }
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
                }
            }
        }

    }

    if(sum % 3) {
        cout << "-1\n";
        return ;
    }
    sum /= 3;
    int ans = f[n][sum][sum];
    if(ans == 0x3f3f3f3f) ans = -1;
    cout << ans << "\n";

}

int main() {
    int T = 1;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
