#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define PortNumber      3000
#define MaxConnects        8
#define BuffSize         10000
#define ConversationLen    3
#define Host            "localhost"

const char* books[] = {"War and Peace",
                       "Pride and Prejudice",
                       "The Sound and the Fury"};

void report(const char* msg, int terminate) {
  perror(msg);
  if (terminate) exit(-1); /* failure */
}

int main() {
  /* fd for the socket */
  int sockfd = socket(AF_INET,      /* versus AF_LOCAL */
                      SOCK_STREAM,  /* reliable, bidirectional */
                      0);           /* system picks protocol (TCP) */
  if (sockfd < 0) report("socket", 1); /* terminate */

  /* get the address of the host */
  struct hostent* hptr = gethostbyname(Host); /* localhost: 127.0.0.1 */
  if (!hptr) report("gethostbyname", 1); /* is hptr NULL? */
  if (hptr->h_addrtype != AF_INET)       /* versus AF_LOCAL */
    report("bad address family", 1);

  /* connect to the server: configure server's address 1st */
  struct sockaddr_in saddr;
  memset(&saddr, 0, sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr =
     ((struct in_addr*) hptr->h_addr_list[0])->s_addr;
  saddr.sin_port = htons(PortNumber); /* port number in big-endian */

  if (connect(sockfd, (struct sockaddr*) &saddr, sizeof(saddr)) < 0)
    report("connect", 1);

  /* Write some stuff and read the echoes. */
  puts("Connect to server, about to write some stuff...");


  const char * httpRequest = "GET / HTTP/1.1\n"
    "Host: localhost:3000/\n"
    "Connection: keep-alive\n"
    "sec-ch-ua: \" Not A;Brand\";v=\"99\", \"Chromium\";v=\"98\", \"Google Chrome\";v=\"98\"\n"
    "sec-ch-ua-mobile: ?0\n"
    "sec-ch-ua-platform: \"macOS\"\n"
    "DNT: 1\n"
    // "Upgrade-Insecure-Requests: 1\n"
    "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36\n"
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\n"
    "Sec-Fetch-Site: none\n"
    "Sec-Fetch-Mode: navigate\n"
    "Sec-Fetch-User: ?1\n"
    "Sec-Fetch-Dest: document\n"
    "Accept-Encoding: gzip, deflate, br\n"
    "Accept-Language: en-US,en;q=0.9,de;q=0.8\n"
    "\n";

  ssize_t result = write(sockfd,httpRequest,strlen(httpRequest));
  char buffer[BuffSize + 1];
  memset(buffer, '\0', sizeof(buffer));
  if (read(sockfd, buffer, sizeof(buffer)) > 0) {
    puts(buffer);
  }
    
  // int i;
  // for (i = 0; i < ConversationLen; i++) {
  //   if (write(sockfd, books[i], strlen(books[i])) > 0) {
  //     /* get confirmation echoed from server and print */
  //     char buffer[BuffSize + 1];
  //     memset(buffer, '\0', sizeof(buffer));
  //     if (read(sockfd, buffer, sizeof(buffer)) > 0)
  //       puts(buffer);
  //   }
  // }
  puts("Client done, about to exit...\n");
  close(sockfd); /* close the connection */
  return 0;
}