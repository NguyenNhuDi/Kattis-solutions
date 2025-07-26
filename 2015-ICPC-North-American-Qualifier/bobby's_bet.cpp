#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;

int bi[11][11];

int binomial(int n, int k){
    return (k < 0 || k > n) ? 0 : bi[n][k];
}

void set_bi(){
    bi[0][0] = 1;
    FOR(n,1,11){
        FORE(k,0,n){
            bi[n][k] = binomial(n-1,k-1) + binomial(n-1,k);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    set_bi();

    double N, R, S, X, Y, W;

    cin >> N;

    FOR(i,0,N){
        cin >> R >> S >> X >> Y >> W;

        double cT = S - R + 1.0;
        double chance = cT / S;
        double below = 1 - chance;
        double win_chance = 0.0;
        double loose_chance = 0.0;
        FORE(i,X,Y){
            win_chance += binomial(Y,i) * pow(chance,i) * pow(below, Y-i);
        }
        loose_chance = 1 - win_chance;

        printf((win_chance * (W - 1) + loose_chance * -1) > 0 ? "yes\n" : "no\n");

    }

    return 0;
}
