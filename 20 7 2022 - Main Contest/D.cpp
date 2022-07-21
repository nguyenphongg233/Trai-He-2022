#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 998244353;
const long long INF = 1e18;

using namespace std;

int sub,n,m,q;
struct querry{
	int u,v,l,r;
};

vector<querry> yu;

void sub1(){
	
	
	bool dd[15][15];
	
	memset(dd,0,sizeof dd);
	vii whoasked;
	
	for(int i = 0;i < q;i++){
		int u = yu[i].u;
		int v = yu[i].v;
		int l = yu[i].l;
		int r = yu[i].r;
		
		//cout<<u<<" "<<v<<" "<<l<<" "<<r<<"\n";
		for(int j = u;j <= v;j++){
			for(int z = l;z <= r;z++){
				
				if(!dd[j][z]){
					dd[j][z] = 1;
					whoasked.push_back({j,z});
				}
				
			}
		}
		
		int sum = INF;
		
		for(int i1 = 1;i1 <= n;i1++){
			for(int j = 1;j <= m;j++){
			
				
				
				int sut = 0;
				
				for(auto v : whoasked){
					sut += abs(i1 - v.X) + abs(j - v.Y);
					
				}
				sum = min(sum,sut);
			}
			
		}
		
		
		cout<<sum % mod<<" ";
	}
}
int L[MAX],R[MAX];
int cntl[MAX],cntr[MAX];

void sub2(){
	
	bool d[MAX];
	memset(d,0,sizeof d);
	//vii whoasked;
	for(int i = 0;i < q;i++){
		int u = yu[i].u;
		int v = yu[i].v;
		int l = yu[i].l;
		int r = yu[i].r;
		
		if(u == v && v == 1){
			for(int j = l;j <= r;j++){
				d[j] = 1;
			}
		}
		int sum = INF;
		
		L[0] = R[m + 1] = 0;
		cntl[0] = cntr[m + 1] = 0;
		for(int j = 1;j <= m;j++){
			L[j] = L[j - 1] + cntl[j - 1];
			cntl[j] = cntl[j - 1] + d[j];
		}
		for(int j = m;j >= 1;j--){
			R[j] = R[j + 1] + cntr[j + 1];
			cntr[j] = cntr[j + 1] + d[j];
		}
		
		for(int j = 1;j <= m;j++){
			
			//cout<<cntl[i]<<" "<<cntr[i]<<"\n";
			
			sum = min(sum,R[j] + L[j]);
		}
		
		
		cout<<sum % mod<<" ";
	}
	
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("balls.inp")){
		freopen("balls.inp","r",stdin);
		freopen("balls.out","w",stdout);
	}
	cin>>sub>>n>>m>>q;
	
	for(int i = 1,u,v,x,y;i <= q;i++){
		cin>>u>>v>>x>>y;
		yu.push_back({u,v,x,y});
		
	}
	
	if(sub == 1){
		
		sub1();
		
		return 0;
	}else if(sub <= 3){
		sub2();
		return 0;
	}
	
}