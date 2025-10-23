//contigency planning

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
#define ll long long

using namespace std;

ll fac(ll n){
    if(n <= 1){
        return 1;
    }

    return n * fac(n - 1);
}

ll perm(ll n, ll r){
    return fac(n) / fac(n -r);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if(n >= 12){
        cout << "JUST RUN!!\n";
        return 0;
    }

    ll out = 0;
    FORE(i,1,n){
        out += perm(n,i);
    }
    cout << out << endl;

    return 0;
}
