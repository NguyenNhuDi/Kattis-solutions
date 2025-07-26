#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define fe(x,y) for(auto & x : y)
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;
typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    map<ll, ll> aNums;
    while(t--){
        ll n; cin >> n;

        FOR(i,0,n){
            string _; ll x; cin >> _ >> x;

            if(aNums.find(x) != aNums.end()){
                aNums[x]++;
            }
            else{
                aNums[x] = 1;
            }
        }
        ll out = 0;
        FOR(i,1,n+1){

            if(aNums.find(i) != aNums.end()){
                if(--aNums[i] <= 0) aNums.erase(i);
            }
            else{
                out += abs(i - aNums.begin()->first);
                if(--aNums.begin()->second <= 0) aNums.erase(aNums.begin());
            }
        }
        cout << out << endl;
    }

    return 0;
}
