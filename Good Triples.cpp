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
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 1;
        while(n) {
            ll dig = n % 10;
            //how can we make a sum of (a+b+c = n) ways will be (n+2)C2 = (n+2)*(n+1)/2
            //here what we are doing is that every digit is come like this so at the end the sum will be n and digsum will be also digsum(n) because we have considered every dig differently
            ans *= ((dig+2)*(dig+1))/2;
            n /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}