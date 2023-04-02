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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;

    cin >> R >> C;

    char img[R][C];

    FOR(i,0,R){
        FOR(j,0,C){
            char input;
            cin >> input;
            img[i][j] = input;
        }
    }

    int frames = 1;


    FOR(i,0,C){
        bool flag = false;
        FOR(j,0,R){
            if(img[j][i] == '$'){
                flag = true;
            }
        }
        if(!flag){
            frames += 1;
            flag = false;
        }
    }

    cout << frames << endl;

    return 0;
}
