#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#define SA struct sockaddr
#define PORT 1024
int main()
{
        int sockfd,num;
        struct sockaddr_in servaddr,cli;
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd==-1){
                printf("Socket creation failed...\n");
        }
        else{
                printf("Socket created successfully...\n");
        }
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        servaddr.sin_port=htons(PORT);
        if((connect(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0){
                printf("connection failed...\n");
        }
        else{
                printf("Connection successful...\n");
        }
        printf("Enter the number : ");
        scanf("%d",&num);
        write(sockfd,&num,sizeof(num));
        close(sockfd);
}
