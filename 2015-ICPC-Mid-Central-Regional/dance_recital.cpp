//Dance Recital

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

int checkSame(string a, string b){

    unordered_set<char> sames;

    string combine = a + b;

    return SIZE(combine) - SIZE(unordered_set<char>(combine.begin(),combine.end()));
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    string all[n];
    int perm[n];
    int cost[n][n];

    if(n == 0){
        cout << 0 << endl;
        return 0;
    }

    FOR(i,0,n){
        cin >> all[i];
        perm[i] = i;
    }

    FOR(i,0,n){
        FOR(j,i,n){
            cost[i][j] = cost[j][i] = checkSame(all[i],all[j]);
        }
    }

    int qc = 5000;

    do{
        int curr = 0;
        FOR(i,0,n-1){
            curr += cost[perm[i]][perm[i+1]];
        }
        qc = min(qc,curr);
    }
    while(next_permutation(perm,perm+n));


    cout << qc << endl;


    return 0;
}
