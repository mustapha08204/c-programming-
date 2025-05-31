#include <stdio.h>
#include <ctype.h>
int main() {
    char sentence[1000];
    // Get input from user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    // Encrypt each character
    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = sentence[i];
        // Check if character is a letter
        if (isalpha(ch)) {
            if (ch == 'z') {
                sentence[i] = 'a';
            } else if (ch == 'Z') {
                sentence[i] = 'A';
            } else {
                sentence[i] = ch + 1;
            }
        }
        
        else if (isdigit(ch)) {
            if (ch == '9') {
                sentence[i] = '0';
            } else {
                sentence[i] = ch + 1;
            }
        }
        
        else if (ch == ' ') {
            sentence[i] = '_'; 
        }
    }
   
    printf("Encrypted sentence: %s", sentence);
    return 0;
}
