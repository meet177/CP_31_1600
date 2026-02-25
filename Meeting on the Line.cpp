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

bool check(ll minutes, vector<ll>& x, vector<ll>& t) {
    ll l = MINF, r = INF;
    for(ll i=0; i<x.size(); i++) {
        ll remT = minutes - t[i];
        if(remT < 0) return false;
        ll currL = x[i] - remT;
        ll currR = x[i] + remT;
        if(currL > r || currR < l) return false;
        l = max(currL,l);
        r = min(currR,r);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> x(n), t(n);
        for(ll i=0; i<n; i++) cin >> x[i];
        for(ll i=0; i<n; i++) cin >> t[i];
        ll lo = 0, hi = 1e14;
        //BS on minutes
        //FFFFTTTTTT
        while((hi - lo) > 1) {
            ll mid = (lo + hi)/2;
            if(check(mid,x,t)) {
                hi = mid;
            }else {
                lo = mid+1;
            }
        }
        ll min_minutes = INF;
        if(check(lo,x,t)) {
            min_minutes = lo;
        }else {
            min_minutes = hi;
        }
        ll l = MINF, r = INF;
        for(ll i=0; i<n; i++) {
            ll remT = min_minutes - t[i];
            l = max(l, x[i] - remT);
            r = min(r, x[i] + remT);
        }
        double ans = (l+r)/2.0;
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}