#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int target, guess, attempts = 0;
    srand(time(NULL));
    target = rand() % 100 + 1; // 1~100的随机数

    printf("欢迎来到猜数字游戏！我已经选好了1~100之间的一个数字。\n");

    do {
        printf("请输入你的猜测：");
        scanf("%d", &guess);
        attempts++;

        if (guess < target) {
            printf("太小了！\n");
        }
        else if (guess > target) {
            printf("太大了！\n");
        }
        else {
            printf("恭喜你，猜对了！你总共猜了%d次。\n", attempts);
        }
    } while (guess != target);

    return 0;
}