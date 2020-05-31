#include<bits/stdc++.h>
using namespace std;
#define M 1000007
#define N 100010
#define int long long 
int dp[N];
main(){
	dp[0]=1,dp[1]=0,dp[2]=3;
	int t,n;
	cin>>t;
	for(int i=4;i<N;i+=2){
		dp[i]=(4*dp[i-2]-dp[i-4]+M)%M;
	}
	while(t--){
		cin>>n;
		if(n%2!=0)cout<<0<<"\n";
		else cout<<dp[n]<<"\n";
	}
}