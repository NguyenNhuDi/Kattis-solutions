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

int power(int x, int y){
    if(y == 0){
        return 1;
    }

    return x * power(x,--y);
}

int toInt(string x){
    int out = 0;
    int counter = 0;
    for(const auto &i : x){
        if(i == 'B'){
            out += power(2,counter);
        }
        counter++;
    }
    return out;
}

string intToString(int x){
    string out = "";

    while(x){
        int remainder = x % 2;

        char i = remainder +'0';
        out += i;
        x /= 2;
    }

    return out;

}

string binToOutput(string x, int length){
    string out = "";

    for(const auto &i : x){
        if(i == '0'){
            out += 'A';
        }
        else{
            out += 'B';
        }
    }

    int temp = length - x.length();

    FOR(i,0,temp){
        out += 'A';
    }

    return out;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int days;
    cin >> input >> days;

    int length = input.length();

    int end = toInt(input);

    end += days;

    cout << binToOutput(intToString(end),length) << endl;

    return 0;
}
