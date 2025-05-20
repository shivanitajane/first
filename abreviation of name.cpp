##include <stdio.h>
#include <string.h>
#include <ctype.h>

void abbreviate_name(char full_name[]) {
    int length = strlen(full_name);
    int i = 0;
    int j = 0;
    char abbreviated_name[200];
    int space_count = 0;

    // First, we count the number of spaces to find the last name
    for (int k = 0; k < length; k++) {
        if (full_name[k] == ' ') {
            space_count++;
        }
    }

    // Iterate over the full name and abbreviate first and middle names
    while (i < length) {
        // Skip leading spaces
        while (i < length && full_name[i] == ' ') {
            i++;
        }
        
        // If we reached the end, break
        if (i == length) break;

        // If this is not the last name and it's the first or middle name, abbreviate it
        if (space_count > 0) {
            // First letter in uppercase
            abbreviated_name[j++] = toupper(full_name[i]);
            abbreviated_name[j++] = '.'; // Add period after the letter
            while (i < length && full_name[i] != ' ') {
                i++;
            }
            space_count--; // Decrease space_count after handling a name part
        } else {
            // Last name - copy it as is
            while (i < length && full_name[i] != ' ') {
                abbreviated_name[j++] = full_name[i++];
            }
        }
    }

    // Null terminate the resulting string
    abbreviated_name[j] = '\0';

    // Print the abbreviated name
    printf("%s\n", abbreviated_name);
}

int main() {
    char full_name[200];
    
    // Input full name
    printf("Enter full name: ");
    fgets(full_name, sizeof(full_name), stdin);
    
    // Remove newline character if present
    full_name[strcspn(full_name, "\n")] = '\0';
    
    // Call the function to abbreviate the name
    abbreviate_name(full_name);
    
    return 0;
}