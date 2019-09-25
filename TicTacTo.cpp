#include <iostream>

using namespace std;
const int SIZE = 3; // Dimension of game board


void testPrint(int *);
bool decideFirst();
void makeMove(int *a, bool playerTurn);
bool checkWinner(int *a, bool exit);
void endGame(int winner);
void initializeGameBoard (int *a);
void displayGameBoard(int *a);


void displayGameBoard(int *a){
    char valueAtIndex;
    cout << "-------------------------" << endl;
    for (int row = 0; row < SIZE; row++){
        for (int column = 0; column < SIZE; column++) {
            valueAtIndex = a[row*SIZE + column];
            
            if(valueAtIndex == 1){
                cout << "|   " << "X" << "   ";
            }
            else if(valueAtIndex == 2){
                cout << "|   " << "O" << "   ";
            }
            else{
                cout << "|   " << " " << "   ";
            }
        }
        cout << "|" << endl << "-------------------------" << endl; // Row break
    }
}
void initializeGameBoard (int *a){ // Sets every game board value to 0
    for (int n = 0; n < SIZE; n++){
        for (int m = 0; m < SIZE; m++) {
            a[n*SIZE+m] = 0;
        }
    }
}

void endGame(int winner){
    if (winner == 1){cout << "GAME OVER: Congratulations Player X, You Win! ";}
    else if (winner == 2){cout << "GAME OVER: Congratulations Player O, You Win! ";}
    }

void makeMove(int *a, bool playerTurn){
    int userRow, userColumn;

    if (playerTurn) {cout << "It is Player X's Turn" << endl;}
    else { cout << "It is Player O's Turn" << endl;}

    cout << "Please select a row (0-2): ";
    cin >> userRow;
    if (userRow < 0 || userRow > 2){ // Input validation
        while(userRow < 0 || userRow > 2){
            cout << "Invalid entry, please select a row (0-2): ";
            cin >> userRow;
        }
    }

    cout << "Please select a column (0-2): ";
    cin >> userColumn;
    if (userColumn < 0 || userColumn > 2){ // Input validation
        while(userColumn < 0 || userColumn > 2){
            cout << "Invalid entry, please select a column (0-2): ";
            cin >> userColumn;
        }
    }

    if (*( a + (userRow * SIZE + userColumn)) != 0) { // Input validation
        while (*( a + (userRow * SIZE + userColumn)) != 0){
            cout << "Invalid move, that space is already taken" << endl;
            
            cout << "Please select a row (0-2): ";
            cin >> userRow;
            if (userRow < 0 || userRow > 2){ // Input validation
                while(userRow < 0 || userRow > 2){
                    cout << "Invalid entry, please select a row (0-2): ";
                    cin >> userRow;
                }
            }
            
            cout << "Please select a column (0-2): ";
            cin >> userColumn;
            
            if (userColumn < 0 || userColumn > 2){ // Input validation
                while(userColumn < 0 || userColumn > 2){
                    cout << "Invalid entry, please select a column (0-2): ";
                    cin >> userColumn;
                }
            }
        }
        if (playerTurn){*( a + (userRow * SIZE + userColumn)) = 1;}
        else{*( a + (userRow * SIZE + userColumn)) = 2;}

    }
    else if (playerTurn){*( a + (userRow * SIZE + userColumn)) = 1;}
    else{*( a + (userRow * SIZE + userColumn)) = 2;}

}
bool checkWinner(int *a, bool exit){ // Returns true if X wins, false if O wins
    if (a[0] == 1 && a[1] == 1 && a[2] == 1){endGame(1);} // All possible Player X win scenarios
    else if (a[3] == 1 && a[4] == 1 && a[5] == 1){
        endGame(1);
        exit = true;
        return exit;
    }
    else if (a[6] == 1 && a[7] == 1 && a[8] == 1){
        endGame(1);
        exit = true;
        return exit;
    }
    else if (a[0] == 1 && a[3] == 1 && a[6] == 1){
        endGame(1);
        exit = true;
        return exit;
    }
    else if (a[1] == 1 && a[4] == 1 && a[7] == 1){
        endGame(1);
        exit = true;
        return exit;
    }
    else if (a[2] == 1 && a[5] == 1 && a[8] == 1){
        endGame(1);
        exit = true;
        return exit;
    }
    else if (a[0] == 1 && a[4] == 1 && a[8] == 1){
        endGame(1);
        exit = true;
        return exit;
    }
    else if (a[6] == 1 && a[4] == 1 && a[2] == 1){
        endGame(1);
        exit = true;
        return exit;
    }

    else if (a[3] == 2 && a[4] == 2 && a[5] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    
    // All possible Player O win scenarios
    else if (a[3] == 2 && a[4] == 2 && a[5] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else if (a[6] == 2 && a[7] == 2 && a[8] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else if (a[0] == 2 && a[3] == 2 && a[6] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else if (a[1] == 2 && a[4] == 2 && a[7] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else if (a[2] == 2 && a[5] == 2 && a[8] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else if (a[0] == 2 && a[4] == 2 && a[8] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else if (a[6] == 2 && a[4] == 2 && a[2] == 2){
        endGame(2);
        exit = true;
        return exit;
    }
    else {
        if(a[0] != 0 && a[1] != 0 && a[2] != 0 && a[3] != 0 && a[4] != 0 && a[5] != 0 && a[6] != 0 && a[7] != 0 && a[8] != 0){
            cout<< "GAME OVER: The game has ended in a tie " << endl; // Tie otherwise
            exit = true;
            return exit;
        }
    }
    return false;

}

bool decideFirst(){ // Decides which player goes first, True: Player X, False: Player O
    int random = rand()%2;
    bool first;

    if(first == 1) {first = true;}
    else {first = false;}

    return first;
}

int main() {
	int* gameBoard = new int[9]; // Row 1: 0-2, Row 2: 3-5, Row 3: 6-9

	bool playerTurn = decideFirst();
	bool exit = false;
	initializeGameBoard(gameBoard);
	makeMove(gameBoard, playerTurn);
	displayGameBoard(gameBoard);
	checkWinner(gameBoard, exit);

	while (exit == false) {
		if (playerTurn) { playerTurn = false; } // Alternates turns
		else { playerTurn = true; }

		makeMove(gameBoard, playerTurn);
		displayGameBoard(gameBoard);
		exit = checkWinner(gameBoard, exit);
	}
}



