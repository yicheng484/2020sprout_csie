#include<bits/stdc++.h>
using namespace std;
#define T 1000000
#define P(X) X/2
#define L(X) 2*X
#define R(X) 2*X+1
int heap[T];
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t,a,b,cur=0,tmp;
	cin>>t;
	while(t--){
		cin>>a;
		if(a==1){
			cin>>b;
			tmp=++cur;
			heap[tmp]=b;
			while(P(tmp)>=1&&heap[tmp]<heap[P(tmp)]){
				swap(heap[tmp],heap[P(tmp)]);
				tmp=P(tmp);
			}
		}else{
			if(cur==0)cout<<"empty!\n";
			else{
				cout<<heap[1]<<"\n";
				heap[1]=heap[cur];
				heap[cur]=0;
				cur--;
				tmp=1;
				while( (L(tmp)<=cur&&heap[L(tmp)]<heap[tmp]) || (R(tmp)<=cur&&heap[R(tmp)]<heap[tmp]) ){
					if(R(tmp)<=cur&&heap[R(tmp)]<heap[tmp]&&heap[R(tmp)]<heap[L(tmp)]){
						swap(heap[tmp],heap[R(tmp)]);
						tmp=R(tmp);
					}else{
						swap(heap[tmp],heap[L(tmp)]);
						tmp=L(tmp);
					}
				}
			}	
		}
	}
}