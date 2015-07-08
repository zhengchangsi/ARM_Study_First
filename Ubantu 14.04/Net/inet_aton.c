#include <arpa/inet.h>
#include <stdio.h>
#include </usr/include/x86_64-linux-gnu/sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	struct in_addr my_addr;
	inet_aton("192.168.0.1",&my_addr);
	printf("aton:%d\n",my_addr.s_addr);

	printf("addr is :%s\n",inet_ntoa(my_addr));
	return 0;
}
