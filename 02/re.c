#include <stdio.h>

#define N 4         // 製品数
#define MAX_TIME 37 // 制約条件

void main(void)
{
    int flag[N] = {0, 0, 0, 0};
    char name[N] = "ABCD";
    int data[N][2] =
        {
            {5, 3},
            {17, 12},
            {20, 20},
            {15, 10}
            //{時間,利益}
        };
    int s_time = 0;
    int s_prifit = 0;
    int m_profit = 0;
    int m_flag[N] = {0, 0, 0, 0};

    while (flag[0] != 1 || flag[1] != 1 || flag[2] != 1 || flag[3] != 1)
    {
        // Aの項に足す１
        flag[0]++;
        // 繰り上がり
        for (int i = 1; i < N; i++)
        {
            if (flag[i - 1] > 1)
            {
                flag[i - 1] = 0;
                flag[i]++;
            }
        }
        //
        s_time = 0;
        s_prifit = 0;
        for (int i = 0; i < N; i++)
        {
            if (flag[i] == 1)
            {
                s_time += data[i][0];
                s_prifit += data[i][1];
            }
        }

        if (s_time <= MAX_TIME)
        {
            for (int i = 0; i < N; i++)
            {
                if (flag[i] == 1)
                {
                    printf("%c", name[i]);
                }
            }
            printf(",時間：%2d,利益：%2d\n", s_time, s_prifit);

            if (m_profit < s_prifit)
            {
                m_profit = s_prifit;
                for (int i = 0; i < N; i++)
                {
                    m_flag[i] = flag[i];
                }
            }
        }
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        if (m_flag[i] == 1)
        {
            printf("%c", name[i]);
        }
    }
    printf(",最大利益%d\n", m_profit);

    return;
}