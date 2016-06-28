#include <stdio.h>

#include "jolin.h"
#include "ip.h"

int main(int argc, char *argv[])
{
	int sockfd;
	char buff[4096];
	struct ip_header *ip_header = (void *)buff;;

	sockfd =
		socket(PF_INET, SOCK_RAW, IPPROTO_TCP | IPPROTO_UDP | IPPROTO_ICMP);
	if (sockfd < 0) {
		perror("socket err\n");
		exit(1);
	}

	memset(buff, 0, sizeof(buff));

	while (recv(sockfd, buff, sizeof(buff), 0)) {
		show_ip_header(ip_header, 1);
	}

	perror("before return 0\n");

	return 0;
}
