#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <poll.h>
#include <errno.h>
#include <stdarg.h>
#include <netinet/ip_icmp.h>
#include <signal.h>

struct icmp_proto {
	void	 (*fproc)(char *, ssize_t, struct timeval *);
	void	 (*fsend)(void);
	struct sockaddr  *sasend;	/* sockaddr{} for send, from getaddrinfo */
	struct sockaddr  *sarecv;	/* sockaddr{} for receiving */
	socklen_t	    salen;		/* length of sockaddr{}s */
	int icmpproto;	/* IPPROTO_xxx value for ICMP */

	pid_t pid;
	int sockfd;
};

void icmp_proc_v4(struct icmp_proto *ipr, char *ptr, ssize_t len, struct timeval *tvrecv);
void icmp_send_v4(struct icmp_proto *ipr);


