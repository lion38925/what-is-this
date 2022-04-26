#include <bits/stdc++.h>
using namespace std;
#include "board.h"


Board::Board(){
    colSum.resize(n,0);
    diagSum = 0;
    revDiagSum = 0;
    rowSum.resize(n,0);
    board.resize(n, vector<string>(n, "."));
}

// Player first =0 -1 for this
// Player second = 1 +1for this
// return 1 if 1st player wins, 2 if 2nd player wins, -1 if no one wins;
int Board::move(Player &player, int row, int col){
    if(row<0  || col< 0 || row>=n || col >=n){
        std::cout <<"Out of Board" <<std::endl;
        return -1;
    }
    else if(board[row][col] != "."){
        std::cout << "Cell already filled" <<std::endl;
        return -1;
    }
    else{
        board[row][col] = player.getSymbol() ;
        print();
        player.move(row, col);
        if(getWinner(player, row, col)){
            return (player.getUserDetails().getId()=="0") ? 1: 2;
        }
        else{
            return -1;
        }
    }
}

bool Board::getWinner(Player &player, int row, int col){
    rowSum[row] += (player.symbol == "X") ? -1:1;
    colSum[col] += (player.symbol == "X") ? -1:1;

    if(row==col){
        diagSum += (player.symbol == "X") ? -1:1;
    }

    if(col == n-row-1){
        revDiagSum += (player.symbol == "X") ? -1:1;;
    }

    if(abs(rowSum[row]) == n || abs(colSum[col]) == n || abs(diagSum) == n || abs(revDiagSum) == n){
        return true;
    }
    else{
        return false;
    }
}

void Board::print() {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        std::cout <<std::endl;
    }
}
