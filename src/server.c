#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#define PortNumber      9875
#define MaxConnects        8
#define BuffSize         256
#define ConversationLen    3
#define Host            "localhost"

void report(const char* msg, int terminate) {
  perror(msg);
  if (terminate) exit(-1); /* failure */
}

int main() {
  int fd = socket(AF_INET,     /* network versus AF_LOCAL */
                  SOCK_STREAM, /* reliable, bidirectional, arbitrary payload size */
                  0);          /* system picks underlying protocol (TCP) */
  if (fd < 0) report("socket", 1); /* terminate */

  /* bind the server's local address in memory */
  struct sockaddr_in saddr;
  memset(&saddr, 0, sizeof(saddr));          /* clear the bytes */
  saddr.sin_family = AF_INET;                /* versus AF_LOCAL */
  saddr.sin_addr.s_addr = htonl(INADDR_ANY); /* host-to-network endian */
  saddr.sin_port = htons(PortNumber);        /* for listening */

  if (bind(fd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0)
    report("bind", 1); /* terminate */

  /* listen to the socket */
  if (listen(fd, MaxConnects) < 0) /* listen for clients, up to MaxConnects */
    report("listen", 1); /* terminate */

  fprintf(stderr, "Listening on port %i for clients...\n", PortNumber);
  FILE *f = fopen("topp-states.png", "r");
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

  char *string = malloc(fsize + 1);
  fread(string, 1, fsize, f);
  fclose(f);

  string[fsize] = 0;
  /* a server traditionally listens indefinitely */
  while (1) {
    struct sockaddr_in caddr; /* client address */
    int len = sizeof(caddr);  /* address length could change */

    int client_fd = accept(fd, (struct sockaddr*) &caddr, &len);  /* accept blocks */
    if (client_fd < 0) {
      report("accept", 0); /* don't terminate, though there's a problem. Wait for next connection.*/
      continue;
    }

    /* read from client */
    int i;
    for (i = 0; i < ConversationLen; i++) {
      char buffer[BuffSize + 1];
      memset(buffer, '\0', sizeof(buffer));
      int count = read(client_fd, buffer, sizeof(buffer));
      if (count > 0) {
        puts(buffer);
        
        char *reply = 
          "HTTP/1.1 200 OK\n"
          "Date: Thu, 19 Feb 2009 12:27:04 GMT\n"
          "Server: Apache/2.2.3\n"
          "Last-Modified: Wed, 18 Jun 2003 16:05:58 GMT\n"
          "ETag: \"56d-9989200-1132c580\"\n"
          "Content-Type: image/png\n"
          "Content-Length: 15\n"
          "Accept-Ranges: bytes\n"
          "Connection: close\n"
          "\n";
        int strlenNeeded = strlen(reply) + strlen(string);
        char * stringSomething = (char *)malloc(sizeof(char) * strlenNeeded);
        strcpy(stringSomething,reply);
        strcat(stringSomething,string);
        
        // char * response = strcat(reply,string);
        printf("BYE WORLD\n");
        // write(client_fd, buffer, sizeof(buffer)); /* echo as confirmation */
        write(client_fd, stringSomething, strlen(stringSomething));
      }
    }
    close(client_fd); /* break connection */
  }  /* while(1) */
  return 0;
}
