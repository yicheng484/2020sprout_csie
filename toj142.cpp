#include<bits/stdc++.h>
using namespace std;
#define N 1000
int a[N+10],dp[N+10];
main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		dp[1]=a[1];
		for(int i=2;i<=n;i++){
			int Max=0;
			for(int j=k;j<2*k&&i-j>0;j++){
				Max = max(Max,dp[i-j]);
			}
			dp[i]=Max+a[i];
		}
		int ans = 0 ;
		for(int i=0;i<k;i++)ans=max(ans,dp[n-i]);
		cout<<ans<<"\n";
	}
}