#include <stdio.h>
#include <math.h>

int sender(int b[10], int k)
{
    int checksum, sum = 0, i;
    printf("\n****SENDER****\n");

    for (i = 0; i < k; i++)
        sum += b[i];
    printf("SUM IS: %d\n", sum);

    checksum = ~sum;
    printf("SENDER's CHECKSUM IS:%d", checksum);
    return checksum;
}

int receiver(int c[10], int k, int scheck)
{
    int checksum, sum = 0, i;
    printf("\n\n****RECEIVER****\n");
    for (i = 0; i < k; i++)
        sum += c[i];
    printf(" RECEIVER SUM IS : %d", sum);
    sum = sum + scheck;
    checksum = ~sum;
    printf("\nRECEIVER's CHECKSUM IS:%d", checksum);
    return checksum;
}
void main()
{
    int a[10], i, n, scheck, rcheck;
    printf("\nENTER SIZE OF THE STRING:");
    scanf("%d", &n);
    printf("\nENTER THE ELEMENTS OF THE ARRAY:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scheck = sender(a, n);
    rcheck = receiver(a, n, scheck);
    if (rcheck == 0)
        printf("\n\nNO ERROR IN TRANSMISSION\n\n");
    else
        printf("\n\nERROR DETECTED\n\n");
}
