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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<m; i++) cin >> b[i];
        //whenever something is involved with +,- just try to use this property of gcd
        //gcd(x,y) = gcd(x-y,y)
        //this holds for more arguments also
        //gcd(x,y,z,t,.....) = gcd(x-y,y,z,t,....)
        //gcd(a1+bj,a2+bj,a3+bj,...) = gcd(a1+bj,a2-a1,a3-a1,...)
        //G = gcd(a2-a1,a3-a1,...) then ans = gcd(a1+bj,G) for every j
        //by deleting a1+bj from every argument except first
        ll G = 0;
        for(ll i=1; i<n; i++) {
            G = __gcd(G, abs(a[i] - a[0]));
        }
        for(ll i=0; i<m; i++) {
            ll g = __gcd(a[0]+b[i], G);
            cout << g << " ";
        }
        cout << "\n";
    }
    return 0;
}