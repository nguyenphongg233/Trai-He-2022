#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int t;

string l,r;
int f[MAX][19][10];

int dp(int i, int r, int s){
    if (i==-1) return r==0;
    auto& ans = f[i][r][s];
    if (ans) return ans-1;
    for (int j = 0; j < 10; ++j)
        if ((s>>(30-j)%3&1)==0)
            ans = (ans+dp(i-1, (r*10+j)%19, (j==0&&s==0)?0:(1<<j%3|s) )) % mod;
    return ans++;
}

int calc(string R){
	
	 int ans = 0;
     reverse(R.begin(), R.end());
     for (int i = R.size(), s = 0, r = 0; i--; ){
            int x = R[i] - '0';
            for (int j = 0; j < x; ++j)
            if ((s>>(30-j)%3&1)==0)
                    ans = (ans+dp(i-1, (r*10+j)%19, (j==0&&s==0)?0:(1<<j%3|s) )) % mod;
            int j = x;
            if ((s>>(30-j)%3&1)==1) break;
            r = (r*10+j)%19, s = (j==0&&s==0)?0:(1<<j%3|s);
    }
    
    return ans;
	
}

void solve(string L, string R){
	 if (*min_element(R.begin(), R.end()) == '9'){//++R
            R = "1"+string(R.size(), '0');
        } else {
            for (int i = R.size(); i--; )
                if (R[i] != '9'){
                    ++R[i];
                    for (int j = i+1; j < R.size(); ++j) R[j] = 0;
                    break;
        }
     }
     
     cout<<(calc(R) - calc(L) + mod) % mod<<"\n";
}

signed main(){
	
	cin>>t;
	while(t--){
		cin>>l>>r;
		
		solve(l,r);
	}
	
	
	
}