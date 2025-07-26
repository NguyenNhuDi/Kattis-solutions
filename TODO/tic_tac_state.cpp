#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define foreach(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

bool wonHorizontal(vector<string> board, char x){

    foreach(row, board){
        int counter = 0;
        
        foreach(item, row) {
            if (item == x) counter++;
        }

        if (counter == 3) return true;
    }

    return false;
}

bool wonVertical(vector<string> board, char x){
    FOR(row,0,3){
        int counter = 0;
        FOR(col, 0, 3){
            if (board[col][row] == x){
                counter++;
            }
        }

        if (counter == 3) return true;
    }

    return false;
}

bool wonDiagonal(vector<string> board, char x){

    if (board[0][0] == x && board[1][1] == x && board[2][2] == x) return true;
    if (board[0][2] == x && board[1][1] == x && board[2][0] == x) return true;

    return false;
}



string octalToBin(string x){

    string out;

    foreach(c, x){
        switch (c)
        {
        case '0':
            out += "000";
            break;
        case '1':
            out += "001";
            break;
        case '2':
            out += "010";
            break;
        case '3':
            out += "011";
            break;
        case '4':
            out += "100";
            break;
        case '5':
            out += "101";
            break;
        case '6':
            out += "110";
            break;
        case '7':
            out += "111";
            break;
        
        default:
            break;
        }
    }

    reverse(out.begin(), out.end());
    return out;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    FOR(i,0,n){
        string input; cin >> input;

        string binary = octalToBin(input);

        vector<string> board;

        FOR(i,0,3){
            board.push_back("___");
        }

        FOR(i,0,9){
            if (binary[i] == '1'){
                board[i / 3][i % 3] = binary[i + 9];
            }
        }

        if (wonHorizontal(board, '1')){
            cout << "X wins" << endl;
        }
        else if (wonVertical(board, '1')){
            cout << "X wins" << endl;
        }
        else if (wonDiagonal(board, '1')){
            cout << "X wins" << endl;
        }
        else if (wonVertical(board, '0')){
            cout << "O wins" << endl;
        }
        else if (wonDiagonal(board, '0')){
            cout << "O wins" << endl;
        }
        else if (wonHorizontal(board, '0')){
            cout << "O wins" << endl;
        }
        else{
            bool tie = true;
            FOR(i,0,3){
                FOR(j,0,3){
                    if(board[i][j] == '_'){
                        tie = false;
                    }
                }
            }

            if (tie){
                cout << "Cat's\n";
            }
            else{
                cout << "In progress\n";
            }

        }

    }


    return 0;
}
