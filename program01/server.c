#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int soc, new_soc, fd, n;
    char buffer[1024], fname[50];
    struct sockaddr_in addr;
    soc = socket(PF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6311);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(soc, (struct sockaddr *)&addr, sizeof(addr));
    printf("Server is online\n");
    listen(soc, 5);
    new_soc = accept(soc, NULL, NULL);
    recv(new_soc, fname, 50, 0);
    printf("Requesting for filename %s\n", fname);
    fd = open(fname, O_RDONLY);
    if (fd < 0)
        printf("File not found\n");
    else
        while ((n = read(fd, buffer, sizeof(buffer))) > 0)
            send(new_soc, buffer, n, 0);
    printf("req sent\n");
    close(fd);
    return 0;
}
