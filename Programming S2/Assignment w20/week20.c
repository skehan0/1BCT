/*gavin skehan
21440824
01/03/22*/

#include <stdio.h> // libary's
#include <stdlib.h>
#include <string.h>
#include <time.h>

int readWords(char filePath[]); 
void wordGuess();

typedef struct { // structures
    char dictWord[20];
}dictionary;

dictionary word[100000]; // structure with array

void main() {
    char myFilePath[] = "C:\\Users\\skeha\\OneDrive\\Documents\\dictionary.txt"; // properties of file store in array
    int numWords = readWords(myFilePath); 
    printf("Loaded %d suitable words from the dictionary.\n\n", numWords); 
    wordGuess();
}

int readWords(char filePath[]) {
    dictionary newWord;
    FILE* fptr; // file pointer

    char line[200];
    int i = 0;
    char delims[] = "\n";
    
    fopen_s(&fptr, filePath, "r"); // open file in read mode

    if (fptr == NULL) {
        printf("Error opening file, exiting...."); // if file not read
    }
    else {
        while (!feof(fptr) && i < 100000) { // array length 100000
            fgets(line, 200, fptr);

            char* next = NULL; 
            char* first = strtok_s(line, delims, &next); // separates strings

            if (strlen(first) >= 4 && strlen(first) <= 7) { // determine random word length
                strcpy_s(newWord.dictWord, 20, first); // copy a string
                word[i] = newWord;
                i++;
            }
        }
        fclose(fptr); // close file
    }
    return i;
}
void wordGuess() {
    srand(time(NULL)); // random function
    char ranWord[20];
    char guessedLetter;
    char blankStr[20];
    int d = 0;
    int i = 0;

    int ranNumber = rand() % 100000; // random number between 1 and 100000
    strcpy_s(ranWord, 20, word[ranNumber].dictWord); // generate random word

    if (ranWord == NULL) {
        int ranNumber = rand() % 100000; // random number
        strcpy_s(ranWord, 20, word[ranNumber].dictWord);
    }

    for (int i = 0; i < strlen(ranWord); i++) {
        blankStr[i] = '-';
    }
    blankStr[strlen(ranWord)] = '\0'; // start substring

    while (d == 0) {
        printf("Guess %d.\n", i + 1);

        printf("%s", blankStr);

        printf("\nGuess letter > ");
        scanf_s("\n%c", &guessedLetter);

        for (int j = 0; j < strlen(ranWord); j++) {
            if (ranWord[j] == guessedLetter) {
                blankStr[j] = guessedLetter;
            }
        }
        int value = strcmp(ranWord, blankStr);
        if (value == 0) {
            printf("\n");
            printf("It took you %d guesses to find %s!\n\n", i + 1, ranWord); // print guesses
            break; // break program
        }
        i++; // incrememnt
    }
}