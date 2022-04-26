#include<bits/stdc++.h>
using namespace std;

class board {
    int sz;
    public:
    board(int s){
        sz = s;
    }
    int getBoardSize(){
        return sz;
    }
};

class player {
    string name;
    int position;
    bool won;
    public:
    player(string n){
        name = n;
        position = 0;
        won = false;
    }
    string getName(){
        return name;
    }
    int getPosition() {
        return position;
    }
    bool getWon() {
        return won;
    }
    void setPosition(int x) {
        position = x;
    }
    void setWon(bool x) {
        won = x;
    }
};

class dice {
    public:
    int rollDice() {
        return (1 + rand()%6);
    }
};

class snake {
    int start, end;
    public:
    snake(int s, int e) {
        start = s;
        end = e;
    }
    int getSnakeStartPos() {
        return start;
    }
    int getSnakeEndPos() {
        return end;
    }
};

 class ladder {
     int start, end;
     public:
     ladder(int s, int e) {
         start = s;
         end = e;
     }
     int getLadderStartPos() {
         return start;
     }
     int getLadderEndPos() {
         return end;
     }
};

class game {
    int snakesCount, laddersCount, playersCount, boardDimension;
    dice* diceValue;
    vector<snake*> snakes;
    vector<ladder*> ladders;
    queue<player*> players;
    public:
    game(int snakesNumber, vector<pair<int,int>> sk, int ladderNumber, vector<pair<int,int>> ld, int playerNumber, vector<string> py, int boardD ) {
        snakesCount = snakesNumber;
        laddersCount = ladderNumber;
        playersCount = playerNumber;
        board *bd = new board(boardD);
        boardDimension = bd->getBoardSize();
        dice *d = new dice();
        diceValue = d;
        for(int i=0;i<snakesCount;i++){
            snake *obj = new snake(sk[i].first, sk[i].second);
            snakes.push_back(obj);
        }
        for(int i=0;i<laddersCount;i++){
            ladder *obj = new ladder(ld[i].first, ld[i].second);
            ladders.push_back(obj);
        }
        for(int i=0;i<playersCount;i++){
            player *obj = new player(py[i]);
            players.push(obj);
        }
    }

    void play() {
        while(!players.empty()) {
            player *p = players.front();
            players.pop();
            int oldPos = p->getPosition();
            int diceRoll = diceValue->rollDice();
            int newPos = oldPos + diceRoll;
            cout<<"Player - "<<p->getName()<<endl;
            if(newPos > boardDimension) {
                cout<<"Moved - "<<oldPos<<" to "<<oldPos<<endl;
                cout<<endl;
                players.push(p);
            } else {
                cout<<"New position : - "<<newPos<<endl;
                p->setPosition(getNewPosition(newPos));
                int newPosition = p->getPosition();
                if(newPos == boardDimension) {
                    cout<<"Moved - "<<oldPos<<" to "<<newPosition<<endl;
                    cout<<"Winner"<<endl;
                    cout<<endl;
                    p->setWon(true);
                } else {
                    cout<<"Moved - "<<oldPos<<" to "<<newPosition<<endl;
                    cout<<endl;
                    players.push(p);
                }
            }
            if(players.size() < 2) break;
            char c;
            cin>>c;
        }
    }

    int getNewPosition(int x) {
        for(snake *s : snakes) {
            if(s->getSnakeStartPos() == x) {
                cout<<"Bit by snake. New Position : - "<<x<<" to "<<s->getSnakeEndPos()<<endl;
                x = s->getSnakeEndPos();
            }
        }
        for(ladder *l : ladders) {
            if(l->getLadderStartPos() == x) {
                cout<<"Reached a ladder. New Position : - "<<x<<" to "<<l->getLadderEndPos()<<endl;
                x = l->getLadderEndPos();
            }
        }
        return x;
    }

};

int main() {
    int boardSize, numberOfSnakes, numberOfLadders, numberOfPlayers, x, y;
    string str;
    vector<pair<int,int>> snakes, ladders;
    vector<string> players;
    ifstream file;
    file.open("sampleInput.txt");
    if(!file) {
        cout<<"Error ! No file named sampleInput.txt"<<endl;
        exit(1);
    } else {
        file >> boardSize;
        file >> numberOfSnakes;
        for(int i=0;i<numberOfSnakes;i++) {
            file >> x;
            file >> y;
            snakes.push_back({x,y});
        }
        file >> numberOfLadders;
        for(int i=0;i<numberOfLadders;i++) {
            file >> x;
            file >> y;
            ladders.push_back({x,y});
        }
        file >> numberOfPlayers;
        for(int i=0;i<numberOfPlayers;i++){
            file >> str;
            players.push_back(str);
        }
        file.close();
        cout<<"Reached End of File ";
    }
    
    // cin>>boardSize;
    // cin>>numberOfSnakes;
    // for(int i=0;i<numberOfSnakes;i++) {
    //     cin>>x>>y;
    //     snakes.push_back({x,y});
    // }
    // cin>>numberOfLadders;
    // for(int i=0;i<numberOfLadders;i++) {
    //     cin>>x>>y;
    //     ladders.push_back({x,y});
    // }
    // cin>>numberOfPlayers;
    // for(int i=0;i<numberOfPlayers;i++){
    //     cin>>str;
    //     players.push_back(str);
    // }
    cout<<"\nEntering Game \n\n";
    game *g = new game(numberOfSnakes, snakes, numberOfLadders, ladders, numberOfPlayers, players, boardSize);
    g->play();
    return 0;
}