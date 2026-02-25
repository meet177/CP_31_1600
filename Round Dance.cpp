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

vector<unordered_set<ll>> graph;
vector<bool> vis;
ll t = 1;
ll n,x;
vector<ll> arr;

bool dfs(ll ver, ll par=-1) {
    vis[ver] = true;
    for(auto& child : graph[ver]) {
        if(child == par) continue;
        if(vis[child]) return true;
        if(dfs(child,ver)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        arr.assign(n+1,0);
        graph.assign(n+1,{});
        vis.assign(n+1,0);
        for(ll i=1; i<=n; i++) {
            cin >> arr[i];
            graph[i].insert(arr[i]);
            graph[arr[i]].insert(i);
        }
        ll cycles = 0, bamboos = 0;
        for(ll i=1; i<=n; i++) {
            if(vis[i]) continue;
            if(dfs(i)) cycles++;
            else bamboos++;
        }
        ll mini = cycles + min(bamboos,1LL);
        ll maxi = cycles + bamboos;
        cout << mini << " " << maxi << "\n";
    }
    return 0;
}