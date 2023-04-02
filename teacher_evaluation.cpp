//Teacher Evaluation

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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n, goal,t, sum;
    cin >> n >> goal;
    sum  = 0;

    FOR(i,0,n){
        cin >> t;
        sum += t;
    }
    if(goal < (sum/n)){
        cout << "impossible\n";
        return 0;
    }
    else if(goal == (sum / n)){
        cout << 0 << endl;
        return 0;
    }
    else if(goal == 100 && (sum/n) < 100){
        cout << "impossible\n";
        return 0;
    }

    double x;

    double out = 1;

    while(pow(10,0)){
        x = (goal*(n + out)) - sum;
        x /= out;

        if(x > 100){
            out++;
        }
        else{
            cout << out << endl;
            break;
        }
    }

    return 0;
}
