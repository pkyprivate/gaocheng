//2151753 ?????? ?ƿ?
void line_row(int* line, int* row);
void base(int line, int row, int choose);
void set(int s[11][11], int line, int row, int number,int num[8]);
void choice1(int s[11][11],int line ,int row);
void choice2(int s[11][11], int line, int row);
void choice3(int s[11][11], int line, int row);
void choice4(int s[11][11], int line, int row);
void choice5(int s[11][11], int line, int row);
void choice6(int s[11][11], int line, int row);
void choice7(int s[11][11], int line, int row,int num[8]);
int findway(int s1[11][11], char start[3], char end[3], int line, int row, int choose);
void atoA(char* s);
void reset(int s[11][11], int line, int row);
void start_input(int s[11][11], int line, int row, char t[3]);
void end_input(int s[11][11], int line, int row, char t[3]);
void print(int s[11][11], int line, int row, int choose);
void the_enter();
void set_cmd(int line, int x);
void reset_cmd();
void addthree(int s[11][11], int next[3], int line, int row);
void clear(int line);
void nextthree(int* next);
int judge(int s[11][11], int line, int row, int move_x, int move_y, int* p);
void goback(int s[11][11]);
