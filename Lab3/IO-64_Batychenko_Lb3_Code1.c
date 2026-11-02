#include <stdio.h>
#include <windows.h>

typedef struct
{
    char main[50];
    int lp;
} Stack;

void init(Stack *s) { s->lp = 0; }

int is_full(const Stack *s) { return s->lp == 50; }

int is_empty(const Stack *s) { return s->lp == 0; }

int pop(Stack *s)
{
    if (is_empty(s))
    {
        return 0;
    }
    s->lp--;
    s->main[s->lp] = '\0';
    return 1;
}

int push(Stack *s, char x)
{
    if (is_full(s))
    {
        return 0;
    }
    s->main[s->lp] = x;
    s->lp++;
    s->main[s->lp] = '\0';
    return 1;
}

int peek(const Stack *s, char *x)
{
    if (is_empty(s))
    {
        return 0;
    }
    *x = s->main[s->lp - 1];
    return 1;
}

int main()
{
    SetConsoleOutputCP(65001);

    Stack stack;

    //char s[]={'(', '(', '(', ')', '(', ')', ')',')','\0'};
    char s[] = "a*(b-c:((d+e)*(f+g)))-h*(k-l)+m";

    int max = 0, chek = 0;

    init(&stack);

    printf("Рядок для перевірки: ");
    puts(s);
    printf("\n");

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            chek = push(&stack, s[i]);
            if (chek == 0)
            {
                printf("Error: Стек переповнено!\n");
                init(&stack);
                return 0;
            }
            if (stack.lp > max)
            {
                max = stack.lp;
            }
        }
        else if (s[i] == ')')
        {
            chek = pop(&stack);
            if (chek == 0)
            {
                printf("Error: Неправильне вкладення!\n");
                init(&stack);
                return 0;
            }
        }
    }

    if (stack.lp == 0)
    {
        printf("Дужки вкладені правильно!");
        printf("\nМаксимальна глибина вкладення: %i\n", max);
    }
    else
    {
        printf("Дужки вкладені НЕ правильно!");
    }
    return 0;
}