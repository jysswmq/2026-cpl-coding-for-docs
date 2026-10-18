#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a, b, c, p;
    a = n / 100;
    b = n % 100 / 10;
    c = n % 100 % 10 / 1;
    p = n % 100;
    if (n == 0)
        printf("zero\n");
    else
    {
        switch (a)
        {
            case 0:break;
            case 1:printf("one hundred"); break;
            case 2:printf("two hundred"); break;
            case 3:printf("three hundred"); break;
            case 4:printf("four hundred"); break;
            case 5:printf("five hundred"); break;
            case 6:printf("six hundred"); break;
            case 7:printf("seven hundred"); break;
            case 8:printf("eight hundred"); break;
            case 9:printf("nine hundred"); break;
        }
        if (p == 0)
            return 0;
        if (p != 0&&a != 0)
            printf(" and ");
        switch (b)
        {
            case 0:case 1:break;
            case 2:printf("twenty"); break;
            case 3:printf("thirty"); break;
            case 4:printf("forty"); break;
            case 5:printf("fifty"); break;
            case 6:printf("sixty"); break;
            case 7:printf("seventy"); break;
            case 8:printf("eighty"); break;
            case 9:printf("ninety"); break;
        }
        if (c == 0 && b>=2)
            return 0;
        else
        {
            if (p > 19||p<11)
            {
                if(p>19)
                    printf("-");
                switch (c)
                {
                case 1:printf("one\n"); break;
                case 2:printf("two\n"); break;
                case 3:printf("three\n"); break;
                case 4:printf("four\n"); break;
                case 5:printf("five\n"); break;
                case 6:printf("six\n"); break;
                case 7:printf("seven\n"); break;
                case 8:printf("eight\n"); break;
                case 9:printf("nine\n"); break;
                }
            }
            if (p >= 11 && p <= 19)
                switch (p)
                {
                case 11:printf("eleven\n"); break;
                case 12:printf("twelve\n"); break;
                case 13:printf("thirteen\n"); break;
                case 14:printf("fourteen\n"); break;
                case 15:printf("fifteen\n"); break;
                case 16:printf("sixteen\n"); break;
                case 17:printf("seventeen\n"); break;
                case 18:printf("eighteen\n"); break;
                case 19:printf("nineteen\n"); break;
                }
             
        }
    }
    return 0;
}