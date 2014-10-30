#pragma pack(1)

struct ip_header
{
	u8 version 				:4;
	u8 header_length 		:4;
	u8 service_type 		:8;
	u16 total_length;
	u16 ident;
	u32 flags 				:3;
	u32 piece_offset 		:13;
	u8 ttl 					:8;
	u8 protocol_type 		:8;
	u16 header_checksum;

	u32 src_ip;
	u32 dest_ip;

	u8 data[0];
};

#pragma pack()

