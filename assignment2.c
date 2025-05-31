#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int wordCount = 0;
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    size_t len = strlen(sentence);
    
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    FILE *file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        fprintf(file, "%s\n", token);  
        wordCount++;
        token = strtok(NULL, " ");
    }
    if (ferror(file)) {
        printf("Error writing to file!\n");
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        printf("Error closing file!\n");
        return 1;
    }
    fclose(file); 
    printf("Number of words: %d\n", wordCount);
    return 0;
}
