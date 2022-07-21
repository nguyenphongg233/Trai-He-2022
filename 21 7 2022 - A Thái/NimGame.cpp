#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;


int n;
int a[MAX];

set<ii> st;
int nim = 0;
int sum = 0;
signed main(){
	
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		st.insert({a[i],i});
		nim ^= a[i];
		sum += a[i];
	}
	

	
	if(nim == 0){
		cout<<0<<endl;
		goto stp;
	}else cout<<1<<endl;
	
	
	while(sum > 0){
	
		if(st.size() == 2){
			
			ii x = *st.rbegin();
			ii y = *st.begin();
			
			if(x.X > y.X){
				
				cout<<x.Y<<" "<<x.X - y.X<<endl;
				
				st.erase({x.X,x.Y});
				a[x.Y] -= x.X - y.X;
				sum -= x.X - y.X;
				st.insert({a[x.Y],x.Y});
				
				
				
			}else{
				
				cout<<y.Y<<" "<<y.X - y.X<<endl;
				
				st.erase({y.X,y.Y});
				a[y.Y] -= y.X - x.X;
				st.insert({a[y.Y],y.Y});
				sum -= y.X - x.X;
			}
			
		}else if(st.size() == 1){
			ii x = *st.begin();
			cout<<x.Y<<" "<<x.X<<"\n";
			sum = 0;
		}else{
			
			bool ok = 0;
			
			for(int i = 1;i <= n;i++){
				
				if(a[i] == 0)continue;
				
				int newnim = nim ^ a[i];
				
				if(newnim < a[i]){
					ok = 1;
					
					cout<<i<<" "<<a[i] - newnim<<endl;
					sum -= a[i] - newnim;
					st.erase({a[i],i});
					a[i] = newnim;
					st.insert({a[i],i});
					
					nim = 0;
					break;
				}
				
			}		
		}
		
		
		
		
		
		
		
		
		
		
		stp:;
		int x,y;
		cin>>x>>y;
		
		st.erase({a[x],x});
		nim ^= a[x];
		a[x] -= y;
		st.insert({a[x],x});
		nim ^= a[x];
		sum -= y;
		
		
	}
	
	
	
	
	
}