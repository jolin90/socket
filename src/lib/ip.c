#include "jolin.h"
#include "ip.h"

const char *ip_protocol_type_tostring(int type)
{
	switch (type)
	{
	case IPPROTO_IP:
		return "IPPROTO_IP";
	case IPPROTO_ICMP:
		return "IPPROTO_ICMP";
	case IPPROTO_IGMP:
		return "IPPROTO_IGMP";
	case IPPROTO_IPIP:
		return "IPPROTO_IPIP";
	case IPPROTO_TCP:
		return "IPPROTO_TCP";
	case IPPROTO_EGP:
		return "IPPROTO_EGP";
	case IPPROTO_PUP:
		return "IPPROTO_PUP";
	case IPPROTO_UDP:
		return "IPPROTO_UDP";
	case IPPROTO_IDP:
		return "IPPROTO_IDP";
	case IPPROTO_RSVP:
		return "IPPROTO_RSVP";
	case IPPROTO_GRE:
		return "IPPROTO_GRE";
	case IPPROTO_IPV6:
		return "IPPROTO_IPV6";
	case IPPROTO_ESP:
		return "IPPROTO_ESP";
	case IPPROTO_AH:
		return "IPPROTO_AH";
	case IPPROTO_COMP:
		return "IPPROTO_COMP";
	case IPPROTO_SCTP:
		return "IPPROTO_SCTP";
	case IPPROTO_RAW:
		return "IPPROTO_RAW";
	case IPPROTO_PIM:
		return "IPPROTO_PIM";
#if 0
	case IPPROTO_DCCP:
		return "IPPROTO_DCCP";
	case IPPROTO_BEETPH:
		return "IPPROTO_BEETPH";
	case IPPROTO_UDPLITE:
		return "IPPROTO_UDPLITE";
#endif
	default:
		return "unknown";
	}
}

void show_ip_header(struct ip_header *hdr, int simple)
{
	pr_green_info("IP Header:");

	if (simple == 0)
	{
		pr_std_info("version = %d", hdr->version);
		pr_std_info("header_length = %d", hdr->header_length);
		pr_std_info("service_type = %d", hdr->service_type);
		pr_std_info("total_length = %d", ntohs(hdr->total_length));
		pr_std_info("flags = %d", hdr->flags);
		pr_std_info("piece_offset = %d", hdr->piece_offset);
		pr_std_info("ttl = %d", hdr->ttl);
		pr_std_info("header_checksum = 0x%04x", ntohs(hdr->header_checksum));
	}

	pr_std_info("protocol type = %s", (char *)ip_protocol_type_tostring(hdr->protocol_type));
	pr_std_info("src ip = %s", inet_ntoa(*(struct in_addr *)&hdr->src_ip));
	pr_std_info("dest ip = %s", inet_ntoa(*(struct in_addr *)&hdr->dest_ip));

}




