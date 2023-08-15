#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<strings.h>
#include<netinet/in.h>
#define MAX 80
#define PORT 8081
#define SA struct sockaddr
void func(int sockfd)
{
        char buff[MAX];
        int n,cl;
        struct sockaddr_in client;
        cl=sizeof(client);
        for(;;)
        {
                bzero(buff,MAX);
                recvfrom(sockfd,buff,sizeof(buff),0,(SA*)&client,&cl);
                printf("\n");
                printf("Message from client : %s Enter message to client : ",buff);
                bzero(buff,MAX);
                n=0;
                while((buff[n++]=getchar())!='\n');
                sendto(sockfd,buff,sizeof(buff),0,(SA*)&client,cl);
                if(strncmp("exit",buff,4)==0)
                {
                        printf("Server Exit...\n");
                        break;
                }
        }
}
int main()
{
        int sockfd;
        struct sockaddr_in servaddr;
        sockfd=socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd==-1)
        {
                printf("Socket creation failed...\n");
                exit(0);
        }
        else
        {
                printf("Socket successfully created...\n");
        }
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(PORT);
        if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
        {
                printf("Socket binding failed...\n");
                exit(0);
        }
        else
        {
                printf("Socket successfully binded...\n");
        }
        func(sockfd);
        close(sockfd);
}
