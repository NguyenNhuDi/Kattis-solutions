#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    std::set<int> palindromes;
    FOR(i, 100000, 1000000){
        string t = std::to_string(i);

        bool valid = true;
        FOR(j, 0, 3){
            if(t[j] != t[5 - j]){
                valid = false;
                break;
            }
        }

        if(valid)
            palindromes.insert(i);
    }
    
    int n; std::cin >> n;
    FOR(i, 0, n){
        int inpoo; std::cin >> inpoo;

        if(inpoo < 100001){
            std::cout << 100001 << std::endl;
        }
        else if(inpoo == 999999){
            std::cout << inpoo << std::endl;
        }
        else if(palindromes.count(inpoo)){
            std::cout << inpoo << std::endl;
        }
        else{
            auto it = palindromes.lower_bound(inpoo);
            int r = *it;
            it--;
            int l = *it;

            if(std::abs(l - inpoo) <= std::abs(r - inpoo)){
                std::cout << l << std::endl;
            }
            else{
                std::cout << r << std::endl;
            }

        }
    }

    return 0;
}
