//Jack Farrell
//Student No: 20352136
//I acknowledge the DCU Academic Integrity Policy 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

extern char **environ;
void fclear();
void fenviron(char **environ);
void fdir(char **args);
void fcd(char **args, char *CWD);
void fpause(char *CWD);
void fecho(char **args);
void fhelp();
void fexternal(char **args);
void mycommands(char **args, char *CWD);
int myIO(char **args);

char CWD[255];
char buf[MAX_BUFFER];
char * args[MAX_ARGS];
char ** arg;
char * prompt = CWD;
int status;
int pid;
int batch;
int back = 0;
char SHELL[1024];