/* include host_serv */

#include "jolin.h"
#include "error.h"
#include "jolinwrapper.h"

char * sock_ntop_host(const struct sockaddr *sa, socklen_t salen)
{
	static char str[128];		/* Unix domain is largest */

	switch (sa->sa_family) {

	case AF_INET: {
			struct sockaddr_in	*sin = (struct sockaddr_in *) sa;

			if (inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL)
				return(NULL);
			return(str);
	}

	default:
		snprintf(str, sizeof(str), "sock_ntop_host: unknown AF_xxx: %d, len %d",
				sa->sa_family, salen);
		return(str);
	}

	return (NULL);
}

char * Sock_ntop_host(const struct sockaddr *sa, socklen_t salen)
{
	char	*ptr;

	if ( (ptr = sock_ntop_host(sa, salen)) == NULL)
		err_sys("sock_ntop_host error");	/* inet_ntop() sets errno */
	return(ptr);
}


struct addrinfo * host_serv(const char *host, const char *serv, int family, int socktype)
{
	int				n;
	struct addrinfo	hints, *res;

	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags = AI_CANONNAME;	/* always return canonical name */
	hints.ai_family = family;		/* AF_UNSPEC, AF_INET, AF_INET6, etc. */
	hints.ai_socktype = socktype;	/* 0, SOCK_STREAM, SOCK_DGRAM, etc. */

	if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
		return(NULL);

	return(res);	/* return pointer to first on linked list */
}

struct addrinfo * Host_serv(const char *host, const char *serv, int family, int socktype)
{
	int ret;
	struct addrinfo hints, *res;

	bzero(&hints, sizeof(hints));
	hints.ai_flags = AI_CANONNAME;	/* always return canonical name */
	hints.ai_family = family;
	hints.ai_socktype = socktype;

	if ( (ret = getaddrinfo(host, serv, &hints, &res)) != 0)
		err_quit("host_serv error for %s, %s: %s",
				 (host == NULL) ? "(no hostname)" : host,
				 (serv == NULL) ? "(no service name)" : serv,
				 gai_strerror(ret));
#if 0
	char ipstr[16];
	struct addrinfo *curr;

	for (curr = res; curr != NULL; curr = curr->ai_next) {
		inet_ntop(AF_INET, &(((struct sockaddr_in *)(curr->ai_addr))->sin_addr), ipstr, 16);
		printf("%s\n", ipstr);
	}

	freeaddrinfo(res);
	return NULL;
#else
	return(res);	/* return pointer to first on linked list */
#endif	
}

