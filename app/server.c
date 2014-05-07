/*
 * 建立TCP server 并发服务器
 * 接受客户端发来的字符串并打印
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
#include <pthread.h>

#define MAXLINE 256
#define SERV_PORT 8888
#define LISTEN_NUM 10

#define error_quit(msg) \
    do {perror(msg); exit(EXIT_FAILURE);} while(0)

#define error_quit_pthread(msg) \
		do {perror(msg); pthread_exit(NULL);}while(0);

pthread_mutex_t mutex;

void * thread_socket(void *arg)
{
    char  buffer[MAXLINE];
    int   connfd = *(int *)arg;

    free(arg);

    if (pthread_detach(pthread_self()) != 0 )  /* 分离线程 */
        error_quit_pthread("pthread_detach");

    memset(buffer, 0, MAXLINE);
    while(read(connfd, buffer, MAXLINE) > 0)
    {
        pthread_mutex_lock(&mutex);
        printf("recv from clilen: %s \n", buffer);
        pthread_mutex_unlock(&mutex);

        if (strncmp(buffer, "end", 3) == 0)
            break;
        memset(buffer, 0, MAXLINE);
    }

    if(close(connfd) == -1)
        error_quit_pthread("close");	/*这里不能用exit_quit（），会引起进程结束*/

    return  NULL;
}

int main()
{
    int         socketfd, *connfd;
    socklen_t   clilen;
    struct      sockaddr_in myaddr, cliaddr;
    pthread_t   pthread_id;

    if (pthread_mutex_init(&mutex, NULL) < 0)
        error_quit("pthread_mutex_init");

    /*  创建套接字 */
    if((socketfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        error_quit("socket");

    /* 初始化服务器地址信息 */
    bzero(&myaddr, sizeof(struct sockaddr_in));
    myaddr.sin_family       = PF_INET;
    myaddr.sin_addr.s_addr  = htonl(INADDR_ANY);  /* 0.0.0.0 */
    myaddr.sin_port         = htons(SERV_PORT);

    if (bind(socketfd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
        error_quit("bind");

    if (listen(socketfd, LISTEN_NUM) < 0)
        error_quit("listen");

    clilen = 0;
    for(;;)
    {
        connfd  = (int *) malloc(sizeof(int));
        *connfd  = accept(socketfd, (struct sockaddr *)&cliaddr, &clilen);
        if( *connfd == -1 )
        {
            free(connfd);
            error_quit("accept");
        }
        if (pthread_create(&pthread_id, NULL, thread_socket, (void *)connfd) < 0)
            error_quit("pthread");
    }

    close(socketfd);
    return 0;

}

