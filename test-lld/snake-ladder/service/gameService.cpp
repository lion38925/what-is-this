#include "gameService.h"
#include "../model/user.h"
gameService::gameService(std::string &p1_name, std::string &p2_name) {
    user userdetail1;
    userdetail1.setName(p1_name);
    userdetail1.setId("0");
    p1.setUserDetails(userdetail1);
    p1.setSymbol("X");
    user userdetail2;
    userdetail2.setName(p2_name);
    userdetail2.setId("1");
    p2.setUserDetails(userdetail2);
    p2.setSymbol("O");
    moves = 0;

}

void gameService::play() {
    while(true){
        int x,y;
        std::cout << p1.userDetails.getName() <<" move" <<std::endl;
        std::cin >> x >> y;

        int res = board.move(p1, x, y);
        if(res == 1){
            //std::cout << p1.name <<" won the match" << std::endl;
            won = true;
            p1.isWin = true;
            break;
        }
        if(moves >= 4){
            std::cout << "Match draw" << std::endl;
            won = false;
            break;
        }
        std::cout << p2.userDetails.getName()<<" move"<<std::endl;
        std::cin >> x >> y;

        res = board.move(p2, x, y);
        if(res == 2){
            //std::cout << p2.name <<" won the match" << std::endl;
            won = true;
            p2.isWin = true;
            break;
        }

        moves++;
    }
    generateReport();
}
void gameService::generateReport(){

    if(p1.isWin){
        std::cout <<  p1.userDetails.getName() <<" Won the match" << std::endl;
    }
    else if(p2.isWin){
        std::cout <<  p2.userDetails.getName() <<" Won the match" << std::endl;
    }
    else{
        std::cout << "Match draw" <<std::endl;
    }
    std::cout <<" Here is final board" << std::endl;
    std::cout <<"X for " <<  p1.userDetails.getName() <<" & O for " << p2.userDetails.getName() << std::endl;

    board.print();

    std::cout << "Moves by " <<  p1.userDetails.getName() << std::endl;

    for(auto i:p1.movesList){
        std::cout << "("<<i.first <<", " <<i.second << ") ";
    }
    std::cout << std::endl;

    std::cout << "Moves by " <<  p2.userDetails.getName() << std::endl;

    for(auto i:p2.movesList){
        std::cout << "("<<i.first <<", " <<i.second << ") ";
    }
    std::cout << std::endl;

}
