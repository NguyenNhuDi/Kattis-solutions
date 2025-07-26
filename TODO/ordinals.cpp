//ordinals
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
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;

vector<string> dp(9);

void makeOrdinal(){
    dp[0] = "{}";

    FOR(i,0,9){
        string curr = "{";
        FOR(j,0,i){

            curr += dp[j];
        
            if(j != i - 1){
                curr += ',';
            }
        }
        curr += '}';
        dp[i] = curr;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    makeOrdinal();

    int n;
    cin >> n;
    cout << dp[n] << endl;

    return 0;
}
