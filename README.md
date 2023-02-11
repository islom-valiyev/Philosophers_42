Project Description:
------------------------------------------------------------------------------------------------------------------------------------------------
Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table.
•There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating,  they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation .

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying




Tutorial Project Description:
------------------------------------------------------------------------------------------------------------------------------------------------
In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes

* This is a program in C that simulates a dinner with philosophers using the pthread library. The program takes in command line arguments to set the number of philosophers, the time each philosopher takes to eat and the time each philosopher takes to rest. The program also checks for validity of the arguments, initializes mutexes for the forks, creates threads for each philosopher, and frees allocated memory at the end. The program uses the function ft_isdigit to check if the command line arguments are valid and only contains digits. The program also uses the pthread library for creating and managing threads for each philosopher. The main function validates the arguments and calls the function info_init to initialize variables, mutexes, and threads. The program also has a function init_mutex which is used to initialize the mutexes for the forks and other variables that are used in the program.
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


I WILL EXPLAIN SOME FUNCTIONS
----------------------------------------------------------------------------------------------------------------

* int check(int ac, char **av): This function is used to check if all the command line arguments are digits. It takes in two arguments, the number of arguments (ac) and the arguments themselves (av). The function uses a nested while loop to iterate through all the characters of all the arguments, and for each character, it checks if it is a digit using the ft_isdigit function. If any of the characters is not a digit, the function returns 0. If all the characters are digits, the function returns 1.

* int ft_isdigit(int num): This function is used by the check function to determine if a character is a digit. It takes in one argument, an integer (num), which represents the ASCII code of a character. If the ASCII code is between '0' and '9', the function returns 1, indicating that the character is a digit. If the ASCII code is not between '0' and '9', the function returns 0, indicating that the character is not a digit.

* void info_init(t_philo *philo, t_info *info, int ac, char **av): This function is used to initialize variables, mutexes, and threads. It takes in four arguments: a struct of type t_philo (philo), a struct of type t_info (info), the number of arguments passed in the command line (ac), and the arguments passed in the command line (av). The function stocks the arguments passed in the command line, initializes the mutexes for the forks and other variables that are used in the program by calling the init_mutex function, creates a struct for each philosopher, which will contain information such as the philosopher's ID, the time they take to eat and rest, and a pointer to the mutex for the fork they will be using. Then the function creates a thread for each philosopher using the pthread_create function. Each thread will run the function philosopher, which simulates the actions of a philosopher, such as thinking, eating, and sleeping.

* void init_mutex(t_info *info): This function is used to initialize the mutexes for the forks and other variables that are used in the program. It takes in one argument, a struct of type t_info (info), which contains information about the simulation such as the number of philosophers and the time each philosopher takes to eat and rest. The function allocates memory for the forks using malloc, initializes the mutexes for each fork using pthread_mutex_init, and initializes the mutex for the write to stdout and the mutex for the global time.

* void *philosopher(void *arg): This function simulates the actions of a philosopher. It takes in one argument, a void pointer (arg), which points to a struct containing information about the philosopher such as their ID, the time they take to eat and rest, and a pointer to the mutex for the fork they will be using. The function simulates the philosopher thinking, eating, and sleeping, and also updates the global time and the philosopher's state.

* int double_check(int ac, char **av): This function is used to check the limits for each argument passed in the command line. It takes in two arguments, the number of arguments passed in the command line (ac) and the arguments themselves (av). The function checks if the arguments passed are withinThe function int double_check(int ac, char **av) is used to check the limits for each argument passed in the command line. It takes in two arguments, the number of arguments passed in the command line (ac) and the arguments themselves (av). The function checks if the arguments passed are within the specified limits. For example, it checks that the first argument, which represents the number of philosophers, is between 1 and 200, the second argument which represents the time each philosopher takes to eat is greater than 0, the third argument which represents the time each philosopher takes to rest is greater than 0, the fourth argument which represents the time to die is greater than 0, and the fifth argument which represents the number of time each philosopher can eat before dying is greater than 0. If any of these conditions are not met, the function returns 0, otherwise it returns 1.

* int double_check(int ac, char **av)
This function checks that the arguments passed to the program are within the expected limits. It checks that the first argument, which represents the number of philosophers, is between 1 and 200, the second argument which represents the time each philosopher takes to eat is greater than 0, the third argument which represents the time each philosopher takes to rest is greater than 0, the fourth argument which represents the time to die is greater than 0, and the fifth argument (if entered) which represents the number of time each philosopher can eat before dying is greater than 0. If any of these conditions are not met, the function returns 0, otherwise it returns 1.

* void philo_pause is not a function that is used in this program, it might be used in another program.
int start is a variable that represents the start time of the simulation, it's used to check the global time of the simulation
void *pthread is a pointer to a pthread, it's used to represent a thread created using the pthread library.

* void *pthread is a pointer to a pthread, it's used to represent a thread created using the pthread library. The pthread library provides a way to create and manage threads in C. The pthread_create function is used to create a new thread and pass it a function to run, along with any arguments that need to be passed to the function. The pthread_join function  is used to wait for a specific thread to finish executing.

* int start is a variable that represents the start time of the simulation, it's used to check the global time of the simulation. It's used to keep track of how much time has passed since the start of the simulation, this is used to check if the philosophers have exceeded the time to die.
int ft_isdigit(int num): This function is used to check if a character is a digit. It takes in one argument, an integer representing the ASCII code of a character, and returns 1 if the character is a digit (i.e. its ASCII code is between '0' and '9'), and 0 otherwise.

* int ft_atoi(char *str): This function converts a string of characters representing a number to an integer. It takes in one argument, a pointer to a character array (string) and returns the integer representation of the string.

* long long get_time(void): This function is used to get the current time in milliseconds. It takes no argument and returns a long long integer representing the current time in milliseconds.

* void philo_pause(t_philo *philo, int time_pause): This function is used to simulate a philosopher's pause. It takes in two arguments, a pointer to a struct of type t_philo (philo), and an integer (time_pause) representing the time the philosopher should pause for. The function sleeps for the specified time and updates the philosopher's state.

* void print(t_philo *philo, int id, char *is_doing): This function is used to print the state of a philosopher. It takes in three arguments, a pointer to a struct of type t_philo (philo), an integer representing the philosopher's ID (id), and a string representing the philosopher's current state (is_doing). The function uses a mutex to ensure that the output to the terminal is not mixed up between different threads.

* void *pthread(void *philo) is a function that serves as the entry point for each philosopher thread that is created.
It takes in one argument, a void pointer (philo), which is casted to a pointer to a struct of type t_philo. This struct contains information about the philosopher such as their ID and the number of times they have eaten.The function starts by creating an infinite loop, in which the philosopher will alternate between thinking, eating, and sleeping.First, it calls the philo_pause function with the time the philosopher should think before trying to eat.Then, it calls the start function, which attempts to take the forks, eat and put down the forks if they are available, otherwise it will wait until they are available.Then it calls the philo_pause function with the time the philosopher should sleep before trying to eat again.It also check if it's time for the philosopher to die using the ft_check_died function, if so it will break the loop, and set the philosopher state as 'DEAD' and update the global variable 'died' as 1.
This function is called by the info_init function, it's used for creating the philosophers threads and run the simulation.

* void put_down_fork(t_philo *philo) is a function that simulates a philosopher putting down their forks after finishing eating.
It takes in one argument, a pointer to a struct of type t_philo (philo), which contains information about the philosopher such as their ID and the number of times they have eaten.
The function starts by setting the status of the philosopher to 'THINKING' and releases the mutexes held by the philosopher on their left and right forks, allowing other philosophers to take the forks.
It also prints a message to the console indicating that the philosopher is done eating and has put down their forks.
This function is called by the done_eat function, it's used for simulating the action of a philosopher putting down their forks after finishing eating.Please let me know if you have any more question or need more clarification on this function.


Unix Threads in C
----------------------------------------------------------------------------------------------------------------

Short introduction to threads (pthreads)
 
* https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
 
What is a mutex in C? (pthread_mutex)
 
*  https://www.youtube.com/watch?v=oq29KUy29iQ&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=4
 
Unix Threads in C

*  https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
