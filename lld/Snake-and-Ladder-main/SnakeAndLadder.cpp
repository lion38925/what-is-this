#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class dice {
public:
	int roll() {
		return (1 + rand() % 6);
	}
};

class player {
	string name;
	int position;
	bool won;
public:
	player(string n) {
		name = n;
		position = 0;
		won = false;
	}
	string getName() {
		return name;
	}
	int getPosition() {
		return position;
	}
	void setPosition(int p) {
		position = p;
	}
	void setWon(bool x) {
		won = x;
	}
};

class board {
	int size;
public:
	board() {
		size = 30;
	}
	int getSize() {
		return size;
	}
	void setSize(int s) {
		size = s;
	}
};
// class which are initialzed at the start so no setter for them.
class snake {
	int start;
	int end;
public:
	snake(int s, int e) {
		start = s;
		end = e;
	}
	int getStartSnake() {
		return start;
	}
	int getEndSnake() {
		return end;
	}
};

class ladder {
	int start;
	int end;
public:
	ladder(int s, int e) {
		start = s;
		end = e;
	}
	int getStartLadder() {
		return start;
	}
	int getEndLadder() {
		return end;
	}
};

class game {
	int numberOfSnakes, numberOfLadders;
	vector<snake*> s;
	vector<ladder*> l;
	queue<player*> players;
	board *bd = new board();
	dice *de = new dice();
public:
	game(vector<pair<int, int>> a, vector<pair<int, int>> b, int st, int lt, int n, int p, vector<string> v) {
		numberOfSnakes = st;
		numberOfLadders = lt;
		bd->setSize(n);
		// cout << "Snake : " << endl;
		for (int i = 0; i < numberOfSnakes; i++) {
			snake *snakeobj = new snake(a[i].first, a[i].second);
			s.push_back(snakeobj);
		}
		// cout << "Ladder pushing: " << endl;
		for (int i = 0; i < numberOfLadders; i++) {
			ladder *ladderobj = new ladder(b[i].first, b[i].second);
			l.push_back(ladderobj);
		}
		// cout << "player pushing : " << endl;
		for (int i = 0; i < p; i++) {
			player *x = new player(v[i]);
			players.push(x);
		}
	}
	void play() {
		while (true) {
			player *x = players.front();
			players.pop();
			int diceVal = de->roll();
			cout << "Dice value : " << diceVal << endl;
			int oldpos = x->getPosition();
			int newpos = oldpos + diceVal;
			if (newpos > bd->getSize()) {
				x->setPosition(oldpos);
				cout << "Player " << x->getName() << " moved from " << oldpos << " to " << x->getPosition() << endl;
				players.push(x);
			}
			else {
				x->setPosition(getNewPosition(newpos));
				if (x->getPosition() == bd->getSize()) {
					x->setWon(true);
					cout << "Player " << x->getName() << " won" << endl;
				}
				else {
					cout << "Player " << x->getName() << " moved from " << oldpos << " to " << x->getPosition() << endl;
					players.push(x);
				}
			}
			if (players.size() < 2)
				break;
		}
	}
	int getNewPosition(int pos) {
		for (snake *sk : s) {
			if (sk->getEndSnake() == pos) {
				cout << "Snake bit" << endl;
				pos = sk->getStartSnake();
			}
		}
		for (ladder *ld : l) {
			if (ld->getStartLadder() == pos) {
				cout << "Ladder up" << endl;
				pos = ld->getEndLadder();
			}
		}
		return pos;
	}
};



void solve()
{
	int n ;
	cin >> n;
	int s, l, p;
	vector<pair<int, int>> sk, ld;
	vector<string> v;
	// input number of snakes
	cin >> s;
	for (int i = 0; i < s; i++) {
		int x, y;
		cin >> x >> y;
		sk.push_back({x, y});
	}
	// input number of ladders
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x, y;
		cin >> x >> y;
		ld.push_back({x, y});
	}
	cin >> p;
	for (int i = 0; i < p; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	cout << "Entering game : " << endl;
	game *g = new game(sk, ld, s, l, n, p, v);
	g->play();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}

