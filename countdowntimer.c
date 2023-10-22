#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "countdowntimer.h"

int main(void){
    char title[] = "あなたのハートにカウントダウン！";
    char answer[2];
    int seconds = 0;
    int minutes, count;
    int students[NUMBERS];

    // タイトルを表示
    printTitle(title);

    // 時間設定
    minutes = setTime();

    // カウントダウンタイマー表示
    displayTimer(minutes, seconds);

    // カウントダウン処理
    countDown(minutes, seconds);

    do{
        // 感想を求めるかどうか
        stateOpinion(answer);

        if (strcmp(answer,"y") == 0){
            while(1){
                 /* 生徒数を入力 */
                count = selectNumOfStu();

                /* 乱数の範囲を生成(1〜24) */
                generateScopeRanNum(students);

                /* students配列の中身をシャッフル */
                shuffle(students, NUMBERS);

                /* (重複なし)ランダムに生徒を選択*/
                getRandomStu(students, count);

                // もう一度感想を求めるかどうか
                stateOpinion(answer);
                if (strcmp(answer, "n") == 0) break;
            }
        }
    } while (answer[0] == '\0');

    printf("終了します。\n");

    return 0;
}
