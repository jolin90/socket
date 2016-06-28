#include "jolin.h"
#include "ip.h"

char *mac_address_tostring(const char *mac, size_t maclen, const char *buff)
{

	char *p = (char *)buff;
	char *mac_t = (char *)mac;
	char *mac_end = mac_t + maclen - 1;

	for (; mac_t < mac_end; mac_t++) {
		p += sprintf(p, "%02x:", *(u8 *) mac_t);
	}

	p += sprintf(p, "%02x", *(u8 *) mac_t);

	return (char *)buff;
}

void show_eth_header(struct ethhdr *ethhdr)
{
	char buff[20];

	memset(buff, 0, sizeof(buff));

	pr_green_info("Ethhdr Header");
	pr_std_info("dest_mac = %s",
				mac_address_tostring((const char *)ethhdr->h_dest,
									 sizeof(ethhdr->h_dest),
									 (const char *)buff));
	pr_std_info("src_mac = %s",
				mac_address_tostring((const char *)ethhdr->h_source,
									 sizeof(ethhdr->h_source),
									 (const char *)buff));
	pr_std_info("protocol_type = %x", ntohs(ethhdr->h_proto));
	pr_std_info("");
}
