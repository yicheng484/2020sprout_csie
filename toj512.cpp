#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200000
int data[N];
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	stack<int>s;
	int n;
	cin>>n;
	int flag=1;
	for(int i=0;i<n;i++)cin>>data[i];
	for(int i=0;i<n;i++){
		if(data[i]<0){
			if(s.empty()||(!s.empty()&&s.top()+data[i] != 0)){
				flag=0;
			}else{
				s.pop();
			}
		}else{
			s.push(data[i]);
		}
	}
	if(flag&&s.empty())cout<<"weed\n";
	else cout<<"lose light light\n";
}