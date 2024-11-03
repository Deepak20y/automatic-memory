#include<iostream>
#define int long long
#define PII pair<int,int>

using namespace std;
int T,n,a[200005];
void solve(){
	cin>>n;
	int sum=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		sum+=a[i];
	}

	
	for(int i=0;i<n-1;++i){
		int aa=(sum+i)/n;
		int o=a[i]-aa;
      //  cout<<o<<" ";
		if(o>0){
			cout<<"No\n";
			return;
		}
		//else {
			a[i+1]+=o;
		//}
	}
	cout<<"Yes\n";
}
signed main() {
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}