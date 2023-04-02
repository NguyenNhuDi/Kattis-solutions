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

    int N;
    cin >> N;

    FOR(i,0,N){
        string in1, in2;
        cin >> in1 >> in2;

        cout << in1 << endl;
        cout << in2 << endl;
        FOR(j,0,SIZE(in1)){
            if(in1[j] == in2[j]){
                cout << ".";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
        cout << endl;

    }
    

    return 0;
}
