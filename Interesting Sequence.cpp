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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,x;
        cin >> n >> x;
        bool poss = 1;
        for(ll i=0; i<63; i++) {
            if(!((n >> i) & 1) && ((x >> i) & 1)) {
                poss = 0;
                break;
            }
        }
        if(!poss) minus;
        else {
            ll i = 62;
            while(i >= 0) {
                if(((n >> i) & 1) && !((x >> i) & 1)) {
                    break;
                }
                --i;
            }
            ll prev = i;
            if(prev >= 0 && (n >> (prev+1)) & 1) {
                poss = 0;
            }
            --i;
            while(i >= 0) {
                if((x >> i) & 1) {
                    poss = 0;
                    break;
                }
                --i;
            }
            if(!poss) minus;
            else {
                ll ans = 0;
                for(ll i=62; i>prev; i--) {
                    if((n >> i) & 1) {
                        ans |= (1LL << i);
                    }
                }
                if(prev >= 0) ans |= (1LL << (prev+1));
                cout << ans << "\n";
            }
        }
    }
    return 0;
}