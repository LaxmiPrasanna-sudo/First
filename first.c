#include <stdio.h>
#include <string.h>
#include <ctype.h>

char grammar[6][10] = {
    "E+T",
    "T",
    "T*F",
    "F",
    "(E)",
    "id"
};

char productions[6] = {'E', 'E', 'T', 'T', 'F', 'F'};

int firstE[10], firstT[10], firstF[10];
int eCount = 0, tCount = 0, fCount = 0;

void addUnique(int arr[], int *count, int value)
{
    int i;

    for (i = 0; i < *count; i++)
    {
        if (arr[i] == value)
            return;
    }

    arr[(*count)++] = value;
}

int main()
{
    /*
        Grammar:
        E -> E+T
        E -> T
        T -> T*F
        T -> F
        F -> (E)
        F -> id
    */

    /* FIRST(F) */
    addUnique(firstF, &fCount, '(');
    addUnique(firstF, &fCount, 'i');   // represents id

    /* FIRST(T) = FIRST(F) */
    addUnique(firstT, &tCount, '(');
    addUnique(firstT, &tCount, 'i');   // represents id

    /* FIRST(E) = FIRST(T) */
    addUnique(firstE, &eCount, '(');
    addUnique(firstE, &eCount, 'i');   // represents id

    printf("Grammar:\n");
    printf("E -> E+T\n");
    printf("E -> T\n");
    printf("T -> T*F\n");
    printf("T -> F\n");
    printf("F -> (E)\n");
    printf("F -> id\n\n");

    printf("FIRST(E) = { ");

    int i;
    for (i = 0; i < eCount; i++)
    {
        if (firstE[i] == 'i')
            printf("id");
        else
            printf("%c", firstE[i]);

        if (i < eCount - 1)
            printf(", ");
    }

    printf(" }\n");

    printf("FIRST(T) = { ");

    for (i = 0; i < tCount; i++)
    {
        if (firstT[i] == 'i')
            printf("id");
        else
            printf("%c", firstT[i]);

        if (i < tCount - 1)
            printf(", ");
    }

    printf(" }\n");

    printf("FIRST(F) = { ");

    for (i = 0; i < fCount; i++)
    {
        if (firstF[i] == 'i')
            printf("id");
        else
            printf("%c", firstF[i]);

        if (i < fCount - 1)
            printf(", ");
    }

    printf(" }\n");

    return 0;
}
