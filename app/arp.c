#include "jolin.h"
#include "arp.h"

int main()
{
	int sockfd;

	//sockfd = socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_ARP));
	sockfd = socket(PF_PACKET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("socket err\n");
		exit(1);
	}

	pr_std_info("%d\n", (int)sizeof(struct arp_header));
	return 0;
}
