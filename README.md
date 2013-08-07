c_epoll_framework
=================

c epoll framework like tornado tcpserver


Need implement process_request

Example

```
void process_request(int client, int epoll_fd) {

    ssize_t count;
    char buf[4096];

    count = read_all(client, buf);

    #ifdef DEBUG
    printf("read all %s\n",buf);
    #endif

    echo(client, buf);
}


void echo(int client,char *buf){

    char *char_quit = "quit";
    int quit = strncmp(buf, char_quit , 4);

    if(quit == 0){
        buf = "quit!";
    }

    send_all(client , buf);

    /* quit */
    if(quit == 0){
        close(client);
    }

}

```