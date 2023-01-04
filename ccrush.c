#include "ccrush.h"
#include <stdio.h>

/*
  This file will contain all code for the main execution loop.  This
  code should be kept simple and concise. Functions containing more
  specialized behaviors will be placed in other files.
*/

/* P1 - Modify main function to make a game board and print it */
/* P2 - Add a "game loop" that accepts input from the user until
        a quit key is pressed, modifying the board based on the
        key pressed */
int main(void) {
  int keep_looping = 0;
  char cmd;

  board_t game = load_board(MAP, BOARDSIZE);
  print_board(game);

  while(keep_looping == 0){
    scanf("%c", &cmd);

    keep_looping = process_command(cmd, &game);
    game_logic(&game);
    print_board(game);
  }
}
