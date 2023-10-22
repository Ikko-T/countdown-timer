#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "countdowntimer.h"

// ゲームタイトル表示
void printTitle(char title[])
{
    printf("\n\t%s\n\n", title);
    
    sleep(SEC);
}

// 時間設定の関数
int setTime(){
    int minutes;

    do{
        printf("\t%d～%dの間を分単位で入力\n時間を入力しエンターを押下したら開始します -> ", MIN, MAX);
        scanf("%d", &minutes);
    }while(!(MIN <= minutes && minutes <= MAX));

    return minutes;
}

// タイマー表示の関数
void displayTimer(int minutes, int seconds)
{
    system("clear");
    printf("\x1b[41m**************************************\n");
    printf("               %02d : %02d                \n", minutes, seconds);
    printf("**************************************\x1b[0m\n");
    sleep(SEC);
}


// カウントダウン関数
void countDown(int minutes, int seconds){
    seconds = 59;
    minutes -= 1;

    while(1){
        displayTimer(minutes, seconds);
        seconds -= 1;

        if(minutes==0 && seconds==0){
            displayTimer(minutes, seconds);
            printf("\n\n\t\t終了!!!!\n\n\n");
            break;
        }

        if(seconds == 0){
            seconds = 59;
            minutes -= 1;
        }
    }
}

// 感想人の選択有無関数
char stateOpinion(char answer[]){
    printf("感想を述べる人をランダムで選びますか？\n");
    printf("はい -> y\tいいえ -> n\n => ");
    scanf("%s", answer);

    if(strcmp(answer,"y") == 0){
        answer[0] = 'y';
    }else if(strcmp(answer,"n") == 0){
        answer[0] = 'n';
    }else{
        answer[0] = '\0';
    }
    
    printf("\n");

    return answer[2];
}

// 生徒の人数取得関数
int selectNumOfStu(){
    unsigned int count;

    do{
        printf("%d人中、何人分表示しますか? => ", NUMBERS);
        scanf("%d", &count);
    } while (count > NUMBERS);

    return count;
}

// 乱数範囲の生成関数
int generateScopeRanNum(int students[]){
    srand((unsigned int)time(NULL));

    for (int i = 0; i < NUMBERS; i++) {
        students[i] = i + 1;
    }

    return students[NUMBERS];
}

// シャッフル関数
void shuffle(int students[], unsigned int size) {
    unsigned int lastIndex, randomIndex;
    int tmp;

    /* シャッフル範囲の末尾を設定 */
    lastIndex = size - 1;

    while (lastIndex > 0) {
        /* シャッフル範囲（0〜lastIndex）からランダムに１つデータを選択 */
        randomIndex = rand() % (lastIndex + 1);

        /* ランダムに選択されたデータとシャッフル範囲の末尾のデータを交換 */
        tmp = students[randomIndex];
        students[randomIndex] = students[lastIndex];
        students[lastIndex] = tmp;

        /* シャッフル範囲を狭める */
        lastIndex--;
    } 

    printf("\n");
}

// 重複なし乱数の取得と表示関数
void getRandomStu(int students[], int count){
    unsigned int randomNumber;

    for (int i = 0; i < count; i++) {
        randomNumber = students[i];
        printf("%d番の人が選ばれました。\n", randomNumber);
        sleep(SEC);
    }

    printf("\n");
}