#include<bits/stdc++.h>
using namespace std;
#define N 10000
pair<int,int>a[N];
main(){
	int n;
	while(cin>>n&&n){
		for(int i=0;i<n;i++)cin>>a[i].second>>a[i].first;
		sort(a,a+n);
		int eat=0,time=0;
		for(int i=n-1;i>=0;i--){
			time+=a[i].second;
			eat=max(eat,time+a[i].first);
		}
		cout<<eat<<"\n";
	}
}