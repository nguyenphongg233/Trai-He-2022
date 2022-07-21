#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9 + 1e5;

using namespace std;

int n,m;

struct kru{
	int u,v,tt;
	int id;
};

int maxx = -INF;
int minx = INF;

vector<kru> unknow;

int par[MAX];
int res[MAX];

int find(int u){
	if(u == par[u])return u;
	else return par[u] = find(par[u]);
	
}

bool ok[MAX];

bool cmp(kru a,kru b){
	
	if(a.tt == b.tt)return 1;
	else return a.tt > b.tt;
	
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++)par[i] = i;
	int cnt = 0;
	for(int i = 1,u,v,lg,tt;i <= m;i++){
		cin>>u>>v;
		string s;
		cin>>s>>tt;
		
		if(s == "?"){
			
			unknow.push_back({u,v,tt,++cnt});
			continue;
			
		}
		
		
		int nuh = stoi(s);
		
		maxx = max(maxx,nuh);
		minx = min(minx,nuh);
		
		int x = find(u);
		int y = find(v);
		
		par[u] = v;
		ok[u] = 1;
		ok[v] = 1;
		
	}
	
	
	//cout<<maxx<<" "<<minx<<"\n";
	
	sort(unknow.begin(),unknow.end(),cmp);
	
	for(auto e : unknow){
		
		int u = e.u;
		int v = e.v;
		int tt = e.tt;
		int id = e.id;
		
		if(tt == 1)
		
		
		
		
	}
	for(int i = 1;i <= cnt;i++)cout<<res[i]<<" ";
}