//Jack Farrell
//Student No: 20352136
//I acknowledge the DCU Academic Integrity Policy 

// The base of this code is credited to Ian g Graham and it was taken from lab04/05 of this module page on loop
// The changes and additions made to the code are all my work

#include "myshell.h"
#include "utility.c"

int main (int argc, char ** argv)
{
    while (!feof(stdin)) // is constantly checking for new commands
    {
        if (argc > 1) // if the shell has been run with a batch file it changes the input from stdin to the file
        {
            batch = 0;
            freopen(argv[1], "r", stdin);
        }
        else // if ran without a batch file it ensures that the batch flag is 1
        {
            batch = 1;
        }

        if(batch == 1) // the batch process will not print the prompt while it is running
        {
            getcwd(CWD, sizeof(CWD)); // gets the current working directory
            strcat(SHELL, CWD);
            strcat(SHELL, argv[0] + 1);
            setenv("PWD", CWD, 1); // updates the PWD environment variable
            setenv("SHELL", SHELL, 1);
            setenv("PARENT", SHELL, 1);
            (strcat(CWD, ">>> "));
            fputs (CWD, stdout); // places the prompt on to the command line
        }

        if (fgets (buf, MAX_BUFFER, stdin )) // get command line from input
        {
            arg = args; // tokenize the input into args array
            *arg++ = strtok(buf,SEPARATORS); // tokenise input
            while ((*arg++ = strtok(NULL,SEPARATORS)));

            if (args[0]) // checks to see if a command has been inputted
            {
                if (strcmp(args[0],"quit") == 0) // checks if it is the quit command
                {
                    exit(0);
                }

                if (strcmp(args[0],"cd") == 0) // "change directory" command
                {
                    fcd(args, CWD);
                    continue;
                }

                int j = 0;
                while(args[j] != NULL) // this process checks to see if the command has been requested to run in the background
                {
                    if (!strcmp(args[j], "&"))
                    {
                        back = 1; // if the command contains an & then the flag for background processesing is changed
                    }
                    j++;
                }
                switch(pid = fork())
                {
                    case -1: // checks to see if an error occured while forking
                        printf("Switch error");
                        break;
                    case 0: ;

                        int check = myIO(args); // goes to the utility.c file to check for input output indicators ("<", ">", ">>")
                        if(check == 0) // if the function ran succesfully it then goes to the mycommands function
                        {
                            mycommands(args, CWD);
                            continue;
                        }
                        else // if the function returns incorectly then an error message is displayed
                        {
                            printf("error in myIO, 0 not returned");
                        }
                        break;
                    default:
                        if(back == 1)
                        {
                            waitpid(pid, &status, WNOHANG); // waitpid command that doesent wait for the cild to finish as it is running in the background
                            sleep(1);
                            back = 0;
                            continue;
                        }
                        else if (back == 0) // this is for functions that are run in the foreground
                        {
                            waitpid(pid, &status, WUNTRACED);                        
                        }

                }
            }
        }
    }
    return 0;
}

void mycommands(char **args, char *CWD) // this function looks at the first argument and determines which command should run
{
    if (!strcmp(args[0],"clr")) // "clear" command
    { 
        fclear();
    }

    if (!strcmp(args[0],"environ")) // "environ" command
    {
        fenviron(environ);
    }

    if (!strcmp(args[0],"dir")) // "dir" command
    {
        fdir(args);
    }

    if(!strcmp(args[0],"pause")) // "clear" command
    {
        fpause(CWD);
    }

    if (!strcmp(args[0],"echo")) // "echo" command
    {
        fecho(args);
    }

    if (!strcmp(args[0],"help")) // "help" command
    {
        fhelp();
    }
    else
    {
        fexternal(args); // external commands
        exit(0);
    }
}

void fclear()
{
    execlp("clear", "clear",NULL);
}

void fenviron(char **environ)
{
    execlp("env", "env", NULL);
}

void fdir(char **args)
{
    char thing[] = "ls"; // these are the base case if no argument has been inputted it will run the "ls -al" command
    char other[] = "-al";
    execlp(thing, thing, other, args[1], NULL);
}

void fcd(char **args, char *CWD)
{
    if(args[1])
    {
        chdir(args[1]); // if an argument has been inputted it will change the directory to that argument if it exists
    }
    else
    {
        printf("%s\n",CWD); // if no argument has been inputted after cd then it will print the current working directory
    }
}

void fpause(char *CWD)
{
    char c;
    printf("Programme paused, Press enter to continue");
    while((c = getchar()) != '\n') // waits for enter to be pressed as that will make the while loop fail
    {
        sleep(1);
    }
}

void fecho(char **args)
{
    int i = 1;
    char string[1024] = "";
    while(args[i] != NULL)
    {
        if (strcmp(args[i], ">") == 0 || strcmp(args[i], ">>") == 0 || strcmp(args[i], "<") == 0) // if the command comes across an IO redirection symbol it wont print that symbol or anything after it
        {
            break;
        }
        else
        {
            strcat(string, args[i]); // gets the blank string and adds the word to it
            strcat(string, " "); // adds a space to the end for the next word
            i++;
        }
    }
    execlp("echo", "echo", string, NULL); // echos the string
}

void fhelp()
{
    execlp("more", "more", "-p -d","../manual/readme.md", NULL); // opens up the readme file with the more command
}

void fexternal(char **args)
{
    execvp(args[0], args);
}