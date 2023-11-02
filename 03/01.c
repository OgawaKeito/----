#include <stdio.h>
#include <stdlib.h>

int figure[100][3];
int pre, point;
int pre_, point_;

void main(void)
{
    printf("figure[ 1][2] =");
    scanf("%d", &figure[1][2]);
    figure[1][0] = 0;
    figure[0][0] = 1;
    pre = 1;
    point = 1; /* 1. 最初の値代入*/
    for (int i = 2; i < 100; i++)
    {
        printf("figure[%2d][2] =", i);
        scanf("%d", &figure[i][2]); /* 2. 二番目以降の値入力 */
        if (100 < figure[i][2])
        {
            printf("Input error\n");
            i--;
            continue;
        }
        if (figure[i][2] == 0)
        {
            break;
        } /* 2.1. もし0が入力されたら終了 */
        figure[i][0] = 0;
        point = figure[0][0];
        pre = 0; /* 2.2. 次のループ用の前準備 */
        while (1)
        { /* 新しいデータをチェインのどこに入れるか探す */
            /* 2.3. チェインの間の入れるべき位置を探す */
            if (figure[point][2] < figure[i][2])
            {
                pre = point;
                point = figure[point][0];
            }
            else
            {
                figure[pre][0] = i;
                figure[i][0] = point;
                break;
            }
            if (figure[point_][2] > figure[i][2])
            {
                pre_ = point_;
                point_ = figure[point_][0];
            }
            else
            {
                figure[pre_][0] = i;
                figure[i][0] = point_;
                break;
            }
            /* 2.4. 最後まで探し終わったので最後尾に */
            if (point == 0)
            {
                figure[pre][0] = i;
                figure[pre_][0] = i;
                break;
            }
        }
    }
    /* 3. pointが0になるまでfigure[point][1]の値を出力 */
    point = figure[0][0];
    point_ = figure[0][0];

    printf("==========================\n");
    while (point != 0)
    {
        printf("figure[%2d][1]=%d\n", point, figure[point][2]);
        point = figure[point][0];
    }
    printf("==========================\n");
    while (point_ != 0)
    {
        printf("figure[%2d][1]=%d\n", point_, figure[point_][2]);
        point_ = figure[point_][0];
    }
}