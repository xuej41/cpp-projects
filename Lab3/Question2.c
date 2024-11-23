#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){
    FILE *file = fopen(input_filename, "r");
    fscanf(file, "%d\n", nPtr);

    // Step 3: Allocate an array of nPtr number of char pointers under word_list
    char **word_list = (char **)malloc(*nPtr * sizeof(char *));

    // Step 4: Allocate an array of characters for each word and read each line
    for (int i = 0; i < *nPtr; i++)
    {
        char buffer[20];  // Assuming no word exceeds 20 characters

        // Read a line (word) from the file
        if (fgets(buffer, sizeof(buffer), file) == NULL)
        {
            // Free any previously allocated memory before returning
            for (int j = 0; j < i; j++)
            {
                free(word_list[j]);
            }
            free(word_list);
            return NULL;
        }

        // Remove newline character manually if it exists
        int len = 0;
        while (buffer[len] != '\n' && buffer[len] != '\0')
        {
            len++;
        }
        if (buffer[len] == '\n')
        {
            buffer[len] = '\0';
        }

        // Allocate memory for the word
        word_list[i] = (char *)malloc((len + 1) * sizeof(char));
        if (!word_list[i])
        {
            // Free any previously allocated memory before returning
            for (int j = 0; j < i; j++)
            {
                free(word_list[j]);
            }
            free(word_list);
            return NULL;
        }

        // Copy the word from buffer to word_list[i]
        for (int j = 0; j < len; j++)
        {
            word_list[i][j] = buffer[j];
        }
        word_list[i][len] = '\0'; // add null termination to end of string
    }

    // close file and return 2D array
    fclose(file);
    return word_list;
}

void swap(char **str1, char **str2)
{    
	/*this is a helper function that you can implement and use to facilitate your development*/
    
    // Hint: str1 and str2 are not just double pointers - they are single pointers passed-by-reference
    //       Therefore, you should treat *str1 and *str2 as changeable addresses of the start of their
    //       respective strings.

    // Hint 2: Swapping two strings in an array of strings is as easy as swapping the starting addresses
    //         of the two target strings to be swapped.  Review Lecture Contents!

    char *temp = *str1;
    
    // Swap the addresses
    *str1 = *str2;
    *str2 = temp;
}

void delete_wordlist(char **word_list, int size)
{
    /*This is a helper function that you MUST IMPLEMENT and CALL at the end of every test case*/
    /*THINK ABOUT WHY!!!*/

    // implement your table deletion code here //
   
    // Hint: Review how to deallocate 2D array on heap.  word_list is a 2D array of chars on heap.

    // Loop through each string in the array
    for (int i = 0; i < size; i++) {
        // Free each individual string
        free(word_list[i]);
    }
    // Free the array of pointers itself
    free(word_list);
}

void sort_words_Bubble(char **words, int size)
{
	/*write your implementation here*/

    // !!IMPLEMENT SWAP() BEFORE ATTEMPTING THIS FUNCTION!! //

    // By this time you should be able to implement bubble sort with your eyes closed ;)

    // Hint: Use your own my_strcmpOrder to compare the ASCII size of the two strings, and
    //       use the returned result as the sorting reference.  

    // Hint: Use swap() if string swapping is required
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (my_strcmpOrder(words[j], words[j + 1]) == 1)
            {
                // if current > next, swap them
                swap(&words[j], &words[j + 1]);
            }
        }
    }
}

void sort_words_Selection(char **words, int size){

    // This implementation of string-sorting function using Selection Sort contains 2 semantic bugs

    // Fix the code, and document how you've found the bugs using GNU debugger.
    // Take screenshots of the debugger output at the instance where you've determined every bug.

    // You will be tested again at the cross exam.

    // If you forgot how Selection Sort works, review Lab 2 document.

    int i, j;    
    int min, minIndex;
    
    for(i = 0; i < size; i++)
    {
        minIndex = i;

        for(j = i + 1; j < size; j++)
        {
            if(my_strcmpOrder(words[minIndex], words[j]) == 1)
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            swap(&words[i], &words[minIndex]);
        }

    }
    
}

