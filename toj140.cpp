#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define M 1000007
int dp[N+10][3][3],ans[N+10];
main(){
	memset(ans,0,sizeof(ans));
	dp[1][0][0]=1,dp[1][1][1]=1,dp[1][2][2]=1,ans[1]=3;
	int t,n;
	cin>>t;
	for(int i=1;i<N;i++){
		for(int j=0;j<3;j++){
			dp[i+1][0][j]+=(dp[i][0][j]+dp[i][1][j]+dp[i][2][j])%M;
			dp[i+1][1][j]+=(dp[i][0][j]+dp[i][1][j])%M;
			dp[i+1][2][j]+=(dp[i][0][j]+dp[i][2][j])%M;
		}
		//dp[i+1][0][j]%=M,dp[i+1][1][j]%=M,dp[i+1][2][j]%=M;
		ans[i+1]=dp[i+1][0][0]+dp[i+1][0][1]+dp[i+1][0][2]+dp[i+1][1][0]+dp[i+1][1][1]+dp[i+1][2][0]+dp[i+1][2][2];
		ans[i+1]%=M;
	}
	while(t--){
		cin>>n;
		cout<<ans[n]<<"\n";
		//for(int i=1;i<15;i++)cout<<ans[i]<<"\n";
	}
} 