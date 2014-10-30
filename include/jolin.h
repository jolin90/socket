#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>
#include <linux/if_packet.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef  pr_fmt
#define pr_fmt(fmt) fmt "\n"
#endif

#define pr_std_info(fmt, args ...) \
		printf(pr_fmt(fmt), ##args)

#define pr_red_info(fmt, args ...) \
		pr_std_info("\033[31m" fmt "\033[0m", ##args);

#define pr_bold_info(fmt, args ...) \
		pr_std_info("\033[1m" fmt "\033[0m", ##args);

#define pr_green_info(fmt, args ...) \
		pr_std_info("\033[32m" fmt "\033[0m", ##args);

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


