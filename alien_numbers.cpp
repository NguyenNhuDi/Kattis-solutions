#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef vector<char> vc;
typedef vector<int> vi;

void print(vc a){

    for(const auto & x : a){
        cout << x;
    }

    cout << "\n";
}

int vToInt(vi num) { 
    int n = 0;
    int N = num.size();
    
    for (int i = 0; i < N; i++) {
        n += num[i]*pow(10, N-i-1);
    }
    return n;
}

int toBase10(int base, vi number){

    if (base == 10){
        return vToInt(number);
    }

    int size = number.size();
    
    
    int returnValue = 0;

    for(int i = 0; i < size; i++){
        returnValue += (number[i] * pow(base, size - 1 - i));
    }

    return returnValue;
    
}


vi toCode (int number, int base){

    vi code;

    while(number != 0){

        int remainder = number % base;

        code.insert(code.begin(), remainder);

        number /= base;

    }

    return code;   

}


int main() {

    int n;

    cin >> n;

    int currCase = 1;

    while(n--){

        string i, j, k;
        cin >> i >> j >> k;
        
        vc input(i.begin(),i.end());
        vc source(j.begin(),j.end());
        vc target(k.begin(),k.end());

        
        int base = source.size();
        int targetBase = target.size();

        vi inputValue;

        for(int a = 0; a < input.size(); a++){
            for(int b = 0; b < base; b++){

                if(input[a] == source[b]){

                    inputValue.push_back(b);
                    break;

                }

            }

        }

        int number = toBase10(base, inputValue);

        vi code = toCode(number, targetBase);


        cout << "Case #" << currCase << ": ";

        for(auto & x : code){
            cout << target[x];
        }

        cout << endl;

        currCase++;

        
    }

    return 0;
}
