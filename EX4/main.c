#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";   // 共4格（含'\0'）
    float c[] = {1.1, 1.2, 1.3};
    int ra[3];
    char rb[4];
    float rc[3];

    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(a), 1, fp);   // 一次寫整個 int 陣列
    fwrite(b, sizeof(b), 1, fp);   // 一次寫整個 char 陣列（含'\0'）
    fwrite(c, sizeof(c), 1, fp);   // 一次寫整個 float 陣列

    fseek(fp, 0, SEEK_SET);        // 回到檔案開頭

    fread(ra, sizeof(ra), 1, fp);  // 一次讀整個 int 陣列
    fread(rb, sizeof(rb), 1, fp);  // 一次讀整個 char 陣列
    fread(rc, sizeof(rc), 1, fp);  // 一次讀整個 float 陣列

    for (int i = 0; i < 3; i++)    // 輸出 int
        printf("%d ", ra[i]);
    printf("\n%s\n", rb);          // 輸出 char
    for (int i = 0; i < 3; i++)    // 輸出 float
        printf("%.6f ", rc[i]);
    printf("\n");

    fclose(fp);
    return 0;
}
