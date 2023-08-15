#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#define SA struct sockaddr
#define MAX 80
#define PORT 1024
int main()
{
        FILE *f1;
        int sockfd;
        struct sockaddr_in servaddr, cli;
        char buff[MAX],name[20];
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd==-1){
                printf("Socket crreation failed...\n");
        }
        else{
                printf("socket created successfully...\n");
        }
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        servaddr.sin_port=htons(PORT);
        if((connect(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0){
                printf("Connection failed..\n");
        }
        else{
                printf("Connection successful");
        }
        printf("Enter file name : ");
        scanf("%s",name);
        f1=fopen(name,"r");
        while(fgets(buff,4096,f1)!=NULL)
        {
                write(sockfd,buff,sizeof(buff));
        }
        fclose(f1);
        close(sockfd);
}
