#include <fstream>
/**
 * Saves the current state of the board to a text file.
 * Returns 1 if the save was successful, or 0 if the file could not be opened.
 *
 * Parameters:
 *   board    - 2D array holding the game board (5 columns per row)
 *   numrows  - number of rows in the board (defaults to 5)
 *   filename - name of the file to write to (defaults to "savegame.txt")
 */
int save_game(int board[][5], int numrows = 5, string filename = "savegame.txt") {
                                                                                                 // Open the file for writing (creates it, or overwrites it if it exists)
    ofstream outFile(filename);
    
                                                                                                 // If the file couldn't be created/opened, the stream evaluates to false
    if (!outFile) {
                                                                                                 // Return failure flag if the file cannot be created/opened
        return 0; 
    }
    
                                                                                                 // Go through every row of the board
    for (int r = 0; r < numrows; r++) {
                                                                                                 // Go through every column in the current row
        for (int c = 0; c < 5; c++) {
                                                                                                 // Write the cell value followed by a space so values stay separated
            outFile << board[r][c] << " ";
        }
                                                                                                 // Start a new line after each row so the file mirrors the board layout
        outFile << endl;
    }
    
                                                                                                 // Close the file to make sure everything is written to disk
    outFile.close();
                                                                                                 // Signal that the save succeeded
    return 1;
}

/**
 * Loads a saved board state from a text file into the game array.
 * Returns 1 if the load was successful, or 0 if the save file was missing.
 *
 * Parameters:
 *   board    - 2D array that will be filled with the saved values
 *   numrows  - number of rows in the board (defaults to 5)
 *   filename - name of the file to read from (defaults to "savegame.txt")
 */
int load_game(int board[][5], int numrows = 5, string filename = "savegame.txt") {
                                                                                                 // Open the file for reading
    ifstream inFile(filename);
    
                                                                                                 // If the file doesn't exist or can't be opened, the stream evaluates to false
    if (!inFile) {
                                                                                                 // Return failure flag if the file does not exist
        return 0; 
    }
    
                                                                                                 // Go through every row of the board
    for (int r = 0; r < numrows; r++) {
                                                                                                 // Go through every column in the current row
        for (int c = 0; c < 5; c++) {
                                                                                                 // Read the next number from the file into the matching board cell
                                                                                                 // (>> skips the spaces and newlines the save function wrote)
            inFile >> board[r][c];
        }
    }


//IMPLEMENT vvvvvv

// Variable to store the player's menu selection
int choice;
                                                                                                    // Show the menu and prompt for a choice
cout << "1. Save Game\n2. Load Game\nChoice: ";
cin >> choice;

                                                                                                    // Option 1: save the current board to the file
if (choice == 1) {
                                                                                                    // save_game returns 1 (true) on success, 0 (false) on failure
    if (save_game(board)) {
        cout << "Game saved successfully!" << endl;
    } else {
                                                                                                    // File couldn't be opened for writing
        cout << "Error: Could not write save file." << endl;
    }
                                                                                                    // Option 2: load a previously saved board from the file
} else if (choice == 2) {
                                                                                                    // load_game returns 1 (true) on success, 0 (false) if the file is missing
    if (load_game(board)) {
        cout << "Game loaded successfully!" << endl;
                                                                                                    // Display the loaded board so the player can see the restored state
        print_board(board);
    } else {
                                                                                                    // Save file doesn't exist
        cout << "Error: No save file found." << endl;
    }
}