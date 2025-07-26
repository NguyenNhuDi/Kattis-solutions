#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int bSearch(vector<int> a, int x){
    int size = a.size();
    int l = 0;
    int r = size - 1;
    int result = -1;
    while(l <= r){
        int m = (l + r) /2;
        if(a[m] <= x){
            l = m + 1;
            result = m;
        }
        else{
            r = m -1;
        }
    }
    return result;
}







int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    cin >> input;

    float under_score = 0;
    float lower = 0;
    float uper = 0;
    float symbol = 0;

    float size = input.size();

    for(const auto & x : input){
        if(islower(x)){
            lower++ ;
        }
        if(x == '_'){
            under_score++;
        }
        if(isupper(x)){
            uper++;
        }
    }

    symbol = size - uper - under_score - lower;

    cout << under_score / size << "\n";
    cout << lower / size << "\n";
    cout << uper / size << "\n";
    cout << symbol / size << "\n";


    return 0;
}
