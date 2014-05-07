#define pr_fmt(fmt) "dhcp.c %s: " fmt "\n", __func__

#include "jolin.h"
#include "jolinwrapper.h"

int main()
{
	struct addrinfo	*ai;
	ai = Host_serv("www.baidu.com", NULL, 0, SOCK_STREAM);
	return 0;
}
