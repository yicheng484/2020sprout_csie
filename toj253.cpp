#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define int long long 
#define M 1000000007
#define N 5000
int a[N],dp[N],pre[N],f[N];
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],dp[i]=1,f[i]=1;
	//dp[0]=1,f[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<=a[i]){
				if(dp[j]+1>dp[i]){
					f[i]=f[j];
					pre[i]=j;
					dp[i]=dp[j]+1;
				}else if(dp[j]+1==dp[i]){
					f[i]=(f[i]+f[j])%M;
					if(pre[i]>j)pre[i]=j;
				}
			}
		}
	}
	int ans=0,sum=0,index=0;
	for(int i=0;i<n;i++) 
		ans=max(ans,dp[i]);
	for(int i=0;i<n;i++){
		if(dp[i]==ans){
			sum=(sum+f[i])%M;	
		}
	}
	cout<<ans<<"\n"<<sum<<"\n";
	for(int i=0;i<n;i++){
		if(dp[i]==ans){
			index=i;
			break;
		}
	}
	stack<int>s;
	while(dp[index]>0){
		s.push(index);
		if(dp[index]==1)break;
		index = pre[index];
	}
	cout<<s.top()+1;s.pop();
	while(!s.empty()){
		cout<<" "<<s.top()+1;
		s.pop();
	}
	cout<<"\n";
}