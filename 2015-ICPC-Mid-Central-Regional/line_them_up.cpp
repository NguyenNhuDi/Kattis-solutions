//line them up

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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> all(n);

    FOR(i,0,n){
        cin >> all[i];
    }

    vector<string> copy(all.begin(),all.end());


    sort(copy.begin(),copy.end());

    if(all == copy){
        cout << "INCREASING\n";
        return 0;
    }

    sort(copy.begin(),copy.end(), greater<>());

    if(all == copy){
        cout << "DECREASING\n";
        return 0;
    }

    cout << "NEITHER\n";

    return 0;
}
