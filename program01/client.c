#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int soc, n;
    soc = socket(PF_INET, SOCK_STREAM, 0);
    char buffer[1024], fname[50];
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6311);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    while (connect(soc, (struct sockaddr *)&addr, sizeof(addr)))
        ;
    printf("Client connected to server\n");
    printf("Enter file name to be read\n");
    scanf("%s", fname);
    send(soc, fname, sizeof(fname), 0);
    printf("Recieved response\n");
    while ((n = recv(soc, buffer, sizeof(buffer), 0)) > 0)
        printf("%s\n", buffer);

    return 0;
}
