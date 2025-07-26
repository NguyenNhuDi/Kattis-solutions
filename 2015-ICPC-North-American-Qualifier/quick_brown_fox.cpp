#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

unordered_map<int, char> toPrint;
unordered_map<char, int> indices;

void init(){

    toPrint.insert({0, 'a'});
    toPrint.insert({1, 'b'});
    toPrint.insert({2, 'c'});
    toPrint.insert({3, 'd'});
    toPrint.insert({4, 'e'});
    toPrint.insert({5, 'f'});
    toPrint.insert({6, 'g'});
    toPrint.insert({7, 'h'});
    toPrint.insert({8, 'i'});
    toPrint.insert({9, 'j'});
    toPrint.insert({10, 'k'});
    toPrint.insert({11, 'l'});
    toPrint.insert({12, 'm'});
    toPrint.insert({13, 'n'});
    toPrint.insert({14, 'o'});
    toPrint.insert({15, 'p'});
    toPrint.insert({16, 'q'});
    toPrint.insert({17, 'r'});
    toPrint.insert({18, 's'});
    toPrint.insert({19, 't'});
    toPrint.insert({20, 'u'});
    toPrint.insert({21, 'v'});
    toPrint.insert({22, 'w'});
    toPrint.insert({23, 'x'});
    toPrint.insert({24, 'y'});
    toPrint.insert({25, 'z'});

    fe(x, toPrint) indices.insert({x.s, x.f});

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n; cin >> n;
    string phrase; getline(cin, phrase);
    FOR(i,0,n){
        getline(cin, phrase);
        vector<bool> visited(26, false);
        
        fe(c, phrase) if(indices.find((char) tolower(c)) != indices.end()) visited[indices[(char) tolower(c)]] = true;
        
        bool valid = true;        
        FOR(j,0,26){
            if(!visited[j]){
                if(valid){
                    cout << "missing ";
                    valid = false;
                }

                cout << toPrint[j];
            }
        }

        if(valid) cout << "pangram";
        cout << endl;


    }

    return 0;
}