#include <stdio.h>
#include <stdlib.h>

void compressFile() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("compressed.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char prev, curr;
    int count = 1;

    prev = fgetc(in);
    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }

    fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);

    printf("✅ File compressed successfully -> compressed.txt\n");
}

void decompressFile() {
    FILE *in = fopen("compressed.txt", "r");
    FILE *out = fopen("decompressed.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    int count;

    while (fscanf(in, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("✅ File decompressed successfully -> decompressed.txt\n");
}

int main() {
    printf("===== CODTECH TASK 4: RLE COMPRESSION =====\n");

    compressFile();
    decompressFile();

    return 0;
}
