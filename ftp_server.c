#include<stdio.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SERV_TCP_PORT 8082
#define MAX 60
int i, j, tem;
char buff[4096], t,ch;
FILE *f1,*ptr;
int main(int afg, char *argv)
{
       int n,sockfd, newsockfd, clength;
       struct sockaddr_in serv_addr,cli_addr;
       char recvline[MAX],t[MAX], str[MAX];
       strcpy(t,"exit");
       sockfd=socket(AF_INET, SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=INADDR_ANY;
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nServer Binded..");
       bind(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr));
       printf("\nServer Listening...");
       listen(sockfd, 5);
       clength=sizeof(cli_addr);
       newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr,&clength);
       close(sockfd);
       read(newsockfd, &str, MAX);
       printf("\nFile Name send from client : %s\n", str);
printf("\nContents of the specified file is transferring..... \n");
       f1=fopen(str, "r");
       while(fgets(buff, 4096, f1)!=NULL)
       {
            write(newsockfd, buff,MAX);
       }
       fclose(f1);
printf("\nFile Transferred\n");

       return 0;
}
