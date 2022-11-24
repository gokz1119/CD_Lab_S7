#include <stdio.h>
char inp[100];
int len = 0;
int curr = 0;
int E();
int Z();
int main()
{
    printf("Enter input:\n");
    scanf("%s", inp);
    while (inp[len] != '\0')
        len++;
    int res = E();
    if (res == 1 && curr == len)
        printf("Input has been accepted.\n");
    else
        printf("Input has been rejected.\n");
}

int E()
{
    int result;
    if (inp[curr] == 'i')
    {
        curr++;
        result = Z();
        if (result == 1)
            return 1;
        else
            return -1;
    }
    return -1;
}

int Z()
{
    int result;
    if (inp[curr] == '+' && inp[curr + 1] == 'i')
    {
        curr += 2;
        result = Z();
        if (result == 1)
            return 1;
    }
    return 1;
}