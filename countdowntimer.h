#define NUMBERS 24
#define SEC 1
#define MIN 1
#define MAX 10

// 関数の定義
void printTitle(char title[]);
void displayTimer(int minutes, int seconds);
int setTime();
void countDown(int minutes, int seconds);
char stateOpinion(char answer[]);
int selectNumOfStu();
int generateScopeRanNum(int students[]);
void shuffle(int students[], unsigned int size);
void getRandomStu(int students[], int count);