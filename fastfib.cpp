#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007LL;
map<long long, long long> F;
long long f(long long n)
{
    if (F.count(n))
        return F[n];
    long long k = n / 2;
    if (n % 2 == 0)
    {
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    }
    else
    {
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}
main()
{
    long long n;
    F[0] = F[1] = 1;
    while (cin >> n)
        cout << (n == 0 ? 0 : f(n - 1)) << endl;
}
