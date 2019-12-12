#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define SEG 60 //time limit for the tests
#define DASH "--------------------------"

void child();
void father(char str_pid[]);
void listar_primos();
int primo(int x);
int Fermat(unsigned long long int p);
unsigned long long int modulo(unsigned long long int a, unsigned long long int b, unsigned long long int c);

int main(int argc, char *argv[])
{

    //creates child process
    int pid = fork();

    //converts pid into a string
    char str_pid[20];
    sprintf(str_pid, "%d", pid);

    //problem occoured exiting with -1
    if (pid < 0)
    {
        perror("Error: ");
        exit(-1);
    }

    //it's the child process
    else if (pid == 0)
    {
        child();
    }

    //it's the father process
    else
    {
        father(str_pid);
    }

    perror("Status");
    printf("tchau\n");
    exit(0);
}

/*  This function's purpose is to print into bash and into a file 
 * the defined process's memory and cpu usage.
 *
 * It writes into the string bash_cmd the bash command:
 *  $ ps -e -o pid,rss,pcpu | grep $pid | awk '{ printf "%-10s%-5s\n", $2, $3 }'
 *  
 *  Which shows all the current processes' pids, resident size 
 * memories and their cpu usage, respectively. It then "greps" the 
 * process defined by the variable str_pid, and prints out the last 
 * 2 "ps" outputs: The memory and cpu usage;
 * 
 *  It only writes into a file if there is an argument in argv[2]
 */
void father(char str_pid[])
{
    char bash_cmd[256], aux[20];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int n;

    //ten second loop
    int i;
    for (i = 0; i < SEG; i++)
    {
        sleep(1);
    }

    //writes into the str the command to kill the child process
    strcpy(bash_cmd, "kill ");
    strcat(bash_cmd, str_pid);
    system(bash_cmd);
}

/*
 *  This function is used to force test cpu and ram power.
 *  Uses argv input to define which loop to run.
 */
void child()
{
    unsigned long long int i = 0;
    listar_primos();
}

void listar_primos()
{
    unsigned long long int i = 2;
    for(i = 2;;i++){
        if(i % 2 != 0){
            if(Fermat(i))
                printf("%llu\n", i);
        }
    }
}

int primo(int x)
{
    int i;

    for(i = x - 1; i >= sqrt(x); i--){
        if(x % i == 0){
            return 0;
        }
    }

    return 1;
}

unsigned long long int modulo(unsigned long long int a, unsigned long long int b, unsigned long long int c) {
    //calculate (a^b)%c
    unsigned long long int x = 1;
    unsigned long long int y = a;
    while(b>0) {
        if(b&1) x=(x*y)%c;
        y=(y*y)%c;
        b=b>>1;
    }
    return x%c;
}

int Fermat(unsigned long long int p){
    if(p==1) return 0;
    for(int i=0;i<10;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        unsigned long long int a = rand()%(p-1)+1; 
        if(modulo(a,p-1,p)!=1) return 0; /* p is definitely composite */
    }
    return 1; /* p is probably prime */
}