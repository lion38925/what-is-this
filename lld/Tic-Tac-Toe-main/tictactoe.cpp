#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 10

class Player {
	string name;
	int rank;
	char symbol;
public:
	Player(string s, int r, char sym) {
		name = s;
		rank = r;
		symbol = sym;
	}
	string getName() {
		return name;
	}
	int getRank() {
		return rank;
	}
	char getSymbol() {
		return symbol;
	}
};

class Board {
	int size;
public:
	Board() {
		size = 3;
	}
	int getSize() {
		return size;
	}
	void setSize(int n) {
		size = n;
	}
};

class Game {
	char bd[MAX][MAX];
	queue<Player*> q;
	Board *b = new Board();
public:
	Game(int n) {
		b->setSize(n);
        memset(bd,' ',sizeof bd);
		initializeBoard();
		getPlayerDetails();
		printBoard();
	}
	void initializeBoard() {
		int n = b->getSize();
        
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < 2 * n - 1; j++) {
				if (i % 2 == 0 && j % 2 != 0) bd[i][j] = '|';
				if (i % 2 != 0 && j % 2 == 0) bd[i][j] = '-';
				if (i % 2 != 0 && j % 2 != 0) bd[i][j] = '+';
			}
		}
	}
	void getPlayerDetails() {
		for (int i = 0; i < 2; i++) {
			cout << "Enter details of player " << i + 1 << endl;
			string name;
			int rank;
			char symbol;
			cout << "Name : ";
			cin >> name;
			cout << "\nRank : ";
			cin >> rank;
			cout << "\nSymbol : ";
			cin >> symbol;
			Player *p = new Player(name, rank, symbol);
			q.push(p);
		}

		cout << "Printing Initial Board " << endl;
	}
	void printBoard() {
        int n = b->getSize();
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < 2 * n - 1; j++) {
				cout << bd[i][j] << " ";
			}
			cout << endl;
		}
	}

	bool checkWinner(int r, int c, Player * x) {
		string winner = "";
		for (int i = 0; i < b->getSize(); i++)
			winner += x->getSymbol();

		string rowString = "", colString = "", diagonalString = "", reverseDiagonalString = "";
		for (int i = 0; i < 2 * b->getSize() - 1; i += 2) {
			rowString += bd[r][i];
			colString += bd[i][c];
            if(r == c)
                diagonalString += bd[i][i];
            if(r + c == 2*b->getSize()-2)
                reverseDiagonalString += bd[2*b->getSize()-2-i][i];
		}
		if (rowString == winner || colString == winner || diagonalString == winner || reverseDiagonalString == winner)
			return true;
		return false;
	}

	int getInputRow() {
		int x;
		while (1) {
			cout << "Select row (1 - "<<b->getSize()<<") : ";
			cin >> x;
			if (x >= 1 && x <= b->getSize()) {
                int s = x-2;
                x = x+s;
                break;
            }
		}
		return x;
	}

	int getInputColumn() {
		int x;
		while (1) {
			cout << "Select column (1 - "<<b->getSize()<<") : ";
			cin >> x;
			if (x >= 1 && x <= b->getSize()) {
                int s = x-2;
                x = x+s;
                break;
            }
		}
        return x;
	}

	void play() {
		int count = 0;
		while (1) {
			count++;
			if (count > b->getSize() * b->getSize()) {
				cout << "\n\nDraw" << endl;
				break;
			}
			Player *x = q.front();
			q.pop();
            int row, col;
            do {
            cout<<"Player "<<x->getName()<<endl;
			row = getInputRow();
			col = getInputColumn();
            }while(bd[row][col] != ' ');
			bd[row][col] = x->getSymbol();
			if (checkWinner(row, col, x)) {
				cout << "\n\nPlayer " << x->getName() << " Won " << endl;
                printBoard();
				break;
			}
			printBoard();
			q.push(x);
		}
	}
};


void solve()
{
	int n;
	cout << "Enter board size  : ";
	cin >> n;
	Game *g = new Game(n);
	g->play();
}
int main()
{
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}

