#include<bits/stdc++.h>
using namespace std;
#define N 100000
int f[N],b[N];
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,x,y,first=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i-1,b[i]=i+1;
	b[n]=-1;
	while(m--){
		cin>>x>>y;
		if(x==0){
			if(y==first){
				first=b[y];
				continue;
			}
			if(y!=first)b[f[y]]=b[y];
			if(b[y]!=-1)f[b[y]]=f[y];
		}else{
			if(y==first)continue;
			int a=b[y];
			if(a!=-1){
				f[a]=f[y];
			}
			b[y]=f[y];
			if(f[y]!=first){
				f[y]=f[f[y]];
				b[f[y]]=y;
			}else{
				first=y;
			}
			f[b[y]]=y;
			b[b[y]]=a;
		}
	}
	int now = first;
	while(now!=-1){
		cout<<now;
		if(b[now]!=-1)cout<<" ";
		else cout<<"\n";
		now=b[now];
	}

}