#include<bits/stdc++.h>
using namespace std;
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t,n,a;
	cin>>t;
	int end=0,ans=1,sig=1;//1 odd 0 even
	while(t--){
		end=0,ans=1,sig=1;
		cin>>n;
		cin>>end,n--;
		while(n--){
			cin>>a;
			if((sig&&a<end) || (!sig&&a>end))ans++,sig=!sig;//success
			end=a;
		}
		if(!sig)ans--;
		cout<<ans<<"\n";
	}
}