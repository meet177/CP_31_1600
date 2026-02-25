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

vector<ll> divisors(ll n) {
    vector<ll> divs;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i != n/i) divs.push_back(n/i);
        }
    }
    return divs;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        vector<ll> divs = divisors(n);
        sort(whole(divs));
        ll ans = 0;
        for(auto& k : divs) {
            bool poss = 1;
            //now we have only 1 m so we have to take overall gcd also because we have to ensure all segments of length k are identical
            ll tot_g = 0;
            for(ll i=0; i<k; i++) {
                ll g = 0;
                for(ll j=i+k; j<n; j+=k) {
                    //abs(a[j] - a[i]) will be the value of m for which i and j will be same
                    //we are taking gcd of all because that will ensure that all of the elements in curr seg will be identical
                    g = __gcd(g, abs(a[j] - a[i]));
                }
                if(g == 1) {
                    tot_g = 1;
                    break;
                }
                tot_g = __gcd(g, tot_g);
            }
            if(tot_g == 1) poss = 0;
            ans += poss;
        }
        cout << ans << "\n";
    }
    return 0;
}