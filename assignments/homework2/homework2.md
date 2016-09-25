# Homework 2
Due Monday, October 10, 2016, by 23:59 PM KST

The goals of this homework are to :
- Get some experience with visual studio and C

Before tackling this homework, you should read related class notes.
- [C Demo, Newton's method](slides/ec_siip_04.pdf)

## Taylor series approximation
*link : https://en.wikipedia.org/wiki/Taylor_series*
 1. You should create a new subdirectory *homework2* (of the same private repository you have used for *homework1*). Develop your code for the problems below in this directory and feel free to commit as often as you like, it will help you recover fro blunders.

 Note that to grade this homework, we will try using the functions you write with different input values than the ones used in the examples below, so you might want to test your functions for other reasonable input values.

 1. Recall that computer hardware can only do basic arithmetic, so if you want to evaluate some special function such as square root or a trigonometric function, some algorithm must be implemented by someone to compute an approximation for arbitrary input values. To approximate $\sqrt{y}$, we saw that one approach is to use Newton's method to approximate a zero of the function $x^2 - y = 0$.

 Another approach is to use a Taylor series approximation. Recall that the Taylor series for the exponential function is given by

 $\exp(x) = \sum_{j=0}^\infty \frac{x^j}{j!} = 1 + x + \frac 1 2 x ^2 + \frac 1 6 x^3 + \cdots$

 with the convention that $x^0 = 0!  = 1$.

 Copy *Taylor* visual studio solution folder from the *homework2* directory of class repository to your repository and write a function *double myexp(double x, int n)* in *TaylorMath.c* that returns an approximation to $\exp(x)$ based on the Taylor series of degree *n*. (Note that degree *n* polynomial is obtained by truncating the infinite series after n+1 terms.) Also, write a header file *TaylorMath.h* that has declarations of your function.

 If you have done this properly, you should be able to do, for example
 ```
 ```

 **Hint**: Note that term of degree *j* in the series can be computed from the previous therm by multiplying by *x* and dividing by *j*. if you use this trick you won't need the factorial function. See [Fortran examples: Taylor series](http://faculty.washington.edu/rjl/classes/am583s2014/notes/fortran_taylor.html#fortran-taylor) for an example of this same idea used in a Fortran version.

 1. Add some debugging statements to your function, with an optional argument *debug* with the default value *false*(so the examples above still give the same output) but so that setting *debug=true* causes output similar to below:
 ```
 ```
 1. Create function *double mysin(double x, int n)* in *TaylorMath.c" that approximates the sine function at a point *x* by evaluating the Taylor series approximation of degree *n*. Use the Taylor series expansion about $x_0=0$, also known as the Maclaurin series:
 $\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \cdots$
 Note that the degree 5 and 6 approximations only have three nonzero terms, the degree 7 and 8 approximations have four nonzero terms, etc.

 You should get results like:
 ```
 ```

 Add a debug option as in *myexp*

 **Hint**: You might find it convenient to have a variable *term* that is updated as for the exponential function but then is multiplied by a *s* before adding in to the partial sum, where *s* takes the appropriate value $+1,~-1,$ or 0 depending on *j*

 1. See what happens if you call your function *myexp* and *mysin* with negative values of *n*, of with non-integer real numbers. Add some input-checking to each function so that a non-negative integer value of *n* is required. If an invsalid value is detected, print an error message and return the special value **NAN**. For example
 ```
 ```


## Submission
 - At the end you should have the following files committed to your repository:
  * `/assignments/homework2/Taylor/Taylor.sln`
  * `/assignments/homework2/Taylor/Taylor/Taylor.vcxproj`
  * `/assignments/homework2/Taylor/Taylor/Taylor.vcxproj.filters`
  * `/assignments/homework2/Taylor/Taylor/TaylorMain.c`
  * `/assignments/homework2/Taylor/Taylor/TaylorMath.c`
  * `/assignments/homework2/Taylor/Taylor/TaylorMath.h`

 
 Do not add other files such as `HelloWorld.exe`, which was created when the c code was compiled.

 - Tag the commit number that you want graded. If you submit the wrong thing or make further changes to your work before the due date, you can delete old tag and re-tag to new commit.

