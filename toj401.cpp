#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define X first
#define Y second
pii operator+(const pii&p1, const pii&p2){
	return {p1.X+p2.X,p1.Y+p2.Y};
}
pii operator-(const pii&p1, const pii&p2){
	return {p1.X-p2.X,p1.Y-p2.Y};
}
int operator*(const pii&p1, const pii&p2){
	return p1.X * p2.X + p1.Y * p2.Y;
}
int operator^(const pii&p1, const pii&p2){
	return p1.X * p2.Y - p1.Y * p2.X;
}
bool in_segment(pii p1,pii p2,pii q){
	return (((p1-q) ^ (p2-q)) == 0 && ((p1-q)*(p2-q))<=0);
}
int ori(pii p1,pii p2){
	if((p1 ^ p2 ) > 0 )return 1;
	else return -1;
}
bool bnana(pii p1,pii p2,pii q1,pii q2){
	if(in_segment(p1,p2,q1)||in_segment(p1,p2,q2)||in_segment(q1,q2,p1)||in_segment(q1,q2,p2)){
		return true;
	}else if(ori(q1-p1,q2-p1)*ori(q1-p2,q2-p2)==-1 && ori(p1-q1,p2-q1)*ori(p1-q2,p2-q2)==-1){
		return true;
	}else{
		return false;
	}
}
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	pii p1,p2,q1,q2;
	while(t--){
		cin>>p1.X>>p1.Y>>p2.X>>p2.Y>>q1.X>>q1.Y>>q2.X>>q2.Y;
		if(bnana(p1,p2,q1,q2))cout<<"Yes\n";
		else cout<<"No\n";
	}
}