#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void findAndReplaceInFile()
{
    FILE *ifp, *ofp; //File-type pointer used
    char word[100], ch, read[100], replace[100];
    int word_len, i, p = 0;
 
    ifp = fopen("file_search_input.txt", "r");
    ofp = fopen("file_replace_output.txt", "w+");
    if (ifp == NULL || ofp == NULL) {
        printf("Can't open file.");
        exit(0);
    }
    puts("THE CONTENTS OF THE FILE ARE:\n");
    //Loop to display file contents
     while (1) {
        ch = fgetc(ifp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
 
    puts("\n\nEnter the word to find:");
    fgets(word, 100, stdin);
 
    word[strlen(word) - 1] = word[strlen(word)]; //To remove the newline character from the string
 
    puts("Enter the word to replace it with :");
    fgets(replace, 100, stdin);
 
    replace[strlen(replace) - 1] = replace[strlen(replace)]; //To remove the newline character from the string
 
    fprintf(ofp, "%s - %s\n", word, replace);
    // To compare word with file
    rewind(ifp);
    while (!feof(ifp)) {
 
        fscanf(ifp, "%s", read);
 
        if (strcmp(read, word) == 0) {
            //To delete the word
            strcpy(read, replace);
        }
 
        fprintf(ofp, "%s ", read);
    }
    //// Loop to print the content of the Output file
    rewind(ofp);
    while (1) {
        ch = fgetc(ofp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
 
    fclose(ifp);
    fclose(ofp);
}
 
void main()
{
    findAndReplaceInFile();
}