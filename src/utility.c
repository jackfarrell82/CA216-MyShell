//Jack Farrell
//Student No: 20352136
//I acknowledge the DCU Academic Integrity Policy 

int myIO(char **arg) // this command checks to see if IO redirection is present in the command
{
    int j = 0;
    while(arg[j] != NULL) // goes throught the whole command until it reaches the end, if arg[j] matches the symbol it changes the stdin or stdout to the file after the symbol
    {
        if (strcmp(arg[j], "<") == 0)
        {
            freopen(arg[j+1], "r", stdin);
            arg[j] = NULL;
            j++;
        }
                
        if (strcmp(arg[j], ">") == 0)
        {
            freopen(arg[j+1], "w", stdout);
            arg[j] = NULL;
            j++;
        }

        if (strcmp(arg[j], ">>") == 0)
        {
            freopen(arg[j+1], "a", stdout);
            arg[j] = NULL;
            j++;
        }

        j++;
    }
    return 0; // returns 0 so the system knows no errors occured here
}