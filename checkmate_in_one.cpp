//checkmate in one

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int,int> wK;
    pair<int,int> bK;
    pair<int,int> wR;

    FOR(y,0,8){
        FOR(x,0,8){
            char c;
            cin >> c;

            if(c == 'K'){
                wK.first = x;
                wK.second = y;
            }
            else if(c == 'k'){
                bK.first = x;
                bK.second = y;
            }
            else if(c == 'R'){
                wR.first = x;
                wR.second = y;
            }

        }
    }

    //if the black king is not on the edges
    if(bK.second != 0 && bK.second != 7 && bK.first != 0 && bK.first != 7){
        cout << "No\n";
        goto end;
    }
    else{
        //case where the bK is on the left side of the board
        if(bK.first == 0){
            //case where bK is on the top left of the board
            if(bK.second == 0){
                if(wK.first == 0 && wK.second == 2){
                    if(wR.first > 1){
                        goto yes;
                    }
                    else{
                        goto no;
                    }
                }
                else if(wK.first == 2 && wK.second == 0){
                    if(wR.second > 1){
                        goto yes;
                    }
                    else{
                        goto no;
                    }
                }
                else if(wK.first == 2 && wK.second == 1){
                    if(wR.first == 1 && wR.second == 1){
                        goto no;
                    }
                    else{
                        goto yes;
                    }
                }
                else if(wK.first == 1 && wK.second == 2){
                    if(wR.first == 1 && wR.second == 1){
                        goto no;
                    }
                    else{
                        goto yes;
                    }
                }
                else{
                    goto no;
                }
            }
            //case where bK is on the bottom left of the board
            else if(bK.second == 7){
                if(wK.first == 0 && wK.second == 5){
                    if(wR.first > 1){
                        goto yes;
                    }
                    else{
                        goto no;
                    }
                }
                else if(wK.first == 2 && wK.second == 7){
                    if(wR.second < 6){
                        goto yes;
                    }
                    else{
                        goto no;
                    }
                }
                else if(wK.first == 1 && wK.second == 5){
                    if(wR.second == 6 && wR.first == 1){
                        goto no;
                    }
                    else{
                        goto yes;
                    }
                }
                else if(wK.first == 2 && wK.second == 6){
                    if(wR.second == 6 && wR.first == 1){
                        goto no;
                    }
                    else{
                        goto yes;
                    }
                }
                else{
                    goto no;
                }
            }
            //case whre bK is not in a corner
            else{
                if(wK.first == (bK.first + 2) && wK.second == bK.second){
                    if(wR.second < bK.second - 1 || wR.second > bK.second + 1){
                        goto yes;
                    }
                    else{
                        goto no;
                    }
                }
                else{
                    goto no;
                }
            }
        }
        //case where bK is on the right
        else if(bK.first == 7){
            //top right corner
            if(bK.second == 0){
                if(wK.first == 5){
                    if(wK.second == 0){
                        if(wR.second > 1){
                            goto yes;
                        }
                        else{
                            goto no;
                        }
                    }
                    else if(wK.second == 1){
                        if(wR.first == 6 && wR.second ==1){
                            goto no;
                        }
                        else{
                            goto yes;
                        }
                    }
                    else{
                        goto no;
                    }
                }
                else if(wK.second == 2){
                    if(wK.first == 7){
                        if(wR.first < 6){
                            goto yes;
                        }
                        else{
                            goto no;
                        }
                    }
                    else if(wK.first == 6){
                        if(wR.first == 6 && wR.second ==1){
                            goto no;
                        }
                        else{
                            goto yes;
                        }
                    }
                    else{
                        goto no;
                    }
                }
                else{
                    goto no;
                }
            }
            //case if bK is in bottom rigt corner
            else if(bK.second == 7){
                if(wK.second == 5){
                    if(wK.first == 7){
                        if(wR.first < 6){
                            goto yes;
                        }
                        else{
                            goto no;
                        }
                    }
                    else if(wK.first == 6){
                        if(wR.first == 6 && wR.second == 6){
                            goto no;
                        }
                        else{
                            goto yes;
                        }
                    }
                    else{
                        goto no;
                    }
                }
                else if(wK.first == 5){
                    if(wK.second == 7){
                        if(wR.second < 6){
                            goto yes;
                        }
                        else{
                            goto no;
                        }
                    }
                    else if(wK.second == 6){
                        if(wR.first == 6 && wR.second == 6){
                            goto no;
                        }
                        else{
                            goto yes;
                        }
                    }
                    else{
                        goto no;
                    }
                }
                else{
                    goto no;
                }
            }
            else{
                if(wK.first == bK.first - 2 && wK.second == bK.second){
                    if(wR.second < bK.second - 1 || wR.second > bK.second + 1){
                        goto yes;
                    }
                    else{
                        goto no;
                    }
                }
                else{
                    goto no;
                }
            }
        }
        //bK is in bottom edge
        else if(bK.second == 7){
            if(wK.first == bK.first && wK.second == bK.second - 2){
                if(wR.first < bK.first - 1 || wR.first > bK.first + 1){
                    goto yes;
                }
                else{
                    goto no;
                }
            }
            else{
                goto no;
            }
        }
        //bK is in top edge
        else if(bK.second == 0){
            if(wK.first == bK.first && wK.second == bK.second + 2){
                if(wR.first < bK.first - 1 || wR.first > bK.first + 1){
                    goto yes;
                }
                else{
                    goto no;
                }
            }
            else{
                goto no;
            }            
        }
        else{
            goto no;
        }


    }

    yes:
    cout << "Yes\n";
    goto end;

    no:
    cout << "No\n";

    end:
    return 0;
}
