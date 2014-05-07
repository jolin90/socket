#define pr_fmt(fmt) "arp.c %s: " fmt "\n", __func__

#include "jolin.h"
#include "arp.h"

#include <netinet/in.h>
#include <arpa/inet.h>

extern char *mac_address_tostring(const char *mac, size_t maclen, const char * buff);

void show_arp_header(struct arp_header *hdr, int simple)
{
	char buff[20];
	memset(buff, 0, sizeof(buff));

	pr_green_info("ARP Header:");

	if (simple == 0)
	{
		pr_std_info("hardware_type = %d", ntohs(hdr->hardware_type));
		pr_std_info("protocol_type = %d", ntohs(hdr->protocol_type));
		pr_std_info("hardware_addrlen = %d", hdr->hardware_addrlen);
		pr_std_info("protocol_addrlen = %d", hdr->protocol_addrlen);
		pr_std_info("op_code = %d", ntohs(hdr->op_code));
	}

	pr_std_info("src_mac = %s", mac_address_tostring((char *)hdr->src_mac, sizeof(hdr->src_mac), buff));
	pr_std_info("src_ip = %s", inet_ntoa(*(struct in_addr *)&hdr->src_ip));
	pr_std_info("dest_mac = %s", mac_address_tostring((char *)hdr->dest_mac, sizeof(hdr->dest_mac), buff));
	pr_std_info("dest_ip = %s", inet_ntoa(*(struct in_addr *)&hdr->dest_ip));
}

