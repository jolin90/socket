#include "jolin.h"
#include "tcp.h"

void show_tcp_header(struct tcp_header *hdr)
{
	pr_green_info("TCP Header:");
	pr_std_info("src_port = %d", ntohs(hdr->src_port));
	pr_std_info("dest_port = %d", ntohs(hdr->dest_port));
	pr_std_info("sequence = %d", ntohl(hdr->sequence));
	pr_std_info("sck_sequence = %d", ntohl(hdr->sck_sequence));
	pr_std_info("window_size = %d", ntohs(hdr->window_size));
	pr_std_info("reserve = %d", hdr->reserve);
	pr_std_info("TCP_URG = %d", hdr->TCP_URG);
	pr_std_info("TCP_ACK = %d", hdr->TCP_ACK);
	pr_std_info("TCP_PSH = %d", hdr->TCP_PSH);
	pr_std_info("TCP_RST = %d", hdr->TCP_RST);
	pr_std_info("TCP_SYN = %d", hdr->TCP_SYN);
	pr_std_info("TCP_FIN = %d", hdr->TCP_FIN);
	pr_std_info("checksum = 0x%04x", ntohs(hdr->checksum));
	pr_std_info("urgent_pointer = %d", ntohs(hdr->urgent_pointer));
}

