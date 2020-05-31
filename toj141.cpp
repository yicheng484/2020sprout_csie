#include<bits/stdc++.h>
using namespace std;
#define N 100000
int a[N+10],dp[N+10];
main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		dp[1]=a[1];dp[2]=a[2],dp[3]=a[1]+a[3];
		for(int i=4;i<=n;i++){
			dp[i]=max(dp[i-3],dp[i-2])+a[i];
		}
		cout<<max(dp[n-1],dp[n])<<"\n";
	}
}