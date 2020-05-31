#include<bits/stdc++.h>
using namespace std;
#define int long long 
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	multiset<int>m;
	int n;
	pair<int,int>a[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int tmp = (a[i].first-a[j].first)*(a[i].first-a[j].first) + (a[i].second-a[j].second)*(a[i].second-a[j].second);
			m.insert(tmp);
		}
	}
	int ans=0;
	int k=-1;
	for(int i:m){
		if(i==k)continue;
		else k=i;
		ans+=m.count(i)*(m.count(i)-1)/2;
	}
	cout<<ans<<'\n';
}