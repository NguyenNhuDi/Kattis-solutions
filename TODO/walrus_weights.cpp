//Walrus Weights
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

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char * dp = new char[2000];

    int n;
    cin >> n;
    vi nums(n);
    FOR(i,0,n){
        cin >> nums[i];
    }

    FOR(i,0,n){
        int x = nums[i];

        FORD(i,1999,0){
            if(dp[i] == 1 && i + x < 2000){
                dp[i + x] = 1;
            }
        }
        dp[x] = 1;
    }
    int diff = INT32_MAX, out = 0;

    FOR(i,0,2000){
        if(dp[i]){
            int cDiff = abs(0x3e8 - i);

            if(cDiff <= diff){
                diff = cDiff;
                out = max(out,i);
            }
        }
    }
    cout << out << endl;
    delete[] dp;

    return 0;
}
