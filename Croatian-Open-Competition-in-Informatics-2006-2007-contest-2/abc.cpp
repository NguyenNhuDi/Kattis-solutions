#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int a, b, c;
    string order;

    cin >> a >> b >> c;
    cin >> order;

    vector<int> list;

    list.push_back(a);
    list.push_back(b);
    list.push_back(c);

    sort(list.begin(), list.end());

    for(const auto & x: order){
        if(x == 'A'){
            cout << list[0] << " ";
        }
        else if(x == 'B'){
            cout << list[1] << " ";
        }
        else{
            cout << list[2] << " ";
        }

    }

    return 0;
}
