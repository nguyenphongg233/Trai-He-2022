#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,k,a[MAX];
int last = 0;
vi res;
vi sum;
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("winterfashion.inp")){
		freopen("winterfashion.inp","r",stdin);
		freopen("winterfashion.out","w",stdout);
	}
	cin>>n>>k;
	
	for(int i = 1;i <= n;i++)cin>>a[i];

	
	for(int i = 1;i <= n;i++){
		if(a[i] < 20)res.push_back(i);
	}
	
	int k_ = k - res.size();
	
	for(int i = 1;i < res.size();i++){
		
	
		sum.push_back(res[i] - res[i - 1] - 1);
	}
	
	
	if(k_ < 0)return cout<<-1,0;
	
	sort(sum.begin(),sum.end());
	
	int cnt = res.size() * 2;
	
	//cout<<cnt<<"\n";
	
	for(auto v : sum){
		
		if(k_ - v < 0)break;
		
		k_ -= v;
		cnt -= 2;
		
		
	}
	
	
	int last = res[res.size() - 1];
	if(n - last <= k_)cnt--;
	
	
	
	cout<<cnt;
	
	
	
}