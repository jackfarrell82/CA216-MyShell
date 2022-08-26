SHELL(1)

NAME
    C Shell Assignment

DESCRIPTION
    The shell is a C based terminal that reads and executes commands entered via the prompt or a file.
    The list of built in commands can be found below. 
    Other commands that are not listed below can also be interpretit by the shell.
    The shell is formatted to be similar in look and function to the terminal found in linux systems.

COMMANDS
    cd  - change the current default directory.
    [options]
        - Takes in the argument after cd to determin what directory to go to.
        - If no argument is given then it prints the PWD.
        - To go to the previous directory use .. [ cd .. ]

    dir  - list the contents of directory.
    [options]
        - dir / dir . returns a list of all files, including hidden files, that are in the directory.
        - Output can be redirected to a file.
    
    environ - list all the environment strings.
    [options]
        - Output can be redirected to a file.

    echo - prints what is placed after it onto stdout.
    [options]
        - Outputs can be redirected to a file.
        - Echo can accept input redirection and print what is in that file

    help - display the user manual.  

    clr - clear the screen.

    pause - pause operation of the shell until 'Enter' is pressed.

    quit - quit the shell.

ENVIRONMENT

    Environment variables are variables that the system uses when executing certain processes. 
    Both environment variable names and their values are character strings. 
    By changing the enviroment variables it changes how the system works and executes certain processes. 
    Some example environment variables are: 
    - USER contains your username.
    - HOME contains the path to your home directory.
    - PATH contains a colon-separated list of directories through which Linux searches for commands you invoke.

I/O REDIRECTION

    I/O redirection stands for input / output redirection. 
    There are three basic streams standard input, standard output and standard error. These are known as stdin,
    stdout and stderr respectivly.
    IO redirection allows us to change where these streams go and as a result change where the inputs and outputs
    come from and go to.
    This allows us to simultaneously send and store data in files that can then be acceses by other people or even
    by other systems using that file as stdin.

    Output Redirection
        There are two types of output redirection "write" (w) and "append" (a)
        these redirect the stdout stream to print to the file.

    Write
        Writing to a file first erases all the contents in that file before writing its output.
        when calling io redirection use ">" to write to the file.
    
    Append
        Appending to a file simply adds on the output to the end of the file.
        when calling io redirection use ">>" to append to the file.

    Input Redirection
        There is only one form of input redirection and it replaces the stdin string to be a file
        when calling io redirection use "<" to read from a file.

BACKGROUND / FOREGROUND EXECUTION

    Foreground execution is the base execution process when a command is called. 
    in order for a process to be executed in the background an ampersand (&) symbol must be added to the end of the prompt.
    This allows other processes to run in the foreground without affecting the background process. 
    Once the background process has completed it will the child that was running the process is terminated. 

REFERENCES

    Mitchell, M., Oldham, J. and Samuel, A., 2001. Advanced linux programming. New Riders Publishing.
    http://metalab.uniten.edu.my/~abdrahim/csnb334(xcvb)/alp.pdf

    Cobbaut, P., 2015. Linux Fundamentals.
    https://lib.hpu.edu.vn/handle/123456789/21418

    Carothers, C.D. and Fujimoto, R.M., 1996. Background execution of time warp programs. ACM SIGSIM Simulation Digest, 26(1), pp.12-19.
    https://dl.acm.org/doi/pdf/10.1145/238793.238802?casa_token=Hs8DTx-NMF8AAAAA:U0eEIRsT6_B7nyIsyvvNIjwHD0m7EI8SoEK4Y5d0kH2IVMl0M3A5YNR4BcwcSiwM-3kv_QiVhO-K

    Bovet, D.P. and Cesati, M., 2005. Understanding the Linux Kernel: from I/O ports to process management. " O'Reilly Media, Inc.".
    https://books.google.ie/books?hl=en&lr=&id=h0lltXyJ8aIC&oi=fnd&pg=PT11&dq=process+linux&ots=gQ3rIV8cJX&sig=grGRIYDUZziyWCE1Byuad1FdmXg&redir_esc=y#v=onepage&q=process%20linux&f=false
    
Jack Farrell
Student No: 20352136
I acknowledge the DCU Academic Integrity Policy 