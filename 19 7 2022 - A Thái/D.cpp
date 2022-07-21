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

int n,m,k;


signed main(){
	
	cin>>n>>m>>k;
	
	int cv = (n + m) * 2;
	
	
	if((n * m) % 2 != (k) % 2)return cout<<0,0;
	for(int i = 1,x,y,u,v;i <= k;i++){
		cin>>x>>y>>u>>v;
		
		int dis = sqrt((x - u) * (x - u) + (y - v) * (y - v));
		
		cv += (dis) * 2;
	}
	
	cout<<(cv - (k + 1) * 4) / 2;
	
	
	
	
	
	
}