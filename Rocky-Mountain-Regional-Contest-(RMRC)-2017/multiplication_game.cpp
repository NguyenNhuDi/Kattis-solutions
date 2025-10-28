#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second
#define MAXI 65536

using namespace std;


void sieve(std::vector<int> & arr){
    std::vector<bool> p(MAXI + 1, 1);

    FOR(i, 2, MAXI + 1){
        if(p[i]){
            arr.push_back(i);

            FOR(j, i * i, j += i)
                p[j] = 0;
        }
    }
}

void get_factors(std::unordered_map<int, int> & factors, const std::vector<int> & primes, int num){
    int count = 0;
    fe(p, primes){
        if (p * p > num)
            break;

        while(num % p == 0){
            factors[p]++;
            num /= p;

        }
    }
    if(num > 1){
        factors[num]++;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<int> primes;
    primes.reserve(MAXI);
    sieve(primes);

    int n; std::cin >> n;

    while(n--){
        int num; 
        string name;
        std::cin >> num >> name;

        string other = name == "Alice" ? "Bob" : "Alice";

        std::unordered_map<int, int> factors;

        get_factors(factors, primes, num);

        auto it = factors.begin();
        if(factors.size() == 1){
            int count = (*it).s;

            std::cout << (count % 2 ? name : other) << std::endl;
        }
        else if(factors.size() == 2){
            int l = (*it).s;
            it++;
            int r = (*it).s;

            if(l == r){
                std::cout << other << std::endl;
            }
            else if(std::abs(l - r) == 1){
                std::cout << name << std::endl;
            }
            else{
                std::cout << "tie" << std::endl;
            }
        }
        else{
            std::cout << "tie" << std::endl;
        }
    }
    return 0;
}
