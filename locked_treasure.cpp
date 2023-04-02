#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b)for(int i = b; i >= a; i--)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;
typedef unsigned long long ll;

ll choose(ll n,ll k){
    if (k == 0){ 
        return 1;
        }
    return (n * choose(n - 1, k - 1)) / k;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll cases,N,M;

    cin >> cases;
    FOR(i,0,cases){
        cin >> N >> M;

        cout << choose(N,M-1) << endl;
    }
    return 0;
}
