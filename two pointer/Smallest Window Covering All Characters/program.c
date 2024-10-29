#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHARS 256

// Function to find the smallest window in 's' that contains all characters of 't'
char *smallestWindow(char *s, char *t)
{
    int lenS = strlen(s);
    int lenT = strlen(t);

    // If 't' is larger than 's', no such window exists
    if (lenS < lenT)
    {
        return "";
    }

    int charCountT[MAX_CHARS] = {0};
    int charCountWindow[MAX_CHARS] = {0};

    // Count frequency of each character in 't'
    for (int i = 0; i < lenT; i++)
    {
        charCountT[t[i]]++;
    }

    int start = 0, startIndex = -1, minLength = INT_MAX, count = 0;

    // Traverse string 's' with a sliding window
    for (int end = 0; end < lenS; end++)
    {
        // Add current character to the window
        charCountWindow[s[end]]++;

        // If character matches one in 't' and hasn't exceeded its required frequency
        if (charCountT[s[end]] != 0 && charCountWindow[s[end]] <= charCountT[s[end]])
        {
            count++;
        }

        // If all characters from 't' are found in the current window
        if (count == lenT)
        {

            // Try to shrink the window by moving 'start' to the right
            while (charCountWindow[s[start]] > charCountT[s[start]] || charCountT[s[start]] == 0)
            {
                if (charCountWindow[s[start]] > charCountT[s[start]])
                {
                    charCountWindow[s[start]]--;
                }
                start++;
            }

            // Update the minimum length window if found
            int windowLength = end - start + 1;
            if (windowLength < minLength)
            {
                minLength = windowLength;
                startIndex = start;
            }
        }
    }

    // If no valid window is found, return an empty string
    if (startIndex == -1)
    {
        return "";
    }

    // Return the smallest window substring
    static char result[MAX_CHARS];
    strncpy(result, s + startIndex, minLength);
    result[minLength] = '\0';

    return result;
}

int main()
{
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";

    char *result = smallestWindow(s, t);

    if (strlen(result) != 0)
    {
        printf("Smallest window: %s\n", result);
    }
    else
    {
        printf("No such window exists.\n");
    }

    return 0;
}
