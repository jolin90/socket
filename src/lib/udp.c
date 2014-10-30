#include "jolin.h"
#include "udp.h"

void show_udp_header(struct udp_header *hdr)
{
	pr_green_info("UDP Header:");
	pr_std_info("src_port = %d", ntohs(hdr->src_port));
	pr_std_info("dest_port = %d", ntohs(hdr->dest_port));
	pr_std_info("udp_length = %d", ntohs(hdr->udp_length));
	pr_std_info("udp_checksum = 0x%04x", hdr->udp_checksum);
}

