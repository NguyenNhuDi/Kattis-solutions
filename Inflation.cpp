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
#define foreach(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<double> canSize(n);

    FOR(i,0,n) cin >> canSize[i];

    sort(canSize.begin(), canSize.end());
    
    double leastCapacity = 1e9;

    for(double i = 1; i <= n; i++){

        if (i < canSize[i-1]){
            cout << "impossible\n";
            return 0;
        }

        leastCapacity = min(leastCapacity, canSize[i-1]/i);
    }

    cout << leastCapacity << endl;


    return 0;
}
