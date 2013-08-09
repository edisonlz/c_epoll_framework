#include "process.h"


int shart_child(int i){

    pid_t pid;
    if( (pid = fork()) < 0 ){
         perror("fork err");
         return 0;
    }else if (pid == 0){
        //in child


        printf("child pid %d %d c:%d\n", pid,i,getpid());
        return i;
    }else{
        //in parent

        printf("parent fork child pid %d %d c:%d\n", pid,i,getpid());
        return 0;
    }

}

void fork_processes(int number){
    int child_id;
    for(int i=1;i<=number;i++) {
          child_id = shart_child(i);
          if(child_id != 0){
              return;
          }
    }


    printf("parent wait c:%d\n",getpid());
    //in parent
    int status;
    pid_t  ex_pid = wait(&status);
    
    printf("exit pid:%d status:%d\n", ex_pid, status);

    exit(EXIT_FAILURE);
}

