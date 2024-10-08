#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
int n;
int a[N],b[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);

  
	if(n%2)cout<<b[n/2+1]-a[n/2+1]+1;
	else cout<<b[n/2+1]+b[n/2]-a[n/2]-a[n/2+1]+1;
	return 0;
}
