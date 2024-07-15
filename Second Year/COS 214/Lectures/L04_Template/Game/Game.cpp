/** * An abstract class that is common to several games in 
 * which players play against the others, but only one game
 is active at a given time. */
 
 #include<iostream>
using namespace std;

 class Game // Abstract
 {
  	public:
	 	Game(int thePlayerCount);
	 	/* A template method : */
	 	void playOneGame();
  	protected:
	 	int playerCount;
  	private:
	 	virtual void initializeGame()  = 0;
	 	virtual void makePlay(int player) = 0;
	 	virtual bool endOfGame()  = 0;
	 	virtual void printWinner()  = 0;
};

class Monopoly : public Game 
{
	public:
		Monopoly(int thePlayerCount);
	private:

		void initializeGame() ; 
		void makePlay(int player) ; 
		bool endOfGame() ; 
		void printWinner() ;
	
		bool playerHasMoney[6];
};

class Chess : public Game 
{
	public:
		Chess();
	private:
		void initializeGame() ; 
		void makePlay(int player) ; 
		bool endOfGame() ; 
		void printWinner() ; 

		bool done, draw, whiteWin;
};

Game :: Game(int thePlayerCount) : 
	playerCount(thePlayerCount) 
{}
	
void Game :: playOneGame() 
{ 
	initializeGame(); 
	int j = 0; 
	while (!endOfGame()) 
	{ 
		makePlay(j); 
		j = (j + 1) % playerCount; 
	} 
	printWinner(); 
}

Monopoly :: Monopoly(int thePlayerCount) : 
	Game(thePlayerCount) 
{}
	
void  Monopoly :: initializeGame() 
{ 
	// Initialize money
	for (int i = 0; i < playerCount; i++)
	{ 
		playerHasMoney[i] = true;
	}
	cout << "Initialising money" << endl;
}

void Monopoly :: makePlay(int player) 
{ 
	// Process one turn of player 
	if  (playerHasMoney[player])
	{
		cout <<  "\nPlayer " << player  << ": " << endl;
		cout << "Collect rent if applicable and optionally buy/sell property" << endl;
		cout << "rolls dice" << endl;
		cout << "Complete move resulting from dice roll" << endl;
		cout << "How much money has player " << player << " left ? ";
		int balance;
		cin >> balance;
		playerHasMoney[player] = (balance > 0);
	}
} 

bool Monopoly ::  endOfGame() 
{ 
	int activePlayerCount  = 0;
	for (int i = 0; i < playerCount; i++)
	{ 
		if (playerHasMoney[i]) activePlayerCount++;
	}		
	return (activePlayerCount == 1);
} 

void Monopoly :: printWinner() 
{
	// Display who won 
	for (int i = 0; i < playerCount; i++)
	{ 
		if (playerHasMoney[i]) 
			cout << "\nPlayer " << i << " won" << endl;
	}
}	

Chess :: Chess() : 
	Game(2),
	done(false),
	draw(false),
	whiteWin(false)
{}
	
void  Chess :: initializeGame() 
{ 
	cout << " Put the pieces on the board " << endl;
}

void  Chess :: makePlay(int player) 
{ 
	// Process one turn of player 
	cout <<  "\nPlayer " << player  << ": " << endl;
	cout << "Make a valid move" << endl;
	
	cout << "0 Next player can move" << endl;
	cout <<  "1 Next player is in Checkmate" << endl;
	cout << "2 Next player is in Stalemate" << endl;
	int state;
	cout << "Please enter :";
	cin >> state;
	switch (state)
	{
		case 1 :  whiteWin = (player == 0);
			done = true;
			break;
		case 2 :  done = draw = true;
			break;
		default : return ;
	}
} 

bool Chess ::  endOfGame() 
{ 
	return done;
}
    
void Chess :: printWinner() 
{
	// Display who won 
	if (draw)
		cout << "Its a draw" << endl;
	else
		if(whiteWin)
			cout << "White (Player 0) won " << endl;
		else
			cout << "Black (Player 1) won " << endl;
}

int main ()
{
	Game* g;
	int c, n;
	cout << "1 Monopoly" << endl;
	cout << "2 Chess "  << endl;
	cout << "Your choice: ";
	cin >> c;
	if (c == 1)
	{
		cout << "Number of players: " ;
		cin >> n;
		g = new Monopoly(n);
	}
	else if (c == 2)
	{
		g = new Chess();
	}
	g->playOneGame();
	
	// Note: make sure the objects are deleted from the heap.
	// delete g; generates a warning
	// Game does not have a virtual destructor.
	// Fix the code so that there are no warnings.
}
