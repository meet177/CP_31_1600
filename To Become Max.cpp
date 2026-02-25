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

bool canMake(ll val, ll remOps, ll index, vector<ll>& a) {
    //check for valid index
    if(index == a.size()) return false;
    //if a[ind] >= val means we have achieved what we need
    if(a[index] >= val) return true;
    ll neededOps = val - a[index];
    if(neededOps > remOps) return false;
    //we will have val at ind only when we have val-1 at index+1, so check it 
    //we have done with neededOps at this ind so we are remained with remOps-needOps
    return canMake(val-1, remOps-neededOps, index+1, a);
}

ll getMaxForIdx(ll index, ll remOps, vector<ll>& a) {
    //we can't change the last value as there is no suffix
    if(index == a.size() - 1) return a[index];
    //lo is already a[ind] and hi can be at most a[ind] + ops
    ll lo = a[index], hi = a[index] + remOps;
    while((hi - lo) > 1) {
        ll mid = lo + (hi - lo)/2;
        if(canMake(mid,remOps,index,a)) {
            lo = mid;
        }else {
            hi = mid-1;
        }
    }
    if(canMake(hi,remOps,index,a)) return hi;
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll ans = 0;
        //if we consider the ith element will be the maximum after k ops
        for(ll i=0; i<n; i++) {
            ans = max(ans, getMaxForIdx(i,k,a));
        }
        cout << ans << "\n";
    }
    return 0;
}