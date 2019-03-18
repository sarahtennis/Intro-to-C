#include <stdio.h>
#include <string.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    int i;

    for (i = 0; y[i]; i++)
    {
        x[i] = y[i];
    }

    x[i] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    int i;

    for (i = 0; str[i]; i++)
    {
        if (str[i] == c)
        {
            return &str[i];
        }
    }

    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int i;
    int hay_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len > hay_len)
    {
        return NULL;
    }

    for (i = 0; i < (hay_len - needle_len + 1); i++)
    {
        if (haystack[i] == needle[0])
        {
            int k = i;
            k++;

            for (int j = 1; j < needle_len; j++)
            {
                if (haystack[k] != needle[j])
                {
                    break;
                }
                else
                {
                    k++;
                    if (j + 1 == needle_len)
                    {
                        return &haystack[i];
                    }
                }
            }
        }
    }

    return NULL;
}

#ifndef TESTING
int main(void)
{
    // tests string_copy() function
    char toCopy[] = "replace";
    char string[] = "string";
    printf("%s", string);
    printf("\n");
    printf("%s", toCopy);
    printf("\n");
    string_copy(toCopy, string);
    printf("%s", string);
    printf("\n");
    printf("%s", toCopy);
    printf("\n");

    char *hello = "hello";
    char *world = "world";

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    char *str = "LambdaSchool";
    char *found = find_string(str, "School");
    printf("Found string: %s\n", found);

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
