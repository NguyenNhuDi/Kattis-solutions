#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

void compress(std::vector<int> & s){
    while(s.size() > 1 && s[s.size() - 1] == s[s.size() - 2]){
        s.pop_back();
        s.back() *= 2;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;
    FOR(_, 0, n){
        string inpoo; std::cin >> inpoo;

        std::vector<int> s = {inpoo[0] - '0'};
        std::vector<int> out = {inpoo[0] - '0'};

        int it = 1;
        while(it < inpoo.size()){
            int c = inpoo[it] - '0';

            if(c <= s.back()){
                out.push_back(c);
                s.push_back(c);
                ++it;
            }
            else{
                out.push_back(s.back());
                s.push_back(s.back());
            }
            compress(s);
        }

        while(s.size() > 1){
            if(s.back() > 8){
                out.push_back(8);
                s.push_back(8);
            }
            else{
                out.push_back(s.back());
                s.push_back(s.back());
            }
            compress(s);
        }

        string str_out = "";
        fe(x, out) str_out += std::to_string(x);

        std::cout << str_out << std::endl;
    }

    return 0;
}
