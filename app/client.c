/*
 * 建立TCP 客户端
 * 并向服务器发送数据库
 * BY zhang90
 * 2011-8-4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_PORT 8888
#define MAXLINE 256
#define error_quit(msg) \
    do { perror(msg); exit(EXIT_FAILURE); }while(0)

int main(int argc, char *argv[])
{
    int socketfd;
    struct sockaddr_in myaddr, serveraddr;
    char sendtext[MAXLINE];

    if (argc != 2)
    {
        printf("please input: ./client <IPaddress>\n");
        exit(EXIT_FAILURE);
    }

    /*  创建套接字 */
    if((socketfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        error_quit("socket");

    bzero(&myaddr, sizeof(struct sockaddr_in));
    serveraddr.sin_family       = PF_INET;
    serveraddr.sin_addr.s_addr  = inet_addr(argv[1]);
    serveraddr.sin_port         = htons(SERV_PORT);

    if(connect(socketfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        error_quit("connect");

    memset(sendtext, 0, sizeof(sendtext));
    while(fgets(sendtext, MAXLINE, stdin) != NULL)
    {
        if (write(socketfd, sendtext, MAXLINE) == -1)
            error_quit("write");

        if(strncmp(sendtext, "end", 3) == 0)
            break;
        memset(sendtext, 0, sizeof(sendtext));
    }

    return 0;

}


