//Maximum Fix

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

    int n;
    cin >> n;

    vi rRot(n+1,-1);
    vi lRot(n+1,-1);


    FOR(i,0,n){
        int currNum; cin >> currNum;

        //check the the number needed to rotate left
        int leftRot = ((i + 1 - currNum) + n) % n;

        if(lRot[leftRot] != -1){
            lRot[leftRot]++;
        }
        else{
            lRot[leftRot] = 1;
        }

        //check the number needed to rotate right
        int rightRot = n - leftRot;
        if(rRot[rightRot] != -1){
            rRot[rightRot]++;
        }
        else{
            rRot[rightRot] = 1;
        }
    }
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    //check for the number that apears the most (right rotate)
    int maxi = -1;
    int out = INT32_MAX;
    FORE(i,1,n){
        if(rRot[i] > maxi){
            maxi = rRot[i];
            out = n - i;
        }
        else if(rRot[i] == maxi){
            out = min(out,n - i);
        }
    }

    //check for the number that apears the most (left rotate)
    FORE(i,1,n){
        if(lRot[i] > maxi){
            maxi = lRot[i];
            out = i;
        }
        else if(lRot[i] == maxi){
            out = min(out,i);
        }
    }
    cout << out << " " << maxi << endl;

    return 0;
}
