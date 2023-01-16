Project Description:
------------------------------------------------------------------------------------------------------------------------------------------------
In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes

*This is a program in C that simulates a dinner with philosophers using the pthread library. The program takes in command line arguments to set the number of philosophers, the time each philosopher takes to eat and the time each philosopher takes to rest. The program also checks for validity of the arguments, initializes mutexes for the forks, creates threads for each philosopher, and frees allocated memory at the end. The program uses the function ft_isdigit to check if the command line arguments are valid and only contains digits. The program also uses the pthread library for creating and managing threads for each philosopher. The main function validates the arguments and calls the function info_init to initialize variables, mutexes, and threads. The program also has a function init_mutex which is used to initialize the mutexes for the forks and other variables that are used in the program.
 here is a step-by-step explanation of the program's functionality:

1.The program starts by checking the number of command line arguments passed. It should have 5 arguments but 6 is optional. If the number of arguments is not between 5 and 6, the program will print "Invalid arguments" and exit.

2.The program then checks if all the command line arguments are digits using the ft_isdigit function. If any of the arguments contain letters, the program will print "Error found letter in arguments" and exit.

3.The program then checks the limits for each argument using the double_check function. If the argument is invalid, the program will print "Invalid arguments" and exit.

4.The program then calls the info_init function to initialize variables, mutexes, and threads. This function also stocks the arguments passed in the command line.

5.The info_init function calls the init_mutex function to initialize the mutexes for the forks and other variables that are used in the program.

6.The info_init function creates a struct for each philosopher, which will contain information such as the philosopher's ID, the time they take to eat and rest, and a pointer to the mutex for the fork they will be using.

7.The info_init function then creates a thread for each philosopher using the pthread_create function. Each thread will run the function philosopher, which simulates the actions of a philosopher, such as thinking, eating, and sleeping.

8.The main function then waits for all the threads to finish using the pthread_join function.

9.Once all the threads are finished, the main function frees all the memory that was allocated during the program's execution.

10.The program then exits.
