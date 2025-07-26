#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int smallest;
    cin >> smallest;
    double l, w, initSmall, initBig;
    
    l = 0.420448207627;
    w = 0.594603557501;
    initSmall = l;
    initBig = w;
    double area = l * w;
    double tape = 0;
    double need = 1;

    for(int i = 2; i < smallest +1; i++){
        need *= 2;
        int input;
        cin >> input;
        if(i != 2 && i%2 == 0){
            l /= 2;
        }
        else if(i != 2){
            w /= 2;
        }

        if(need < input){
            tape = tape + (l + w) * need * 2;
            need -= input;
            break;
        }
        else{
            tape += (l + w) * input * 2;
            need -= input;
        }


    }
    if(need > 0){
        printf("impossible\n");
    }
    else{
        printf("%.11f\n",(tape - (initBig+initSmall*2)*2)/2);
    }

    return 0;
}
