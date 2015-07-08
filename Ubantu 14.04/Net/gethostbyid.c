#include <arpa/inet.h>
#include <stdio.h>
#include </usr/include/x86_64-linux-gnu/sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
	struct in_addr my_addr;
	struct hostent *myhost;
//addr -> net
	inet_aton("192.168.0.1",&my_addr);
//show net 
	printf("aton:%d\n",my_addr.s_addr);
//show addr
	printf("addr is :%s\n",inet_ntoa(my_addr));
	
//get host by name 
	myhost = gethostbyname("www.baidu.com");
	my_addr.s_addr = (uint32_t)(myhost->h_addr);
	printf("baidu's addr is :%s\n",inet_ntoa(my_addr));

	
	return 0;
}
