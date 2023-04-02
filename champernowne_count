//Champernowne Count

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>
#include<string>

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

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n, k;

    cin >> n >> k;

    ll pCount = 1;
    ll currPow = 10;

    ll num = 0;
    ll prev = 0;

    ll out = 0;
    FORE(i,1,n){
        if(i >= currPow){
            currPow *= 10;
            pCount++;
        }
        ll temp = pow(10,pCount);
        temp %= k;

        ll temp2 = prev % k;

        num = temp2 * temp;

        temp = i % k;

        num += temp;

        if(num % k == 0){
            out++;
        }

        prev = num;
        
    }

    cout << out << endl;


    return 0;
}
