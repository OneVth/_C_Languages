### Programming Problems #4.28
Modify programming problem Exercise 3.20 from Chapter 3, which asks you to design a pid manager. 
This modification will consist of writing a multithreaded program that tests your solution to Exercise 3.20. 
You will create a number of threads — for example, 100 — and each thread will request a pid, sleep for random period of time, and then release the pid. 
(Sleeping for a random period of time approximates the typical pid usage in which a pid is assigned to a new process, the process executes and then terminates, and the pid is released on the process’s termination.) 
On UNIX and Linux systems, sleeping is accomplished through the $\text{sleep()}$ function, which is passed an integer value representing the number of seconds to sleep. 
This problem will be modified in Chapter 7.
