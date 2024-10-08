#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
ll ans;
bool check(int n, ll k, vector<ll> &a, ll mid)
{
    queue<int> q;
    ll cnt = 0LL;
    ll sum = 0LL;
    for (int i = 0; i < n; i++)
    {
        //  cout<<cnt<<endl;
        if (q.size() == 0)
        {    sum=0LL;
            cnt += a[i] / mid;
            if (a[i] % mid != 0)
            {
                q.push(a[i] % mid);
                sum += (a[i] % mid);
            }

        }
        else
        {

            if (sum + a[i] >= mid)
            {   
                ll sp=a[i]-(mid-sum);
                cnt++;
                while (!q.empty())
                    q.pop();
                    sum=0LL;

                cnt += sp / mid;
                if (a[i] % mid != 0)
                {
                    q.push(a[i] % mid);
                    sum += a[i] % mid;
                }
            }
            else {q.push(a[i]);sum+=a[i];}
        }

        if (q.size() ==2)
        {
            sum -= q.front();
            q.pop();
        }

        // while(!q.empty()&&q.front()==0)q.pop();
        // if(mid==4)
        // {cout<<q.front()<<endl;cout<<sum<<" "<<cnt<<endl;}
    }

//  if(mid==4)
//  cout<<cnt<<' '<<k<<" "<<mid<<endl;
     
    if (cnt >= k)
       {ans=max(ans,mid); return true;}
    else
        return false;
}

void solve()
{

    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0LL;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    ll low = 1LL;
    ll high = sum / k + 1e5;
    ll mid;
    //  for(auto &x:a)cout<<x<<" ";cout<<endl;
   // cout<<low<<" "<<high<<endl;
    for (int i = 0; i < 70 && high >= low; i++)
    {
        if (high >= low)
        {
            mid = (high + low) / 2LL;

            if (check(n, k, a, mid))
                low = mid;
            else
                high = mid;
        }
    }
    //cout<<ans<<" "<<k<<endl;
    if(!check(n, k, a,1))cout<<0<<endl;
    else cout << mid*k<< '\n';

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
    return 0;
}