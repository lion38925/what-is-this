#include "player.h"

Player::Player() {
}
Player::Player(int id){
	isWin = false;
}

void Player::move(int i, int j) {
    movesList.push_back({i, j});
}

user Player::getUserDetails() { return userDetails; }
void Player::setUserDetails(user userDetails_) { this->userDetails = userDetails_; }
string Player::getSymbol(){ return symbol; }
void Player::setSymbol(string symbol_) { symbol = symbol_; }