#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNTERFILE "counter.bin"
#define MAX_LOTTONUM 7
#define MAX_LOTTONUMSET 5

void initfile() {
    int writearray[1] = {1};
    FILE *fp = fopen(COUNTERFILE, "r");
    if (fp == NULL) {
        FILE *tmpfp = fopen(COUNTERFILE, "wb");
        fwrite(writearray, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}

int getcounter() {
    int readarray[1];
    FILE *tmpfp = fopen(COUNTERFILE, "rb");
    fread(readarray, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return readarray[0];
}

void setcounter(int counter) {
    int writearray[1];
    writearray[0] = counter;
    FILE *tmpfp = fopen(COUNTERFILE, "wb");
    fwrite(writearray, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}

int numinnumset(int num, int *numset, int len) {
    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (num == numset[i]) {
            ret = 1;
            break;
        }
    }
    return ret;
}

void sortinglottorow(int *numset, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (numset[j] > numset[j + 1]) {
                int temp = numset[j];
                numset[j] = numset[j + 1];
                numset[j + 1] = temp;
            }
        }
    }
}

void printlottorow(FILE *tmpfp, int n) {
    int numset[MAX_LOTTONUM];
    int i = 0;
    while (i < MAX_LOTTONUM - 1) {
        int num = (rand() % 69) + 1;
        if (numinnumset(num, numset, i)) {
            continue;
        }
        numset[i] = num;
        i++;
    }
    // 特別號
    int special;
    while (1) {
        int num = (rand() % 10) + 1;
        if (!numinnumset(num, numset, MAX_LOTTONUM - 1)) {
            special = num;
            break;
        }
    }
    numset[MAX_LOTTONUM - 1] = special;
    sortinglottorow(numset, MAX_LOTTONUM - 1);
    fprintf(tmpfp, " [%02d] : ", n);
    for (int i = 0; i < MAX_LOTTONUM - 1; i++) {
        fprintf(tmpfp, "%02d ", numset[i]);
    }
    fprintf(tmpfp, " | %02d\n", numset[MAX_LOTTONUM - 1]);
}

void printlottofile(int numset, int counter, char *lottofile) {
    time_t curtime;
    time(&curtime);
    srand(time(0));
    FILE *tmpfp = fopen(lottofile, "w");
    fprintf(tmpfp, "========= lotto649 =========\n");
    fprintf(tmpfp, "======= No.%05d ========\n", counter);
    fprintf(tmpfp, "= %24s", ctime(&curtime));
    for (int i = 0; i < MAX_LOTTONUMSET; i++) {
        if (i < numset) {
            printlottorow(tmpfp, i + 1);
        } else {
            fprintf(tmpfp, " [%02d] : -- -- -- -- -- -- | --\n", i + 1);
        }
    }
    fprintf(tmpfp, "========= csieCGU =========\n");
    fclose(tmpfp);
}

int main() {
    int counter;
    initfile();
    counter = getcounter();
    printf("counter = %d\n", counter);
    char lottofile[32];
    snprintf(lottofile, 32, "lotto%05d.txt", counter);
    int numset;
    printf("請輸入要產生的彩券組數（最多 %d 組）：", MAX_LOTTONUMSET);
    scanf("%d", &numset);
    printlottofile(numset, counter, lottofile);
    setcounter(counter + 1);
    return 0;
}
