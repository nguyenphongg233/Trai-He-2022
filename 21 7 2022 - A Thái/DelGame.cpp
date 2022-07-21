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

int n,m,k;
vi adj[MAX];
bool d[MAX];

int bfs(int u){
	
	deque<int> h;
	h.push_back(u);
	d[u] = 1;
	int up2 = 0;
	int cnt = 0;
	while(!h.empty()){
		int up = h.front();
		up2++;
		h.pop_front();
		cnt += adj[up].size();
		
		for(auto v : adj[up]){
			if(!d[v]){
				d[v] = 1;
				h.push_back(v);
			}
		}
	}
	

	return cnt/2 - up2 + 1;
	
}
signed main(){
	
	for(int ert = 1;ert < 5;ert++){
		
		cin>>n>>m>>k;
		for(int i = 1,u,v;i <= m;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(d,0,sizeof d);
		int cnt = 0;
		
		int nim = 0;
		
		for(int i = 1;i <= n;i++){
			if(!d[i]){
				nim ^= (bfs(i) % (k + 1));
			}
		}
		
		//cout<<nim<<" ";
		cout<<(nim > 0)<<"\n";
		
		
		
		
		
		for(int i = 1;i <= n;i++)adj[i].clear();
		
	}
	
	
	
}