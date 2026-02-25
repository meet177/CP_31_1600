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

vector<vector<int>> graph;
vector<int> color;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        graph.assign(n+1,{});
        color.assign(n+1,-1);
        bool poss = true;
        for(ll i=0; i<n; i++) {
            ll u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(graph[u].size() > 2 || graph[v].size() > 2 || u == v) poss = false;
        }
        for(ll i=1; i<=n; i++) {
            if(color[i] != -1) continue;
            color[i] = 0;
            queue<ll> q;
            q.push(i);
            while(!q.empty() && poss) {
                ll ver = q.front(); q.pop();
                for(auto& child : graph[ver]) {
                    if(color[child] == -1) {
                        color[child] = color[ver]^1;
                        q.push(child);
                    }else if(color[child] == color[ver]) {
                        poss = false;
                        break;
                    }
                }
            }
        }
        if(!poss) no;
        else yes;
    }
    return 0;
}