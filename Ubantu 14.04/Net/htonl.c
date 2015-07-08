#include <arpa/inet.h>
#include <stdio.h>

int main()
{
	int ipcount = 0x01020304;
	int ipnet = htonl(ipcount);
	printf("ipcount:%d\n",ipcount);
	printf("ipnet:%d\n",ipnet);
	return 0;
}
