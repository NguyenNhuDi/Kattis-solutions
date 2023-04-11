//undead or alive
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

    string input;

    getline(cin,input);

    bool a,d,c;
    a = d = c = false;

    for(const auto & x : input){
        if(x == ' '){
            c = false;
        }

        if(x == ':'){
            c = true;
        }

        if(c && x == ')'){
            a = true;
            c = false;
        }
        else if(c && x == '('){
            d = true;
            c = false;
        }
    }

    if(a && d){
        cout << "double agent\n";
    }
    else if(a){
        cout << "alive\n";
    }
    else if(d){
        cout << "undead\n";
    }
    else{
        cout << "machine\n";
    }

    return 0;
}
