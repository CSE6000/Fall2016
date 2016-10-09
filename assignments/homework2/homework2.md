# Homework 2
Due Wednesday, October 12, 2016, by 23:59 PM KST

The goals of this homework are to :
- Get some experience with visual studio and C

Before tackling this homework, you should read related class notes and sample codes.
- [C Demo, Newton's method](slides/ec_siip_04.pdf)
- [mysqrt](https://github.com/CSE6000/Fall2016/tree/master/codes/mysqrt)

**NOTE** Use [Chrome extension : GitHub with MathJax](https://chrome.google.com/webstore/detail/github-with-mathjax/ioemnmodlmafdkllaclgeombjnmnbima) for LaTeX equations in [GitHub markdown](https://guides.github.com/features/mastering-markdown/).
## 2-1 ```.gitignore```
 Add ```.gitignore``` file to root directory of your git repository.
 1. Clone [GitHub’s collection of .gitignore file templates](https://github.com/github/gitignore)
 ```
 $ git clone https://github.com/github/gitignore
 ```

 1. Change directory to gitignore and checkout ```b87e474``` commit
 ```
 $ cd gitignore
 $ git checkout b87e474
 ```

 1. Copy ```VisualStudio.gitignore``` to your repository with name ```.gitignore```
 ```
 $ cp VisualStudio.gitignore {YOUR_REPO}/.gitignore
 ```

 1. Add and commit to your git repository
 ```
 $ git add .gitignore
 $ git commit -m "Added .gitignore"
 ```

 **NOTE** Make sure your ```.gitignore``` file same as [b87e474](https://github.com/github/gitignore/blob/master/VisualStudio.gitignore)

## 2-2 Taylor series approximation
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
 x = 1.000000, iter =  0,    1.000000000000000
 x = 1.000000, iter =  1,    2.000000000000000
 x = 1.000000, iter =  2,    2.500000000000000
 x = 1.000000, iter = 20,    2.718281828459046
 ```

 **Hint**: Note that term of degree *j* in the series can be computed from the previous therm by multiplying by *x* and dividing by *j*. if you use this trick you won't need the factorial function. See [Fortran examples: Taylor series](http://faculty.washington.edu/rjl/classes/am583s2014/notes/fortran_taylor.html#fortran-taylor) for an example of this same idea used in a Fortran version.

 1. Create function *double mysin(double x, int n)* in *TaylorMath.c" that approximates the sine function at a point *x* by evaluating the Taylor series approximation of degree *n*. Use the Taylor series expansion about $x_0=0$, also known as the Maclaurin series:

 $\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \cdots$

 Note that the Taylor degree 5 and 6 approximations only have three nonzero terms, the degree 7 and 8 approximations have four nonzero terms, etc.

 You should get results like:
 ```
 x = 1.570796, iter =  2,    1.570796326794897
 x = 1.570796, iter =  3,    0.924832229288650
 x = 1.570796, iter =  4,    0.924832229288650
 x = 1.570796, iter =  5,    1.004524855534817
 ```

 1. See what happens if you call your function *myexp* and *mysin* with negative values of *n* (less than 0). Add some input-checking to each function so that a non-negative integer value of *n* is required. If an invalid value is detected, print an error message and return the special value **NAN**. For example

 code snippet
 ```c
 x = 1.0; iter = -5;
 printf("x = %f, iter = %2d, %f\n", x, iter, myexp(x, iter));
 ```

 output
 ```
 Invalid input. iteration must be non-negative integer
 x = 1.000000, iter = -5, -nan(ind)
 ```

 1. Run and make two result files by uncomment of `printf()` lines of given `TaylorMain.c`.
 ```
 $ $(BUILD_PATH)./Taylor.exe > output1.txt
 $ $(BUILD_PATH)./Taylor.exe output > output2.txt
 ```
 1. Copy `output1.txt` and `output2.txt` to your homework2 directory and `git add` and `git commit`.

## 2-3 Submission
 - At the end you should have the following files committed to your repository:
  * `/assignments/homework2/Taylor/Taylor.sln`
  * `/assignments/homework2/Taylor/Taylor/.vcxproj`
  * `/assignments/homework2/Taylor/Taylor/Taylor.vcxproj.filters`
  * `/assignments/homework2/Taylor/Taylor/TaylorMain.c`
  * `/assignments/homework2/Taylor/Taylor/TaylorMath.c`
  * `/assignments/homework2/Taylor/Taylor/TaylorMath.h`
  * `/assignments/homework2/output1.txt`
  * `/assignments/homework2/output2.txt`

 Do not add other files such as `Taylor.exe`, which was created when the c code was compiled.

 **NOTE** You should follow the file path listed above.

## 2-4 Tag your homework
 - Tag the commit as 'homework2' that you want graded. If you submit the wrong thing or make further changes to your work before the due date, you can delete old tag and re-tag to new commit.

