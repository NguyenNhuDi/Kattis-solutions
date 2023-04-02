#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;
typedef long long ll;
ll all[ll(1e6 + 10)];
bool bSearch(ll a[], ll l, ll r, ll x){
    if (r >= l){
        int m = (l + r) /2;
        if (a[m] == x){
            return true;
        }
        else if(a[m] > x){
            return bSearch(a,l,m-1, x);
        }
        else{
            return bSearch(a,m+1,r,x);
        }
    }
    else{
        return false;
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,a,c,x_0;

    cin >> n >> m >> a >> c >> x_0;

    all[0] = ((a * x_0) + c) % m;

    for(ll i = 1; i <= n; i++){
        all[i]=(((a * all[i-1]) + c) % m);
    }
    ll counter = 0;
    ll r = n - 1;

    for(ll i = 0; i < n; i++){
        if(bSearch(all,0,r,all[i])){
            counter++;
        }

    }

    cout << counter <<"\n";


    return 0;
}
