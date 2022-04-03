#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int testArray[] = {4, 3, 1};
    int length = sizeof(testArray) / sizeof(testArray[0]);

    // Loop through the array
    for (int i = 0; i < length; i++)
    {
        // initialize a minimum value that is equal to the 1st element in the array - we contend that this is the minimum value at the start of the loop
        int min_index = i;
        // 2nd Loop through all elements after the currently-checked element(index i)
        for (int j = i + 1; j < length; j++)
        {
            // Check if any elements are less than i
            if (testArray[j] < testArray[i])
            {
                // grab a reference to the new minimum value, which is J
                min_index = j;
            }
        }

        if (min_index != i)
        {
            int temp = testArray[i];
            testArray[i] = testArray[min_index];
            testArray[min_index] = temp;
        }
    }

    for (int x = 0; x < length; x++)
    {
        printf("%i ", testArray[x]);
    }

    return 0;
}