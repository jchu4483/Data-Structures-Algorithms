#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int testArray[] = {4, 3, 1, 2, 2, 5, 9, -215};
    int length = sizeof(testArray) / sizeof(testArray[0]);

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (testArray[i] > testArray[j])
            {
                int temp = testArray[i];
                testArray[i] = testArray[j];
                testArray[j] = temp;
            }
        }
    }

    for (int x = 0; x < length; x++)
    {
        printf("%i ", testArray[x]);
    }
    printf("\n");
    return 0;
}