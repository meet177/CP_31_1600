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
ll n,m,q,x,k,u,v;
vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cin >> t;
    while(t--) {
        cin >> n >> m;
        arr.assign(n,0);
        for(ll i=0; i<n; i++) cin >> arr[i];
        ll ans = 1;
        //if n <= m means O(n^2) will be 10^6 we can do it else 
        //see if we have more than m numbers so we will surely have two numbers which will have same remainder and when we make a pair of them difference of them will be 0 and hence product will result in zero
        if(n <= m) {
            for(ll i=0; i<n; i++) {
                for(ll j=i+1; j<n; j++) {
                    ans = (ans * abs(arr[i] - arr[j])) % m;
                }
            }
        }else {
            ans = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}