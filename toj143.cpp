#include<bits/stdc++.h>
using namespace std;
#define N 100
#define INF 1e9
int a[N+10],dp[N+10][N+10],sum[N];
main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sum[0]=0,sum[1]=a[1];
		for(int i=2;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(int i=1;i<n;i++){
			for(int L=1,R=L+i;R<=n;L++,R++){
				dp[L][R]=INF;
				for(int j=L;j<R;j++){
					dp[L][R]=min(dp[L][R],dp[L][j]+dp[j+1][R]+sum[R]-sum[L-1]);
				}
			}
		}
		cout<<dp[1][n]<<"\n";
	}
}