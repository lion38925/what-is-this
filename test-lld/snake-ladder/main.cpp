#include <iostream>
#include "service/gameService.h"
#include "model/dice.h"
#include "model/ladder.h"
#include "model/snake.h"
#include "model/player.h"
#include "model/board.h"
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int numberOfSnakes,numberOfLadders,numberOfPlayers;
    unordered_map<int,Snake*>snakeList;
    unordered_map<int,Ladder*>ladderList;
    vector< pair<Player*,bool> >allPlayers;

    cout<<"Enter Number of Snakes"<<endl;
    cout<<endl;
    cin>>numberOfSnakes;

    for( int i = 0; i < numberOfSnakes; i++ )
    {
        int head,tail;
        cout<<"Enter Snake-"<<(i+1)<<" Head & Tail "<<endl;
        cin>>head>>tail;
        if( head > tail )
        {
            Snake* snake = new Snake(head,tail);
            snakeList.insert({head,snake});
        }
    }

    cout<<"Enter Number of Ladders"<<endl;
    cout<<endl;
    cin>>numberOfLadders;

    for( int i = 0; i < numberOfLadders; i++ )
    {
        int head,tail;
        cout<<"Enter Ladder-"<<(i+1)<<" Head & Tail "<<endl;
        cin>>head>>tail;
        if( head < tail )
        {
            Ladder* ladder = new Ladder(head,tail);
            ladderList[head] = ladder;
        }
    }

    cout<<"Enter Number of Players"<<endl;
    cout<<endl;
    cin>>numberOfPlayers;

    for( int i = 0; i < numberOfPlayers; i++ )
    {
        cout<<"Enter Player-"<<(i+1)<<" Name: "<<endl;
        string name;
        cin>>name;

        Player* player = new Player(i,name);
        allPlayers.push_back({player,true});
    }

    cout<<"Initializing Board....."<<endl;
    cout<<endl;
    Board* board = new Board(numberOfSnakes,numberOfLadders,snakeList,ladderList);

    cout<<"Initializing Dice....."<<endl;
    cout<<endl;
    Dice* dice = new Dice();

    int currentPlayer = 0;
    int participants = numberOfPlayers;

    cout<<"Lets start the Game ....."<<endl;
    cout<<endl;

    while( participants > 1 )
    {
        if( allPlayers[currentPlayer].second == false )
        {
            currentPlayer = (currentPlayer+1)%numberOfPlayers;
        }
        else
        {
            int score = dice->getScore();
            board->updatePosition(allPlayers[currentPlayer].first,score);

            if( allPlayers[currentPlayer].first->checkWin() == true )
            {
                cout<<(allPlayers[currentPlayer].first)->getPlayerName()<<" wins the game"<<endl;
                cout<<endl;
                allPlayers[currentPlayer].second = false;
                participants--;
            }

            currentPlayer = (currentPlayer+1)%numberOfPlayers;

        }
    }

    return 0;

}


