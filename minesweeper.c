#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 100  
int move_rows[MAX_MOVES];  
int move_cols[MAX_MOVES];  
int move_top = -1;  

/* Generate the board with random mines */
void generateBoard() {
    srand(time(NULL));
    int N = rand() % 9 + 2;  /* Random board size between 2 and 10 */
    int totalCells = N * N;
    int minMines = totalCells / 10;
    int maxMines = totalCells / 4;
    int numMines = rand() % (maxMines - minMines + 1) + minMines;
	
    int i, j;
    char board[10][10];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }

    int minesPlaced = 0;
    while (minesPlaced < numMines) {
        int row = rand() % N;
        int col = rand() % N;
        if (board[row][col] != '*') {
            board[row][col] = '*';
            minesPlaced++;
        }
    }

    FILE *file = fopen("map.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "  ");  /* Space for row numbers*/
    for (j = 0; j < N; j++) {
        fprintf(file, "%d ", j);
    }
    fprintf(file, "\n");
	
    for (i = 0; i < N; i++) {
        fprintf(file, "%d ", i);  /* Row number */
        for (j = 0; j < N; j++) {
            fprintf(file, "%c ", board[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    
    /* Initialize moves.txt as empty with 0 moves */
    FILE *movesFile = fopen("moves.txt", "w");
    if (movesFile != NULL) {
        fprintf(movesFile, "Total Moves: 0\n");
        fclose(movesFile);
    }
}

/* Load the map from "map.txt" into a 2D array */
void loadMap(char board[10][10], int *size) {
    FILE *file;
    int i, j, header;

    file = fopen("map.txt", "r");
    if (file == NULL) {
        printf("Error opening map.txt file.\n");
        return;
    }

    /* Skip the first two spaces before column headers */
    fscanf(file, " ");

    /* Read column numbers and discard them */
    for (i = 0; i < 10; i++) {
        if (fscanf(file, "%d", &header) != 1) {
            break;
        }
    }

    *size = i;

    for (i = 0; i < *size; i++) {
        fscanf(file, "%d", &header);
        for (j = 0; j < *size; j++) {
            fscanf(file, " %c", &board[i][j]);
        }
    }

    fclose(file);
}

/* Push the move onto the stack */
void push(int row, int col) {
    if (move_top < MAX_MOVES - 1) {
        move_top++;
        move_rows[move_top] = row;
        move_cols[move_top] = col;
    }
}

/* Pop the last move from the stack */
void pop() {
    if (move_top >= 0) {
        move_top--;
    }
}

/* Save moves log to "moves.txt" */
void saveMoves() {
	int i;
    FILE *file = fopen("moves.txt", "w");
    if (file == NULL) {
        printf("Error opening moves.txt file!\n");
        return;
    }

    /* Write each move from the stack */
    for (i = 0; i <= move_top; i++) {
        fprintf(file, "move %d: (row %d, col %d)\n", i + 1, move_rows[i], move_cols[i]);
    }
    
    /* Write the total number of moves */
    fprintf(file, "Total Moves: %d\n", move_top + 1);

    fclose(file);
}

/* Undo a move */
void undo(char playerBoard[10][10], int size) {
    if (move_top >= 0) {
        int row = move_rows[move_top];
        int col = move_cols[move_top];
        playerBoard[row][col] = '#';  /* Reset to unplayed */
        pop();
        saveMoves();  /* Save updated moves log after undo */
    }
}

/* Display the current state of the game */
void displayMap(char playerBoard[10][10], int size) {
    int i, j;
    
    /* Display column headers */
    printf("  ");
    for (j = 0; j < size; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < size; i++) {
        printf("%d ", i);  /* Row number */
        for (j = 0; j < size; j++) {
            printf("%c ", playerBoard[i][j]);
        }
        printf("\n");
    }
}

/* Check the surrounding cells for mines and return the count */
int countMines(char board[10][10], int row, int col, int size) {
    int i;
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; /*N, S, W, E, NW, NE, SW, SE*/

    int mineCount = 0;
    for (i = 0; i < 8; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
            if (board[newRow][newCol] == '*') {
                mineCount++;
            }
        }
    }
    return mineCount;
}

int main() {
    int size;
    char board[10][10];      /* The actual game board with mines */
    char playerBoard[10][10]; /* The player's view board */

    /* Generate the board and save it to map.txt*/
    generateBoard();

    /* Load the board from map.txt*/
    loadMap(board, &size);

    /* Initialize player's view board */
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            playerBoard[i][j] = '#';  /* Initially all cells are hidden */
        }
    }

    /* Display the board size to the user*/
    printf("The board size is %d x %d.\n", size, size);

    int choice, row, col;

    while (1) {
        /* Display the current state of the board */
        displayMap(playerBoard, size);
        
        printf("Enter 1 for a move, or 0 to undo: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter row and column (e.g., 2 3): ");
            scanf("%d %d", &row, &col);

            if (row < 0 || col < 0 || row >= size || col >= size) {
                printf("Invalid coordinates.\n");
            } else {
                if (board[row][col] == '*') {
                    printf("Game over! You hit a mine!\n");
                    break;
                } else {
                    int surroundingMines = countMines(board, row, col, size);
                    playerBoard[row][col] = '0' + surroundingMines;  /* Convert count to character */
                    push(row, col);  /* Push move onto stack*/
                    saveMoves();  /* Save the move log to moves.txt*/
                }
            }
        } else if (choice == 0) {
            undo(playerBoard, size);
            printf("Last move undone.\n");
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}
