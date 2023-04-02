#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b)for(int i = b; i >= a; i--)
#define SIZE(x) x.size()

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    FOR(i,0,N){
        float l, r, ans;
        cin >> l >> r >> ans;

        if(l + r == ans || l - r == ans || r - l == ans || l * r == ans || l / r == ans || r / l == ans){
            cout << "Possible\n";
        }
        else{
            cout << "Impossible\n";
        }
    }
    

    return 0;
}
