#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,a[MAX];
int nim = 0;

signed main(){
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		
		cin>>a[i];
		nim ^= a[i];
		
	}
	
	int cnt = 1;
	
	
	if(nim == 0)return cout<<0,0;
	for(int i = 1;i <= n;i++){
		
		int newnim = nim ^ a[i];
		if(newnim > a[i])continue;
		
		int up = 1;
		bool ok = 0;
		
		for(int j = 0;j < 63;j++){
			
			if(newnim >> j & 1){
				
				
				if(a[i] >> j & 1)continue;
				
				ok = 1;
				break;
			}else 
			
			if(!(newnim >> j & 1)){
				
				if(a[i] >> j & 1)continue;
				up = up << 1;
				up %= mod;
				
				
				
			}
			
			
		}
		
		if(ok)continue;
		
		
		cnt = cnt * up;
		cnt %= mod;
	}
	
	cout<<cnt % mod;
	
	
	
	
	
	
	
}