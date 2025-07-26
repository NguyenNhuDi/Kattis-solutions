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
#define vl vector<long long>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;
typedef unsigned long long ll;

void make_dp(ll n, vl & dp){
    dp[1] = dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        if(dp[i] > 1000000000000000000) dp[i] = 1000000000000000001;
    }
}

string traverse(int x, vl & dp, ll k){
    if (x == 1) return "N";
    if (x == 2) return "A";


    if(k <= dp[x-2]) return traverse(x-2, dp, k);
    return traverse(x-1, dp, k - dp[x-2]);
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin >> n >> k;

    vl dp(n+1, -1);
    make_dp(n, dp);

    cout << traverse(n, dp, k) << endl;
    

    return 0;
}