# Homework 1
Due Monday, September 26, 2016, by 16:00 PM KST

The goals of this homework are to :
- Make sure you are familiar with basic shell command and tools.
- Start using git to download course materials,
- Create your own git repository to keep your coursework and post homeworks to be graded
- Make sure you have some necessary software installed.

Before tackling this homework, you should read related class notes.

By doing this homework you create a git repository containing some files that are graded.

## 1-0 Create pull request
*Refer class slide [Git and GitHub demo](slides/ec_siip_03.pdf).*
 1. Fork class repository https://github.com/CSE6000/Fall2016
 1. Edit `/assignments/IntelParallelStudioXESerials.md` and add your name.
  * Check [master file](https://github.com/CSE6000/Fall2016/blob/master/assignments/IntelParallelStudioXESerials.md) and avoid duplication.
  * If there are no empty slot, add a new row and insert new number and your name.
  * *DO NOT CHANGE* other files or other lines that is not related with this homework.
 1. Commit and push to your repository and create pull request.
 1. If your pull request is valid, your commit will be merged.
If you don't get serial with this homework, you can get serial by yourself. Check this [link](https://software.intel.com/en-us/qualify-for-free-software/student)


## 1-1 Check your environments
 1. Make sure you successfully installed "Git for Windows" by pressing windows key and typing "Git Bash".
 1. You can find your git version by typing

 ```
 $ git --version
 ```

 1. Clone the class repository

 ```
 $ mkdir CSE6000
 $ cd CSE6000
 $ git clone https://github.com/CSE6000/Fall2016.git
 ```

 1. Create your own repository with "[Creating assignment link]()"(*WILL BE AVALIABLE SOON*)
 1. Copy homework1 files from class repository to your own repository.
  * `/assignments/homework1/HelloWorld.c`
  * `/assignments/homework1/test.sh`
 1. Use `git add` and `git commit` to add homework1 files and commit.
 1. Modify `test.sh` as instructed in the comments at the top of the file.
 1. Run this bash shell script via:

 ```
 $ bash test.sh
 ```
 This should give output like below:
 ```
 Code run by **INSERT YOUR NAME HERE** 

 which git returns...
 /mingw64/bin/git 

 check whether visual studio installed...
 '/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe' 

 Compiling a C code...
 Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24213.1 for x86
 Copyright (C) Microsoft Corporation.  All rights reserved. 

 HelloWorld.c
 Microsoft (R) Incremental Linker Version 14.00.24213.1
 Copyright (C) Microsoft Corporation.  All rights reserved. 

 /out:HelloWorld.exe
 HelloWorld.obj
 "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/lib/LIBCMT.lib"
 "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/lib/OLDNAMES.lib"
 "C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86/kernel32.lib"
 "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/lib/libvcruntime.lib"
 "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10240.0/ucrt/x86/libucrt.lib"
 "C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86/uuid.lib" 

 Running HelloWorld
 Code run by **INSERT YOUR NAME HERE**
 Hello world!
 ```
 1. Run it again to make result file.

 ```
 $ bash test.sh > testOutput.txt
 ```
 1. Add and commit modified `test.sh` and `testOutput.txt` to your repository.

 **Note** : At the end you should have the following files committed to your repository:
  * `/assignments/homework1/HelloWorld.c`
  * `/assignments/homework1/test.sh`
  * `/assignments/homework1/testOutput.txt`

 Do not add other files such as `HelloWorld.exe`, which was created when the c code was compiled.

 1. Make sure the copies you want graded have been committed, and then push them to GitHub via:

 ```
 $ cd  *YOUR_REPO*/
 $ git push
 ```
 These files should then also be visible from your GitHub webpage, by clicking on the **Code** tab

**Note**: You can commit to your repository and push changes to your GitHub repository as often as you want before the submission, and you are encouraged to get in the habit of committing changes often as you develop code – that’s the whole point of using version control!

