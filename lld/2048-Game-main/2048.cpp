#include<bits/stdc++.h>
using namespace std;
const int MAX = 4;
class player {
    string name;
    bool won;
    public:
    player(string s) {
        name = s;
        won = false;
    }
    string getName() {
        return name;
    }
    void setWon(bool x) {
        won = x;
    }
    bool getWon() {
        return won;
    }
};

class newPiece {
    vector<int> piece;
    public:
    newPiece() {
        int x = 1;
        for(int i=1;i<=4;i++){
            x *= 2;
            piece.push_back(x);
        }
    }
    int generatePiece() {
        return piece[rand()%4];
    }
};

class mapping {
    public:
    int dirR[4] = {-1, 0, 1, 0};
    int dirC[4] = {0, 1, 0, -1};
    int getMapping(char c) {
        if(c == 'D' || c == 'd') return 0;
        else if(c == 'R' || c == 'r') return 1;
        else if(c == 'U' || c == 'u') return 2;
        else return 3;
    }
    int getdirR(int x) {
        return dirR[x];
    }
    int getdirC(int x) {
        return dirC[x];
    }
};

class game {
    int board[MAX][MAX];
    mapping *m;
    newPiece *addP;
    public: 
    game() {
        mapping *mp = new mapping();
        m = mp;
        newPiece *p = new newPiece();
        addP = p;
        initailizeBoard();
    }
    void initailizeBoard() {
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                board[i][j] = 0;
            }
        }
        addPiece();
    }
    void printBoard() {
        system("cls");
        for(int i=0;i < 4;i++) {
            for(int j=0;j < 4;j++) {
                if(board[i][j] == 0)
                    cout<<setw(4)<<".";
                else cout<<setw(4)<<board[i][j];
            }
            cout<<endl;
        }
    }
    void addPiece() {
        int x = addP->generatePiece();
        do{
            int r = rand()%MAX;
            int c = rand()%MAX;
            if(board[r][c] == 0) {
                board[r][c] = x;
                break;
            }
        }while(true);
    }
    void play() {
        char c;
        do {
            printBoard();
            cout<<"Menu\nPress L for Left\nPress R for Right\nPress D for Down\nPress U for Up\nPress N for NewGame\nPress Q to Quit\n";
            cin>>c;
            if(c == 'N' || c == 'n') {
                initailizeBoard();
                printBoard();
            } else if (c == 'Q' || c == 'q') {break;}
            else {
                int direction = m->getMapping(c);
                applyMove(direction);
                if(checkWinner()) {
                    cout<<"Winner"<<endl;
                    break;
                }
            }
        } while(true);
    }
    void applyMove(int dir) {
        int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
        if(dir == 1) {
            startCol = 3;
            colStep = -1;
        } else if(dir == 0) {
            startRow = 3;
            rowStep = -1;
        }
        int movePossible = 0, canAddPiece = 0;
        do {
            movePossible = 0;
            for(int i= startRow; i >= 0 && i < 4; i+= rowStep) {
                for(int j = startCol ; j >=0 && j < 4 ; j+= colStep) {
                    int x = m->getdirR(dir), y = m->getdirC(dir);
                    int nextI = i + x, nextJ = j + y;
                    if(board[i][j] && canMove(i, j, nextI, nextJ)) {
                        board[nextI][nextJ] += board[i][j];
                        board[i][j] = 0;
                        movePossible = 1;
                        canAddPiece = 1;
                    }
                }
            }
            printBoard();
        }while(movePossible);
        if(canAddPiece) addPiece();
    }
    bool canMove(int i, int j, int nextI, int nextJ) {
        if(nextI < 0 || nextI >= 4 || nextJ < 0 || nextJ >= 4 || (board[i][j] != board[nextI][nextJ] && board[nextI][nextJ] !=0))
            return false;
        return true;
    }

    bool checkWinner() {
        vector<int> v = {2, 0, 4, 8};
        int k=0;
        for(int i=0;i<4;i++){
            k=0;
            for(int j=0;j<4;j++){
                if(board[i][j] == v[k]) k++;
            }
            if(k == 4) return true;
        }
        return false;
    }
};

int main() {
    game *g = new game();
    g->play();
    return 0;
}
