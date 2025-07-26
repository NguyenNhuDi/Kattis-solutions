//Beast Bullies
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

    ll n;
    cin >> n;

    vector<ll> all(n);

    FOR(i,0,n){
        cin >> all[i];
    }

    sort(all.begin(),all.end(),greater<>());

    ll highest = all[0];
    ll sum = 0;
    ll alive = 1;
    ll count = 0;
    FOR(i,1,n){
        sum += all[i];
        count++;
        if(sum >= highest){
            alive += count;
            count = 0;
            highest += sum;
            sum = 0;
        }
    }

    cout << alive << endl;

    return 0;
}
