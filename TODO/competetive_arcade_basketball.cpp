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

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, p, m;

    map<string,ll> all;

    cin >> n >> p >> m;

    string name;
    FOR(i,0,n){
        cin >> name;
        all.insert(pair<string,ll>(name,0));
    }

    bool noWin = true;

    ll score;

    unordered_set<string> printed;
    FOR(i,0,m){
        cin >> name;
        cin >> score;
        all.at(name) += score;

        if(all.at(name) >= p && printed.count(name) != 1){
            cout << name << " wins!\n";
            printed.insert(name);
            noWin = false;
        }

    }


    if(noWin){
        cout << "No winner!\n";
    }

    return 0;
}
