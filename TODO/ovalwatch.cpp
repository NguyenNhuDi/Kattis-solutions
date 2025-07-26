//ovalWatch
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>
#include<bitset>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int bSearch(int l, int r, int x, vi & arr){
    if(l >= r){
        return -1;
    }
    int m = (l + r)/2;

    if(arr[m] == x){
        return m;
    }
    else if(arr[m] > x){
        return bSearch(l, m, x, arr);
    }
    else{
        return bSearch(m+1,r,x,arr);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<vi> rungs(n);

    //build rungs
    FOR(i,0,k){
        int index, height;
        cin >> index >> height;
        rungs[index].push_back(height);
        rungs[index+1].push_back(height);
    }

    FOR(i,0,n){
        sort(rungs[i].begin(),rungs[i].end());
    }

    //Traverse the rungs
    FOR(i,0,n){
        int col = i;

        if(SIZE(rungs[col]) == 0){
            cout << col << " ";
            continue;
        }

        int row = 0;

        while(1){
            
            
            if(col != SIZE(rungs)-1){
                int next = bSearch(0,SIZE(rungs[col+1]),rungs[col][row],rungs[col+1]);
        
                //is it to the right? if not its to the left
                col = next >= 0 ? col+1 : col-1;
                row = next >= 0 ? next : bSearch(0,SIZE(rungs[col]),rungs[col+1][row],rungs[col]);
            }
            else{
                col--;
                row = bSearch(0,SIZE(rungs[col]),rungs[col+1][row],rungs[col]);
            }

            
            if(row == SIZE(rungs[col])-1){
                cout << col << " ";
                break;
            }
            row++;
            
        }
    }
    cout << endl;

    return 0;
}
