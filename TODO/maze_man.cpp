#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
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

struct Cell{
    int row,col;
    char value;
    bool visited;

    Cell(){

    }

    Cell(int r, int c, char v, bool vis){
        row = r;
        col = c;
        value = v;
        visited = vis;
        
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col; cin >> row >> col;

    vector<string> input(row);

    string throwAway;
    getline(cin,throwAway);

    FOR(i,0,row){
       
        getline(cin,input[i]);
    }

    vector<Cell> entrances;

    vector<vector<Cell>> maze(row+2,vector<Cell>(col+2,Cell(0,0,' ',false)));

    //TODO MAKE IT ONE MORE WIDER ON VERT AND HOR EDGES

    //filling top edge
    for(int i = 0; i < col+2; i++){
        maze[0][i].value = 'X';
        maze[0][i].row = 0;
        maze[0][i].col = i;
        maze[0][i].visited = true;
    }
    //filling bottom edge
    for(int i = 0; i < col+2; i++){
        maze[row+1][i].value = 'X';
        maze[row+1][i].row = row+1;
        maze[row+1][i].col = i;
        maze[row+1][i].visited = true;
    }
    //filling left edge
    for(int i = 0; i < row+2; i++){
        maze[i][0].value = 'X';
        maze[i][0].col = 0;
        maze[i][0].row = i;
        maze[i][0].visited = true;
    }

    //filling right edge
    for(int i = 0; i < row+2; i++){
        maze[i][col+1].value = 'X';
        maze[i][col+1].col = col+1;
        maze[i][col+1].row = i;
        maze[i][col+1].visited = true;
    }

    int numDot = 0;
    //count the dots, and finding start pos also building the maze
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){

            char currChar = input[r][c];

            if(currChar == '.'){
                numDot++;
            }
            else if (currChar != 'X' && currChar != ' '){
                Cell temp;
                temp.row = r+1;
                temp.col = c+1;
                temp.value = currChar;
                temp.visited = false;

                entrances.push_back(temp);
            }

            Cell currCell;
            currCell.row = r+1;
            currCell.col = c+1;
            currCell.value = currChar;
            currCell.visited = false;

            maze[r+1][c+1] = currCell;
        }
    }

    int players = 0;

    foreach(startCell, entrances){   
        stack<Cell> todo;
        todo.push(startCell);

        bool firstTime = true;


        while(!todo.empty()){

        
            Cell visited = todo.top();
            int currRow = visited.row, currCol = visited.col;

            if(maze[currRow][currCol].visited){
                todo.pop();
                continue;
            }
            if(visited.value == '.'){
                numDot--;
                if(firstTime){
                    players++;
                    firstTime = false;
                }
            }
           

            todo.pop();

            maze[currRow][currCol].visited = true;
            

            //check neighbours
            for(int i = -1; i <= 1; i += 2){
                Cell hNeighbour = maze[currRow][currCol + i];
                Cell vNeighbour = maze[currRow + i][currCol];
                if(!hNeighbour.visited  && (hNeighbour.value == ' ' || hNeighbour.value == '.')){
                    todo.push(hNeighbour);
                }
                if(!vNeighbour.visited  && (vNeighbour.value == ' ' || vNeighbour.value == '.')){
                    todo.push(vNeighbour);
                }

            }


        }

    }
    cout << players << " " << numDot << endl;

    return 0;
}
