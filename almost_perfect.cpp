// almost perfect
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define fe(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

int sum(vi &arr){
    int out = 0;
    fe(x, arr) out += x;
    return out;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int currNum;

    while (cin >> currNum){
        vi divisors;

        int sqrt_n = int(sqrt(currNum));

        FOR(i, 1, sqrt_n + 1){
            if (currNum % i == 0){
            
                divisors.push_back(i);

                if (i != currNum / i) divisors.push_back(currNum / i);
            }
        }

        int s = sum(divisors) - currNum;

        int diff = s - currNum;
        diff = diff > 0 ? diff : -1 * diff;


        if (currNum == s){
            cout << currNum << " perfect\n";
        }
        else if(diff <= 2){
            cout << currNum << " almost perfect\n";
        }
        else{
            cout << currNum << " not perfect\n";
        }

    }

    return 0;
}
