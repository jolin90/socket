#pragma pack(1)

struct mac_header {
	u8 dest_mac[6];
	u8 src_mac[6];
	u16 protocol_type;

	u8 data[0];
};

#pragma pack()

void show_eth_header(struct ethhdr *ethhdr);
