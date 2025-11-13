#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int nums[3];  // 使用者輸入的3個號碼
    printf("請輸入中獎號碼三個:");
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    printf("輸入中獎號碼為: %02d %02d %02d\n", nums[0], nums[1], nums[2]);

    FILE *fp = fopen("lotto.txt", "r");
    if (!fp) {
        printf("開啟 lotto.txt 失敗\n");
        return 1;
    }
    char line[128];
    int found = 0;
    while (fgets(line, sizeof(line), fp)) {
        int group[7];
        // 比對是否為號碼組行（例如 "[1]:"）
        if (line[0] == '[') {
            sscanf(line, "[%*d]: %d %d %d %d %d %d %d",
                   &group[0], &group[1], &group[2], &group[3], &group[4], &group[5], &group[6]);
            int match = 0;
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 3; ++j)
                    if (group[i] == nums[j]) match++;
            }
            if (match == 3) {  // 三碼全中
                printf("以下為中獎彩卷:\n%s", line);
                found = 1;
            }
        }
    }
    if (!found) printf("未中獎\n");
    fclose(fp);
    return 0;
}
