#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<vector<ll>> graph;
vector<bool> vis;
vector<ll> dp;
ll t = 1;
ll n,m,q,x,k,u,v;
string s,s1,s2;
vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        arr.assign(n+1,0);
        for(ll i=1; i<=n; i++) cin >> arr[i];
        dp.assign(n+1,0);
        dp[0] = 1;
        for(ll i=1; i<=n; i++) {
            //if current element is the length of the prev segment
            if((i - arr[i] - 1) >= 0 && dp[i - arr[i] - 1]) {
                dp[i] = 1;
            }
            //if current element is the length of the next segment
            if((i + arr[i]) <= n && dp[i-1]) {
                dp[i + arr[i]] = 1;
            }
        }
        if(dp[n]) yes;
        else no;
    }
    return 0;
}