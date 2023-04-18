//Ocean's Anti-11
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

ull * dp = new ull[10001];

ull f(int n){
    if(n == 1){
        return 2;
    }
    if(n == 2){
        return 3;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    return dp[n] = (f(n - 1) % MOD  + f(n - 2) % MOD) % MOD;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n){
        int t;
        cin >> t;
        cout << f(t) << endl;
    }

    return 0;
}
