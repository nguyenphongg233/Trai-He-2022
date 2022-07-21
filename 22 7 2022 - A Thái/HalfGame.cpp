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


int n;
int nim = 0;

int g(int u){
	
	if(u == 0)return 0;
	else if(u == 1)return 1;
	else if(u == 2)return 0;
	
	if(u & 1)return (u + 1) / 2;
	else return g(u - 1 - u / 2);
	
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	
	for(int i123 = 1;i123 <= 5;i123++){
		cin>>n;
		
		nim = 0;
		for(int i = 1,x;i <= n;i++){
			cin>>x;
			
			nim ^= g(x);
		}
		
		cout<<(nim ? "yes" : "no")<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}