#include<bits/stdc++.h>
using namespace std;
#define int long long 
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t,n;
	cin>>t;
	int dig[10];
	while(t--){
		memset(dig,0,sizeof(dig));
		cin>>n;
		if(n==1){
			cout<<"1\n";
			continue;
		}
		for(int i=9;i>1;i--){
			while(!(n%i)){
				dig[i]++;
				n/=i;
			}
		}
		if(n!=1)cout<<"-1\n";
		else{
			string ans;
			for(int i=2;i<10;i++){
				while(dig[i]){
					ans+= i+'0';
					dig[i]--;
				}
			}
			cout<<ans<<"\n";
		}
	}
}