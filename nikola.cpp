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
typedef vector<ll> vll;
typedef vector<vll> vvll;


ll solve(vvll & dp, int jump, int pos, vll & costs){
    size_t n = costs.size();
    if (pos < 0 || pos >= n) return INT32_MAX;
    if (pos == n - 1) return costs[pos];
    if (dp[pos][jump] != INT32_MAX) return dp[pos][jump];

    return dp[pos][jump] = costs[pos] +  min(solve(dp, jump, pos - jump, costs), solve(dp, jump + 1, pos + jump + 1, costs));
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vvll dp(n, vll(n, INT32_MAX));
    vll costs(n);

    FOR(i, 0, n) cin >> costs[i];

    dp[0][0] = 0; 
    cout << solve(dp,1,1,costs) << endl;

    return 0;
}