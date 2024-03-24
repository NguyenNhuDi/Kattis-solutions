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
#include <iomanip>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define fe(x,y) for(auto & x : y)
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

double pi = M_PI;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    FOR(_,0,tc){
        int n, f; cin >> n >> f;

        vi pies(n);

        FOR(i,0,n) cin >> pies[i];

        double mini = 0, maxi = 10000 * 10000 * pi;

        while(abs(maxi - mini) > 0.0000001){
            double mid = (mini + maxi) / 2;
            
            int ppl = 0;

            FOR(i,0,n) ppl += (int)floor(pi * pies[i] * pies[i] / mid);

            if (ppl < f + 1) maxi = mid; 
            else mini = mid;

        }

        cout <<  fixed << setprecision(8) <<mini << endl;
        
    }
    

    return 0;
}