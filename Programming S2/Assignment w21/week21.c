/*gavin skehan
21440824
8/03/22*/

#include <stdio.h> // libary's
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main() {
    FILE* fptr; // file pointer
    fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\irishtimes.txt", "r"); // open file

    if (fptr == NULL) { // if there is no file
        puts("Error Opening File \n Exiting ........");
        return;
    }
    else {
        for (int i = 0; i < 5; i++) {
            fprintf(fptr, "Line %d of text.\n", (i + 1));
        }
    }
    int ch = 0; // variables
    int words = 0;
    int sentences = 0;
    int syllables = 0;
    int i = 0;

    while ((ch = fgetc(fptr)) != EOF) { // while it is not the End of File
        i++;

        // count words
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
            words++;
        }
        // count sentences
        if (ch == '.' || ch == ';' || ch == ':' || ch == '!' || ch == '?') {
            sentences++;
        }
        // count syllables
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            syllables++;

        }

    }
    // flesch index
    float Flesch = (206.835 - 84.6 * (double)syllables / (double)words - 1.015 * (double)words / (double)sentences);
    printf("Number of words: %d\n", words);
    printf("Number of Sentences: %d\n", sentences);
    printf("Number of syllables: %d\n", syllables);
    printf("Number of index: %f\n", Flesch);
    fclose(fptr); // close the file

}