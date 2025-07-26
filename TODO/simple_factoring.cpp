//simple factoring

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

    FOR(i,0,n){
        double a, b, c;

        cin >> a >> b >> c;

        double d = (b * b) - (4 * a * c);
        d = sqrt(d);
        double e = floor(d);

        if(d == e){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}
