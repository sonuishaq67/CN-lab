#include <stdio.h>
#include <string.h>
#define N strlen(poly)

char input[20], crcs[20], poly[] = "1011";
int ipLength, i, j, k;

void xor () {
    for (k = 1; k < N; k++)
    {
        crcs[k] = (crcs[k] == poly[k]) ? '0' : '1';
    }
}

    void crc()
{
    for (i = 0; i < N; i++)
    {
        crcs[i] = input[i];
    }
    do
    {
        if (crcs[0] == '1')
        {
            xor();
        }
        for (j = 0; j < N - 1; j++)
        {
            crcs[j] = crcs[j + 1];
        }
        crcs[j] = input[i];
        i += 1;
    } while (i < ipLength + N);
}

void main()
{
    printf("Enter the input data: \n");
    scanf("%s", input);
    printf("The polynomial is: %s \n", poly);
    ipLength = strlen(input);
    for (i = ipLength; i < ipLength + N - 1; i++)
    {
        input[i] = '0';
    }
    printf("Padded input is : %s \n", input);

    crc();
    printf("CRC is : %s \n", crcs);
    for (i = ipLength; i < ipLength + N - 1; i++)
    {
        input[i] = crcs[i - ipLength];
    }
    printf("Output message(0 errors) shall  be : %s \n", input);
    printf("Do you want to send a erroneous message? 1 if yes \n");
    scanf("%d", &i);
    if (i == 1)
    {
        printf("Enter message with same length as the output message\n");
        scanf("%s", input);
    }
    crc();
    i = 0;
    while ((i < N - 1) && crcs[i] != '1')
    {
        i += 1;
    }
    if (i < N - 1)
    {
        printf("You my friend have sent a wrong message\n");
    }
    else
    {
        printf("No errors, LESGO \n");
    }
}
