#include<bits/stdc++.h>
using namespace std;
#define M 1000000
#define INF 1e9
#define N 100
int f[M+10];
int w[N+10],v[N+10];
main(){
	int t,n,m,sumv;
	cin>>t;
	while(t--){
		sumv=0;		
		f[0]=0;
		//memset(f,0,sizeof(f));
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
		for(int i=1;i<=n;i++)sumv+=v[i];
		for(int i=1;i<=sumv;i++)f[i]=INF;
		for(int i=1;i<=n;i++){
			for(int j=sumv;j>=0;j--){
				if(j<v[i])continue;
				f[j]=min(f[j],f[j-v[i]]+w[i]);
			}
		}
		for(int i=sumv;i>0;i--){
			if(f[i]<=m){
				cout<<i<<"\n";
				break;
			}
		}
		//for(int i=0;i<=sumv;i++)cout<<f[i]<<"\n";
	}
}