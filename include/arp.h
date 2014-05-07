#pragma pack(1)

struct arp_header
{
	u16 hardware_type;
	u16 protocol_type;
	u8 hardware_addrlen;
	u8 protocol_addrlen;
	u16 op_code;
	u8 src_mac[6];
	u32 src_ip;
	u8 dest_mac[6];
	u32 dest_ip;
};

#pragma pack()

void show_arp_header(struct arp_header *hdr, int simple);

