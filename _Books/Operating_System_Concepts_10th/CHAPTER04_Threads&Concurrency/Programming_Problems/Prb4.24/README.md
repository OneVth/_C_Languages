### Programming Problems #4.24
1. An interesting way of  calculating $\pi$ is to use a technique known as Monte Carlo, which involves randomization. This technique works as follows:

![image](https://github.com/user-attachments/assets/0e39b8aa-123e-4ada-8518-be5cdefe4082)

Suppose you have a circle inscribed within a square, as shown in Figure 4.25. (Assume that the radius of this circle is 1.)

- First, generate a series of random points as simple $(x,y)$ coordinates. These points must fall within the Cartesian coordinates that bound the square. Of the total number of random points that are generated, some will occur within the circle.
- Next, estimate $\pi$ by performing the following calculation:

$$
\pi = 4*(\text{number of points in circle)}/\text{total number of points)}
$$

Write a multithreaded version of this algorithm that creates a separate thread to generate a number of random points. 
The thread will count the number of points that occur within the circle and store that result in a global variable. 
When this thread has exited, the parent thread will calculate and output the estimated value of $\pi$. 
It is worth experimenting with the number of random points generated. 
As a general rule, the greater the number of points, the closer the approximation to $\pi$.

In the source-code download for this text, you will find a sample program that provides a technique for generating random numbers, as well as determining if the random $(x,y)$ point occurs within the circle.

Readers interested in the details of the Monte Carlo method for estimating $\pi$ should consult the bibliography at the end of this chapter. 
In Chapter 6, we modify this exercise using relevant material from that chapter.
