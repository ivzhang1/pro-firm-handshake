#include "pipe_networking.h"

static void sighandler(int signo){
  if(signo == SIGINT){
    remove("wkp");
    exit(0);
  }
}

int main() {
  signal(SIGINT,sighandler);

  int to_client;
  int from_client;
	char stuff[BUFFER_SIZE];
	while(1){
		from_client = server_handshake( &to_client );
		while(read(from_client, stuff, sizeof(stuff))){
			printf("SERVER: received message %s", stuff);
			stuff[0] += 1;
			printf("SERVER: Sending message %s", stuff);
			write(to_client, stuff, sizeof(stuff));
		}
	
	}
}
