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



int n, p[31];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    
	int ok = 1;
    while(n > 0){
    	int val = 0;
    	
    	
    	for(int i = 0; i < 31 && (ok <= 0 || n > (1 << i)); i++){
    		if(n % (1 << i) == 0 && (n/(1 << i)) % 2 == 1){
    			val = (1 << i);
    			break;
			}
		}
		
		cout << val << endl;
		n -= val;
		
		
		int bot; cin >> bot;
		n -= bot;
		ok--;
		
	}
    
    return 0;
}