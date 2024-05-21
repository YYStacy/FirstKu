#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_characters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    printf("×Ö·ûÊý£º%d\n", count);
}

void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }
    int count = 0;
    char c;
    int in_word = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c) || c == ',') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }
    fclose(file);
    printf("µ¥´ÊÊý£º%d\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s -c|-w <filename>\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "-c") == 0) {
        count_characters(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
        count_words(argv[2]);
    } else {
        printf("Invalid parameter %s. Use -c for character count or -w for word count.\n", argv[1]);
        return 1;
    }
    return 0;
}
