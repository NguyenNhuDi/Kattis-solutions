//Video Speedup
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
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n, p, k;
    cin >> n >> p >> k;
    double pTime = 0;
    double out = 0;
    FOR(i,0,n){
        double cTime; cin >> cTime;
        
        double eTime = cTime - pTime;
        double origin = eTime*(100 + i * p)/100;
        out += origin;
        pTime = cTime;

    }
    out += (k-pTime) * (100 + n * p)/100;
    printf("%.6lf",out);


    return 0;
}
