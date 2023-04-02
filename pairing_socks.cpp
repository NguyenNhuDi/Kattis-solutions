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

    int n;
    cin >> n;

    int socks[n*2];
    int sPile[n];

    FOR(i,0,n*2){
        int temp;
        cin >> temp;
        socks[i] = temp;

    }
    FOR(i,0,n){
        sPile[i] = 0;
    }

    int pIndex = 0;
    int moves = 0;
    bool flag = false;
    
    FOR(i,0,n*2){
        // cout << "socks: \n";
        // FOR(j,i,n*2){
        //     cout << socks[j];
        // }
        // cout << "\npile:\n";
        // FOR(j,0,n){
        //     cout << sPile[j];
        // }
        // cout << endl;

        if(sPile[0] == 0){
            sPile[0] = socks[i];
 
        }
        else{
            if(sPile[pIndex] == socks[i]){
                sPile[pIndex] = 0;
                if(pIndex > 0){
                    pIndex--;
                }
                
            }
            else{
                pIndex++;
                sPile[pIndex] = socks[i];
            }
        }

        moves++;
    }

    if(sPile[0] == 0){
        cout << moves << endl;
    }
    else{
        cout << "impossible\n";
    }




    return 0;
}
