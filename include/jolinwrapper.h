void * Calloc(size_t n, size_t size);
void Gettimeofday(struct timeval *tv, void *foo);
struct addrinfo * Host_serv(const char *host, const char *serv, int family, int socktype);
char * Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);

int Socket(int family, int type, int protocol);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags, const struct sockaddr *sa, socklen_t salen);

