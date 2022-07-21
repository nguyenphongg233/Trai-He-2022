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

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int iop = 1;iop <= 5;iop++){
		int n,m,k;
		cin>>n>>m>>k;
		
		int nim = 0;
		
		for(int j = 1,x,y;j <= k;j++){
			cin>>x>>y;
			nim ^= (x - 1) ^ (y - 1);
			
		}
		
		
		cout<<((nim > 0) ? "YES" : "NO")<<"\n";
	}
	
	
	
	
}