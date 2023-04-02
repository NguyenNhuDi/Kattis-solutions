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

    int set = 1;
    cin >> n;
    while(n != 0){

        string input;
        vector<string> output;
        
        vector<string> allInput;

        FOR(i,0,n){
            cin >> input;
            allInput.push_back(input);
            output.push_back(input);
        }
      
        int diff = 0;

        for(int i = 0; i < n; i++){
            if(!(i%2)){
                output[i - diff] = allInput[i];
                
            }
            else{
                output[n-1-diff] = allInput[i];
                diff++;
            }
        }
        cout << "SET " << set << endl;
        FOR(i,0,n){
            cout << output[i] << endl;
        }
        set++;

        cin >> n;

    }

    



    return 0;
}
