#include <stdio.h>
#include "ccrush.h"
#include "symbols.h"
#include <stdlib.h>

/*
 This file contains code for managing the game board.  This includes
 functions like building and printing the board.
*/

/* P2 - Define process_command (see assignment for instructions) */
int process_command(char cmd, board_t* game) {
  /* Replace this return statement with the functionality described in the assignment */
  int left = -1;
  int right = 1;
  int up = 1;
  int down = -1;
  int temp;

  if(cmd == 'a' && game->cursor.x > 0){
    game->cursor.x += left;

  }else if(cmd == 'd' && game->cursor.x < game->size - 2){
    game->cursor.x += right;

  }else if(cmd == 'w' && game->cursor.y < game->size - 1){
    game->cursor.y += up;

  }else if(cmd == 's' && game->cursor.y > 0){
    game->cursor.y += down;

  }else if(cmd == 'q'){
    return 1;

  }else if(cmd == 'e'){
    temp = game->board[game->cursor.y][game->cursor.x];
    game->board[game->cursor.y][game->cursor.x] = game->board[game->cursor.y][game->cursor.x + 1];
    game->board[game->cursor.y][game->cursor.x + 1] = temp;

  }else{
    printf("Incorrect Input\n");
    return 0;
  }
  
  return 0;
}

/* P2 - Define game_logic (see assignment for instructions) */
void game_logic(board_t* game) {
  for(int i = BOARDSIZE - 1; i >= 0; i--){
    for(int j = 0; j < BOARDSIZE; j++){
      if(game->board[i][j] == game->board[i][j + 1] && game->board[i][j + 1] == game->board[i][j + 2]){
        game->board[i][j] = 7;
        game->board[i][j + 1] = 7;
        game->board[i][j + 2] = 7;

      }

      // printf("%d\n", game->board[i][j]);
      // printf("%d\n", game->board[i + 1][j]);
      // printf("%d\n", game->board[i + 2][j]);

      // if(game->board[i][j] == game->board[i + 1][j] && game->board[i + 1][j] == game->board[i + 2][j]){
      //   game->board[i][j] = 7;
      //   game->board[i + 1][j] = 7;
      //   game->board[i + 2][j] = 7;
      // }
    } 
  }
}
