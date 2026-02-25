#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<vector<ll>> graph;
vector<ll> depth, sub_size;
vector<bool> vis;
ll t = 1;
ll n,m,q,x,k,u,v;
vector<ll> arr;

void dfs(ll ver, ll par=-1) {
    sub_size[ver]++;
    for(auto& child : graph[ver]) {
        if(child == par) continue;
        depth[child] = depth[ver] + 1;
        dfs(child,ver);
        sub_size[ver] += sub_size[child];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cin >> t;
    while(t--) {
        cin >> n >> k;
        // arr.assign(n,0);
        // for(ll i=0; i<n; i++) cin >> arr[i];
        graph.assign(n+1,{});
        depth.assign(n+1,0);
        sub_size.assign(n+1,0);
        for(ll i=0; i<n-1; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        depth[1] = 0;
        dfs(1);
        vector<ll> values;
        for(ll i=1; i<=n; i++) {
            x = depth[i] - (sub_size[i] - 1);
            values.push_back(x);
        }
        sort(whole(values), greater<ll>());
        ll ans = 0;
        for(ll i=0; i<k; i++) {
            ans += values[i];
        }
        cout << ans << "\n";
    } 
    return 0;
}