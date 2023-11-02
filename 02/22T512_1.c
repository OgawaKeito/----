#include <stdio.h>

// 製品数
#define N 4
// 制約条件
#define MAX_TIME 37

int main(void)
{
    // フラグ
    int flag[N] = {0, 0, 0, 0};
    // 製品情報
    int data[N][2] =
        {
            {5, 3},
            {17, 12},
            {20, 20},
            {15, 10}
            //{時間,利益}
        };
    // 製品名
    char name[4] = "ABCD";
    // 計算結果
    int sum[2];
    int m_profit = 0;
    int m_flag[4];

    int count = 0;

    while (flag[0] == 0 || flag[1] == 0 || flag[2] == 0 || flag[3] == 0)
    {

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
        // 初期化
        sum[0] = 0;
        sum[1] = 0;
        // 足し合わせ
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (flag[j] == 1)
                {
                    sum[i] += data[j][i];
                }
            }
        }
        // 表示
        if (sum[0] <= MAX_TIME)
        {

            count = 0;
            for (int i = 0; i < N; i++)
            {
                if (flag[i] == 1)
                {
                    count++;
                    printf("%c", name[i]);
                }
            }
            while (count < N)
            {
                count++;
                printf(" ");
            }
            printf(",%3d時間,%3d万円\n", sum[0], sum[1]);
            // 最大利益判定
            if (m_profit < sum[1])
            {
                m_profit = sum[1];
                for (int i = 0; i < N; i++)
                {
                    m_flag[i] = flag[i];
                }
            }
        }
    }

    // 最大利益表示
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        if (m_flag[i] == 1)
            printf("%c", name[i]);
    }
    printf(" 最大利益は%d万円\n", m_profit);
}