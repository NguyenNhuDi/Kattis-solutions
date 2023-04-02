#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;


vi flipA(vi x){
    int temp = x[0];

    x[0] = x[1];
    x[1] = temp;

    return x;
}

vi flipB(vi x){
    int temp = x[1];

    x[1] = x[2];
    x[2] = temp;

    return x;
}

vi flipC(vi x){
    int temp = x[0];

    x[0] = x[2];
    x[2] = temp;

    return x;
}


int main(){

    vi list(3,0);

    list[0] = 1;

    string input;

    cin >> input;


    vc charList;

    for(auto & x : input){
        charList.push_back(x);
    }

    for(auto & x: charList){
        
        if(x == 'A'){
            list = flipA(list);
        }
        else if (x == 'B'){
            list = flipB(list);
        }
        else if (x == 'C'){
            list = flipC(list);
        }

        
    }

    int pos = 1;
    for(auto & x : list){
        if (x == 1){
            cout << pos;
        }

        pos++;
    }


    return 0;
}
