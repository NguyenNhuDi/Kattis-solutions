#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b)for(int i = b; i >= a; i--)

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int sum = 0;
    FOR(i,0,N){
        int temp;
        cin >> temp;
        if(temp < 0){
            sum -= temp;
        }
    }

    cout << sum << endl;
    

    return 0;
}
