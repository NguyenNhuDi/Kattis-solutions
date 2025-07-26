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

    string input;

    vector<string> allInputs;

    while(cin >> input){
        allInputs.push_back(input);
    }

    if(allInputs[allInputs.size()-1] == "eh?"){
        cout << "Canadian!\n";
    }
    else{
        cout << "Imposter!\n";
    }
    
    return 0;
}
