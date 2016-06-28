#include <stdio.h>

#include "jolin.h"
#include "ip.h"
#include "ether.h"
#include "tcp.h"
#include "udp.h"

int main(int argc, char *argv[])
{
	int sockfd;
	char buff[4096];
	struct ethhdr *ethhdr = (void *)buff;;
	struct ip_header *ip_header = (void *)(ethhdr + 1);

	sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (sockfd < 0) {
		perror("socket err\n");
		exit(1);
	}

	memset(buff, 0, sizeof(buff));

	while (recv(sockfd, buff, sizeof(buff), 0)) {
		switch (ntohs(ethhdr->h_proto)) {
		case ETH_P_IP:
			show_eth_header(ethhdr);
			show_ip_header(ip_header, 1);
			break;

		case ETH_P_ARP:
		case ETH_P_RARP:
			show_eth_header(ethhdr);
			printf("\n");
			break;
		default:
			pr_red_info("others");
			break;
		}
	}

	perror("before return 0\n");

	return 0;
}
