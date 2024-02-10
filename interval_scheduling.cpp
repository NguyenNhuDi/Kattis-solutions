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

typedef vector<pair<int,int>> vpii;

bool eFirst(pair<int, int> a, pair<int,int> b){
    return a.second < b.second;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vpii intervals(n);

    FOR(i,0,n){
        int l, r; cin >> l >> r;

        intervals[i] = {l,r};
    }

    sort(intervals.begin(), intervals.end(), eFirst);

    int out = 0;
    int r = -1;
    fe(x,intervals){
        if (x.first >= r){
            out++;
            r = x.second;
        }
    }

    cout << out << endl;

    return 0;
}