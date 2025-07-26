#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
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
unordered_map<char, int> nums;

void init(){
    toPrint.insert({1, '1'});
    toPrint.insert({2, '2'});
    toPrint.insert({3, '3'});
    toPrint.insert({4, '4'});
    toPrint.insert({5, '5'});
    toPrint.insert({6, '6'});
    toPrint.insert({7, '7'});
    toPrint.insert({8, '8'});
    toPrint.insert({9, '9'});
    toPrint.insert({10, 'a'});
    toPrint.insert({11, 'b'});
    toPrint.insert({12, 'c'});
    toPrint.insert({13, 'd'});
    toPrint.insert({14, 'e'});
    toPrint.insert({15, 'f'});
    toPrint.insert({16, 'g'});
    toPrint.insert({17, 'h'});
    toPrint.insert({18, 'i'});
    toPrint.insert({19, 'j'});
    toPrint.insert({20, 'k'});
    toPrint.insert({21, 'l'});
    toPrint.insert({22, 'm'});
    toPrint.insert({23, 'n'});
    toPrint.insert({24, 'o'});
    toPrint.insert({25, 'p'});
    toPrint.insert({26, 'q'});
    toPrint.insert({27, 'r'});
    toPrint.insert({28, 's'});
    toPrint.insert({29, 't'});
    toPrint.insert({30, 'u'});
    toPrint.insert({31, 'v'});
    toPrint.insert({32, 'w'});
    toPrint.insert({33, 'x'});
    toPrint.insert({34, 'y'});
    toPrint.insert({35, 'z'});
    toPrint.insert({36, '0'});

    fe(x, toPrint) nums.insert({x.s, x.f});

    nums['0'] = 0;
}

double calc(double l, double r, string op){
    if(op == "+") return l + r;
    else if(op == "-") return l - r;
    else if(op == "*") return l * r;
    else {
        if (r == 0) return INT32_MIN;
        return l / r;
    }
}

double toNum(string x, double base){
    double out = 0;
    
    reverse(x.begin(), x.end());
    FOR(i,0, x.size()){
        if(base == 1 && x[i] != '1') return DBL_MIN;
        else if(base > 1 && nums[x[i]] >= base) return DBL_MIN;


        out += nums[x[i]] * pow(base, i);
    }

    return out;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n; cin >> n;

    FOR(i,0,n){
        string l, r, op, _, ans; cin >> l >> op >> r >> _ >> ans;
        bool valid = false;
        FOR(i,1,37){
            double left = toNum(l, i), right = toNum(r, i), answer = toNum(ans,i);
            
            if(left == DBL_MIN || right == DBL_MIN || answer == DBL_MIN) continue;

            if(calc(left, right, op) == answer) {valid = true; cout << toPrint[i];}
        }

        if (!valid) cout << "invalid";
        cout << endl;
    }


    return 0;
}