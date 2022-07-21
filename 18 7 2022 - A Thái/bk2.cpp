#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5000 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n, k, nxt[MAX][2];
int f[MAX][MAX][2];
char s[MAX];


int dp(int i, int d, int ok){

    int &r = f[i][d][ok];
    if (r != -1) return r;

    r = d==0 && ok;

    if (d < k && nxt[i][0] != -1) r += dp(nxt[i][0] + 1, d+1, ok || d+1==k);
    if (d > 0 && nxt[i][1] != -1) r += dp(nxt[i][1] + 1, d-1, ok);

    return r %= mod;
}


signed main(){
	
	cin>>k>>s;
	
	n = strlen(s);
	
	nxt[n][0] = nxt[n][1] = -1;
    for (int i = n; i--; ){
        if (s[i] == '('){
            nxt[i][0] = i;
            nxt[i][1] = nxt[i+1][1];
        } else {
            nxt[i][1] = i;
            nxt[i][0] = nxt[i+1][0];
        }
    }
    memset(f,255,sizeof(f));
    cout << dp(0, 0, 0);
	
	
	
	
}