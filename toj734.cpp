#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define int long long 
#define N 200000
#define INF 1e9
int d[N+10],vis[N+10];
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,m,a,b,w,ans=0;
	cin>>n>>m;
	vector<vector<pair<int,int> > >v(n+1); 
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		v[a].push_back({w,b});
		v[b].push_back({w,a});
	}
	for(int i=1;i<=n;i++)d[i]=INF;
	d[1]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,1});
	for(int i=0;i<n;i++){
		int n1=0,n2=0;
		n1=pq.top().first,n2=pq.top().second,pq.pop();
		while(vis[n2]!=0)n1=pq.top().first,n2=pq.top().second,pq.pop();
		vis[n2]=1;
		//cout<<n1<<" "<<n2<<"\n";
		ans+=n1;
		for(auto j:v[n2]){
			int x,y;//x weight y node
			tie(x,y)=j;
			if(vis[y])continue;
			if(d[y]>x){
				d[y]=x;
				pq.push({x,y});
			}
		}
	}
	cout<<ans<<"\n";
}