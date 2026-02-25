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
vector<bool> vis;
ll t = 1;
ll n,x1, x2;
vector<ll> arr;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cin >> t;
    while(t--) {
        cin >> n;
        ll i = 1, j = n;
        vector<ll> ans(n+1);
        while(i < j) {
            cout << "? " << i << " " << j << "\n";
            cin >> x1;
            cout << "? " << j << " " << i << "\n";
            cin >> x2;
            if(x1 > x2) {
                ans[i++] = x1; 
            }else {
                ans[j--] = x2;
            }
        }
        ans[i] = n;
        cout << "! ";
        for(ll i=1; i<=n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}