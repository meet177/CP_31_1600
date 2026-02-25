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

bool check(ll ind, vector<ll>& queries, vector<pair<ll,ll>>& segs, ll n) {
    vector<ll> ones(n,0);
    for(ll i=0; i<=ind; i++) ones[queries[i]] = 1;
    for(ll i=1; i<n; i++) ones[i] += ones[i-1];
    for(auto& seg : segs) {
        ll l = seg.first, r = seg.second;
        ll curr_ones = 0;
        if(l == 0) curr_ones = ones[r];
        else curr_ones = ones[r] - ones[l-1];
        ll needed = (r-l+1)/2 + 1;
        if(curr_ones >= needed) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        vector<pair<ll,ll>> segs;
        while(m--) {
            ll l,r;
            cin >> l >> r;
            --l; --r;
            segs.push_back({l,r});
        }
        ll q;
        cin >> q;
        vector<ll> queries;
        while(q--) {
            ll x;
            cin >> x;
            --x;
            queries.push_back(x);
        }

        //what we are doing is just binary search on ans that after this much changes do we able to get the desired beautiful segment or not
        ll lo = 0, hi = queries.size()-1;
        //FFFFTTTTTT
        while((hi - lo) > 1) {
            ll mid = lo + (hi - lo)/2;
            if(check(mid,queries,segs,n)) {
                hi = mid;
            }else {
                lo = mid+1;
            }
        }
        if(check(lo,queries,segs,n)) cout << (lo+1) << "\n";
        else if(check(hi,queries,segs,n)) cout << (hi+1) << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}