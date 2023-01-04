#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ccrush.h"
#include "symbols.h"

char* SHAPES[] = {Y, G, W, P, B, R, O, S};

/*
 This file contains code for managing the game board.  This includes
 functions like building and printing the board.
*/

/* P1 - Define print_board (see assignment for instructions) */
void print_board(board_t game){
	// "Clears" the board printing new lines
	system("clear");

	for(int x = 0; x <  50; x++){
		printf("\n");
	}

	// prints the top boarder
	printf("+");
	for(int n = 0; n < (2 * game.size) + 1; n++){
		printf("-");
	}
	printf("+\n");

	// This iterates through the outer array backwards, I have no idea why it did't print correctly when I did it in accending order
	for(int i = game.size - 1; i >= 0; i--){
		printf("|");

			// This iterates through the inner array corresponding to i
      for(int j = 0; j < game.size; j++){

				// Prints the cursor and ensures correct spacing
				if(j == game.cursor.x && i == game.cursor.y){
					if(game.cursor.x != 0){
						printf("\b");
					}
					
					printf("<");
				}else if(j == 0){
					printf(" ");
				}

				//prints the characters
        		printf("%s", SHAPES[game.board[i][j]]);

				// Prints the cursor and ensures correct spacing
				if(j == game.cursor.x + 1 && i == game.cursor.y){
					printf(">");
				}else if(j == game.size -1){
					printf(" ");
				}else{
					printf(" ");
				}
				// else if(j + 1 != game.cursor.x){
				// 	printf(" ");
				// }
      }

			printf("|");
			printf("\n");
    }

		// pints the bottom boarder
		printf("+");

		for(int n2 = 0; n2 < (2 * game.size) + 1; n2++){
			printf("-");
		}

		printf("+\n");
}


/* P1 - Define build_board (see assignment for instructions) */
board_t load_board(const char* filepath, int size){
	// initailizing map
	board_t map;

	// this casts the malloc to the the multidimentional integer array correctly setting it's size by multiplying the size variable by the size of the int**
	map.board = (int**)malloc(size * sizeof(int*));

	// Thit loop goes through the 2nd dimension of the array mallocing for each one
	for(int i = 0; i < size; i++){
		map.board[i] = (int*)malloc(size * sizeof(int));
	}

	// saves the map.size from the BOARDSIZE macro
	map.size = size;

	// staring cursor position should be (0,0)
	map.cursor.x = 0;
	map.cursor.y = 0;

	// opens the file in read mode and saves it to a file pointer
  FILE * map_file = fopen(filepath, "r");

	// saves the current character being pulled with getc so I can use atoi() on it and add it to the array
	char curr_char;

	// Iterates through the file assigning the values to the 2D array
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){

  		curr_char = fgetc(map_file);

			// This checks if the current character is a new line and if it is it runs get char again to skip over it
			if(curr_char == '\n'){
				curr_char = fgetc(map_file);
			}

			// Converts the ascii value to its actual character
			map.board[i][j] = atoi(&curr_char);
		}
	}

	// Closing the file and returning the board_t map
	fclose(map_file);
	return map;
}
