#include <stdio.h>
#include <windows.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct
{
    Node *main;
    int lp;
} Stack;

void init(Stack *s)
{
    s->main = 0;
    s->lp = 0;
}

int is_full(const Stack *s)
{
    (void)s;
    return 0;
}

int is_empty(const Stack *s) { return s->main == 0; }

int push(Stack *s, char x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = x;
    n->next = s->main;
    s->main = n;
    s->lp++;
    return 1;
}

int pop(Stack *s)
{
    if (is_empty(s))
    {
        printf("Error: Стек пустий!\n");
        return 0;
    }

    Node *t = s->main;
    s->main = t->next;
    free(t);
    s->lp--;
    return 1;
}

int peek(const Stack *s, char *val)
{
    if (is_empty(s))
    {
        return 0;
    }
    *val = s->main->data;
    return 1;
}

int main()
{
    SetConsoleOutputCP(65001);

    Stack stack;

    //char s[]={'(', '(', '(', ')', '(', ')', ')',')','\0'};
    //char s[] = "a*(b-c:((d+e)*(f+g)))-h*(k-l)+m";
    char s[]="a*(b-)c:((d+e)*(f+g)))-h*(k(-l)+m";

    int max = 0, chek = 0;
    // char c;
    init(&stack);

    printf("Рядок для перевірки: ");
    puts(s);
    printf("\n");

    for (int i = 0; s[i] != '\0'; i++)
    {
        // peek(&stack, &c);
        // printf("val: %c\n", c);
        if (s[i] == '(')
        {
            chek = push(&stack, s[i]);
            if (chek == 0)
            {
                printf("Error: Стек переповнено!\n");
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
                printf("Неправильне вкладення!\n");
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