#define BOARDSIZE 8
#define MAP "maps/map1.dat"

typedef struct _cursor {
  int x;
  int y;
} cursor_t;

typedef struct _board {
  int** board;
  cursor_t cursor;
  int size;
} board_t;

/* Part 1 */
board_t load_board(const char*, int);
void print_board(board_t);

/* Part 2 */
int process_command(char, board_t*);
void game_logic(board_t*);

/*
The following functions are versions of the assigned work as
written by the teaching staff and can be called when needed
as described in the assignment.
*/
void PROF_print_board(board_t);
board_t PROF_load_board(const char*, int);
int PROF_process_command(char, board_t*);
void PROF_game_logic(board_t*);
