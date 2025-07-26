#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi rungs;
    
    int finalPos[n];

    FOR(i,0,m){
        int temp;
        cin >> temp;
        rungs.push_back(temp);
    }

    
    FOR(i,1,n+1){
        int currNum = i;
        int num = 0;

        FOR(j,0,m){
            num = rungs[j];
            if(currNum == num){
                currNum++;
            }
            else if(currNum - num == 1){
                currNum--;
            }

        }
        finalPos[--currNum] = i;
    }

    FOR(i,0,n){
        cout << finalPos[i] << endl;
    }

    return 0;
}
