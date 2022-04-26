#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
class player {
    string name;
    bool won;
    char symbol;
    public:
    player(string s, char x) {
        name = s;
        won = false;
        symbol = x;
    }
    string getName() {
        return name;
    }
    bool getWon() {
        return won;
    }
    void setWon(bool x) {
        won = x;
    }
    char getSymbol() {
        return symbol;
    }
};

class board {
    int sz;
    public:
    board(int s) {
        sz = s;
    }
    int getBoardSize() {
        return sz;
    }
};

class game {
    int boardDimensions;
    char bd[MAX][MAX];
    queue<player*> players;
    public:
    game(int boardD, vector<pair<string, char>> p) {
        board *b = new board(boardD);
        boardDimensions = b->getBoardSize();
        for(int i=0;i<2;i++) {
            player *obj = new player(p[i].first, p[i].second);
            players.push(obj);
        }
        initializeBoard();
        // printBoard();
    }
    void initializeBoard() {
        for(int i=0;i<2*boardDimensions - 1;i++) {
            for(int j=0;j<2*boardDimensions - 1;j++) {
                if(i%2 == 0 && j%2 != 0) bd[i][j] = '|';
                else if(i%2 != 0 && j%2 == 0) bd[i][j] = '-';
                else if(i%2 != 0 && j%2 != 0) bd[i][j] = '+';
                else bd[i][j] = ' ';
            }
        }
    }

    void printBoard() {
        for(int i=0;i<2*boardDimensions-1;i++) {
            for(int j=0;j<2*boardDimensions-1;j++) {
                cout<<bd[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int getRow(int x) {
        int r;
        if(x > 0 && x <= boardDimensions) {
            return r = x + (x-2);
        }
        return -1;
    }
    int getColumn(int y) {
        int c;
        if(y > 0 && y <= boardDimensions) {
            return c = y + (y-2);
        }
        return -1;
    }
    bool checkWinner(int r, int c, char sym) {
        string winnerString = "";
        for(int i=0;i<boardDimensions;i++)
            winnerString+= sym;
        cout<<"Winner String : - "<<winnerString<<endl;
        string rowString = "", columnString = "", diagonalString = "", reverseDiagonalString = "";
        for(int i=0;i<2*boardDimensions-1;i+=2) {
            rowString += bd[r][i];
            columnString += bd[i][c];
            if(r == c) diagonalString += bd[i][i];
            if(r + c == 2*boardDimensions - 2) reverseDiagonalString += bd[2*boardDimensions-2-i][i];
        }
        if(winnerString == rowString || winnerString == columnString || winnerString == diagonalString || winnerString == reverseDiagonalString)
            return true;
        return false;
    }

    void play() {
        int cnt = 0;
        while(!players.empty()) {
            cnt++;
            system("cls");
            printBoard();
            if(cnt > boardDimensions * boardDimensions) {
                cout<<"Match Draw\n";
                break;
            }
            player *p = players.front();
            players.pop();
            char sym = p->getSymbol();
            string nm = p->getName();
            int x, y, r, c;
            cout<<"Player "<<nm<<"\n";
            do {
                cout<<"Enter position row and column (1-based Indexing) : ";
                cin>>x>>y;
                r = getRow(x);
                c = getColumn(y);
                if(r == -1 || c == -1) {
                    cout<<"\nInvalid Position.\n";
                } else if (bd[r][c] != ' ') {
                    cout<<"\nPosition already occupied. Please select another position\n";
                }
            } while(bd[r][c] != ' ');
            bd[r][c] = sym;
            if(checkWinner(r,c,sym)) {
                system("cls");
                printBoard();
                cout<<"Player "<<nm<<" Wins\n";
                break;
            } else players.push(p);
        }
    }
};

int main() {
    int n;
    string s;
    char x;
    vector<pair<string, char>> players;
    ifstream file;
    file.open("sampleInput.txt");
    if(!file) {
        cout<<"Error! Files doesn't Exist."<<endl;
        exit(1);
    } else {
        file >> n;
        for(int i=0;i<2;i++) {
            file >> s;
            file >> x;
            players.push_back({s,x});
        }
        cout<<"Successfully Read Input from file."<<endl;
        file.close();
    }
    game *g = new game(n, players);
    g->play();
    return 0;
}