
// 2048 Game (5x5 board)
//
// Description:
//   A console version of 2048 played on a 5x5 grid.
//   Slide tiles with w/a/s/d. Tiles with the same value that
//   collide merge into one tile of double the value.
//   After every move that changes the board, a new tile
//   (2 or 4) appears in a random empty cell.
//
// Controls:
//   w = up, a = left, s = down, d = right
//   k = save game, l = load game, q = quit
//   (uppercase letters also work)
//
// The game ends when the board is full and no merges are
// possible. Reaching a 2048 tile shows a congratulations
// message, but the game keeps going.
//
// Board representation:
//   int board[5][5]; a value of 0 means an empty cell.

#include <iostream>   // cin, cout, endl
#include <random>     // random_device (used to seed rand)
#include <iomanip>    // setw, setfill (aligns the board columns)
#include <fstream>    // ifstream, ofstream (save and load)

using namespace std;


// move_left
// Purpose: Slides and merges every row toward the left.
// Params:  board   - the 5x5 game board (changed in place)
//          numrows - number of rows (default 5)
// Each row is handled in three steps:
//   1. Slide all non-zero tiles to the left (remove gaps)
//   2. Merge neighbors that match (each tile merges once)
//   3. Slide again to close gaps left by merging

void move_left(int board[][5], int numrows = 5) {
    for (int r = 0; r < numrows; r++) {
        // Step 1: Slide all non-zero numbers to the left
        int temp[5] = {0};   // temporary row, starts all empty
        int pos = 0;         // next free spot in temp
        for (int c = 0; c < 5; c++) {
            if (board[r][c] != 0) {
                temp[pos++] = board[r][c];
            }
        }

        // Step 2: Merge adjacent matching numbers
        // Going left to right means the leftmost pair merges first.
        for (int c = 0; c < 4; c++) {
            if (temp[c] != 0 && temp[c] == temp[c + 1]) {
                temp[c] *= 2;      // double the left tile
                temp[c + 1] = 0;   // the right tile is absorbed
            }
        }

        // Step 3: Slide again to fill gaps created by merges
        int final_row[5] = {0};
        pos = 0;
        for (int c = 0; c < 5; c++) {
            if (temp[c] != 0) {
                final_row[pos++] = temp[c];
            }
        }

        // Copy back to the main board
        for (int c = 0; c < 5; c++) {
            board[r][c] = final_row[c];
        }
    }
}

// move_right
// Purpose: Slides and merges every row toward the right.
// Same three steps as move_left, but everything is done from
// right to left so the rightmost pair merges first.

void move_right(int board[][5], int numrows = 5) {
    for (int r = 0; r < numrows; r++) {
        // Step 1: Slide all non-zero numbers to the right
        int temp[5] = {0};
        int pos = 4;   // fill temp starting from the right end
        for (int c = 4; c >= 0; c--) {
            if (board[r][c] != 0) {
                temp[pos--] = board[r][c];
            }
        }

        // Step 2: Merge adjacent matching numbers from right to left
        for (int c = 4; c > 0; c--) {
            if (temp[c] != 0 && temp[c] == temp[c - 1]) {
                temp[c] *= 2;      // double the right tile
                temp[c - 1] = 0;   // the left tile is absorbed
            }
        }

        // Step 3: Slide again to the right
        int final_row[5] = {0};
        pos = 4;
        for (int c = 4; c >= 0; c--) {
            if (temp[c] != 0) {
                final_row[pos--] = temp[c];
            }
        }

        // Copy back to the main board
        for (int c = 0; c < 5; c++) {
            board[r][c] = final_row[c];
        }
    }
}


// move_up
// Purpose: Slides and merges every column toward the top.
// Works like move_left, but each COLUMN is treated as a line
// of tiles, read from top to bottom.

void move_up(int board[][5], int numrows = 5) {
    for (int c = 0; c < 5; c++) {
        // Step 1: Slide all non-zero numbers up
        int temp[5] = {0};
        int pos = 0;
        for (int r = 0; r < numrows; r++) {
            if (board[r][c] != 0) {
                temp[pos++] = board[r][c];
            }
        }

        // Step 2: Merge adjacent matching numbers from top to bottom
        for (int r = 0; r < numrows - 1; r++) {
            if (temp[r] != 0 && temp[r] == temp[r + 1]) {
                temp[r] *= 2;
                temp[r + 1] = 0;
            }
        }

        // Step 3: Slide again up
        int final_col[5] = {0};
        pos = 0;
        for (int r = 0; r < numrows; r++) {
            if (temp[r] != 0) {
                final_col[pos++] = temp[r];
            }
        }

        // Copy back to the main board
        for (int r = 0; r < numrows; r++) {
            board[r][c] = final_col[r];
        }
    }
}


// move_down
// Purpose: Slides and merges every column toward the bottom.
// Works like move_right, but on columns, read bottom to top.

void move_down(int board[][5], int numrows = 5) {
    for (int c = 0; c < 5; c++) {
        // Step 1: Slide all non-zero numbers down
        int temp[5] = {0};
        int pos = numrows - 1;   // fill from the bottom
        for (int r = numrows - 1; r >= 0; r--) {
            if (board[r][c] != 0) {
                temp[pos--] = board[r][c];
            }
        }

        // Step 2: Merge adjacent matching numbers from bottom to top
        for (int r = numrows - 1; r > 0; r--) {
            if (temp[r] != 0 && temp[r] == temp[r - 1]) {
                temp[r] *= 2;
                temp[r - 1] = 0;
            }
        }

        // Step 3: Slide again down
        int final_col[5] = {0};
        pos = numrows - 1;
        for (int r = numrows - 1; r >= 0; r--) {
            if (temp[r] != 0) {
                final_col[pos--] = temp[r];
            }
        }

        // Copy back to the main board
        for (int r = 0; r < numrows; r++) {
            board[r][c] = final_col[r];
        }
    }
}


// print_board
// Purpose: Draws the board in the console as a grid.
// Each cell is 6 characters wide and right-aligned. Empty
// cells (0) are printed as blank space instead of "0".

void print_board(int board[][5], int numrows = 5) {
    cout << endl << "\t-----------------------------------------" << endl;
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] > 0)
                cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
            else
                cout << "\t|" << right << setw(6) << setfill(' ') << " ";
        }
        cout << "\t|" << endl;   // close the row
        cout << "\t-----------------------------------------" << endl;
    }
    cout << "\t" << endl << endl;
}


// insert_random
// Purpose: Places a new tile (2 or 4) in a random empty cell.
// Does nothing if the board has no empty cells.
// Steps:
//   1. Count the empty cells
//   2. If there is at least one, pick random cells until an
//      empty one is found, then fill it
// Note: rand() % 2 gives 0 or 1, so 2 * (1 + 0 or 1) is
//       2 or 4, each with a 50% chance.

void insert_random(int board[][5], int numrows = 5) {
    int r, c;
    int empty_count = 0;

    // Count empty cells (the loop variables here are separate
    // from the r and c declared above)
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == 0)
                empty_count++;
        }
    }

    if (empty_count > 0) {
        // Keep guessing random positions until an empty one is found.
        // This is safe because at least one empty cell exists.
        while (true) {
            r = rand() % numrows;
            c = rand() % 5;
            if (board[r][c] == 0) {
                board[r][c] = 2 * (1 + (rand() % 2));   // 2 or 4
                break;
            }
        }
    }
}


//  Saves the current state of the board to a text file.
//  Returns 1 if the save was successful, or 0 if the file could not be opened.
//File format: 5 lines of 5 numbers each, separated by spaces.
 
int save_game(int board[][5], int numrows = 5, const char* filename = "savegame.txt") {
    ofstream outFile(filename);   // opens (or overwrites) the file

    if (!outFile) {
        return 0;   // could not open the file
    }

    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            outFile << board[r][c] << " ";   // one number plus a space
        }
        outFile << endl;                     // new line after each row
    }

    outFile.close();
    return 1;
}


 //Loads a saved board state from a text file into the game array.
 //Returns 1 if the load was successful, or 0 if the save file was missing.
 // Reads the same format that save_game writes. The file contents
 //are not checked for errors.
 */
int load_game(int board[][5], int numrows = 5, const char* filename = "savegame.txt") {
    ifstream inFile(filename);

    if (!inFile) {
        return 0;   // file missing or unreadable
    }

    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            inFile >> board[r][c];   // read the next number
        }
    }

    inFile.close();
    return 1;
}


// board_changed
// Purpose: Compares two boards cell by cell.
// Returns: 1 if any cell is different, 0 if they are identical.
// Used to tell whether a move actually did anything, so a new
// tile is only added after a move that changed the board.

int board_changed(int old_board[][5], int new_board[][5], int numrows = 5) {
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            if (old_board[r][c] != new_board[r][c]) {
                return 1;   // found a difference
            }
        }
    }
    return 0;   // no differences
}


// can_move
// Purpose: Checks whether any valid move still exists.
// Returns: 1 if the player can still move, 0 if the game is over.
// A move is possible if there is any empty cell, or any two
// neighboring cells (right or below) hold the same value.

int can_move(int board[][5], int numrows = 5) {
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == 0) return 1;   // empty cell
            if (c < 4 && board[r][c] == board[r][c + 1]) return 1;              // match to the right
            if (r < numrows - 1 && board[r][c] == board[r + 1][c]) return 1;    // match below
        }
    }
    return 0;
}


// has_won
// Purpose: Checks whether any tile has reached 2048 or higher.
// Returns: 1 if a winning tile exists, otherwise 0.

int has_won(int board[][5], int numrows = 5) {
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] >= 2048) return 1;
        }
    }
    return 0;
}


// main
// Sets up the game, then loops: show board, check win/lose,
// read a command, apply it.

int main() {
    // Seed the random number generator with a different value
    // each run so tile positions are not the same every game
    random_device rd;
    srand(rd());

    int board[5][5] = {0};    // the game board (all empty)
    int backup[5][5] = {0};   // copy of the board before each move
    char move;                // the key the player types
    int won_notified = 0;     // 1 once the win message has been shown

    // Start game with two random tiles
    insert_random(board);
    insert_random(board);

    while (true) {
        print_board(board);

        // Show the win message only once
        if (!won_notified && has_won(board)) {
            cout << "\tCongratulations! You reached 2048! Keep playing or press 'q' to quit." << endl;
            won_notified = 1;
        }

        // End the game when no moves remain
        if (!can_move(board)) {
            cout << "\tGame Over! No more valid moves." << endl;
            break;
        }

        cout << "\tEnter move (w = up, a = left, s = down, d = right, k = save, l = load, q = quit): ";
        cin >> move;

        // ---------- Commands that are not moves ----------
        if (move == 'q' || move == 'Q') {
            cout << "\tThanks for playing!" << endl;
            break;   // leave the game loop
        } else if (move == 'k' || move == 'K') {
            if (save_game(board)) {
                cout << "\tGame saved successfully!" << endl;
            } else {
                cout << "\tError: Could not write save file." << endl;
            }
            continue;   // no move was made, so no new tile
        } else if (move == 'l' || move == 'L') {
            if (load_game(board)) {
                cout << "\tGame loaded successfully!" << endl;
                // If the loaded board already has 2048, do not show the message again
                won_notified = has_won(board);
            } else {
                cout << "\tError: No save file found." << endl;
            }
            continue;
        }

        // Save current board state before moving
        // (used afterward to see whether the move changed anything)
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                backup[r][c] = board[r][c];
            }
        }

        // ---------- Movement commands ----------
        if (move == 'w' || move == 'W') {
            move_up(board);
        } else if (move == 'a' || move == 'A') {
            move_left(board);
        } else if (move == 's' || move == 'S') {
            move_down(board);
        } else if (move == 'd' || move == 'D') {
            move_right(board);
        } else {
            cout << "\tInvalid input! Please use w, a, s, d, k, l, or q." << endl;
            continue;   // skip adding a tile
        }

        // Only spawn a new tile if the move actually shifted or merged tiles
        if (board_changed(backup, board)) {
            insert_random(board);
        }
    }

    return 0;   // program finished normally
}
