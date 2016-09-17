
# bash script to check for software
# Insert your name where indicated below.
# Also insert your name where instructed in the file HelloWorld.c.
# Then execute:
#    $ bash test.sh
# When it looks good, redirect output to a file:
#    $ bash test.sh > testOutput.txt

echo
echo Code run by  **INSERT YOUR NAME HERE**

echo
echo which git returns...
which git

echo
echo check whether visual studio installed...
ls "/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe"

echo
echo Compiling a C code...
"/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe" HelloWorld.c -I"/c/Program Files (x86)/Windows Kits/10/Include/10.0.10240.0/ucrt" -I"/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/include" "/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/lib//LIBCMT.lib" "/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/lib/OLDNAMES.lib" "/c/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86/kernel32.lib" "/c/Program Files (x86)/Microsoft Visual Studio 14.0/VC/lib/libvcruntime.lib" "/c/Program Files (x86)/Windows Kits/10/Lib/10.0.10240.0/ucrt/x86/libucrt.lib" "/c/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86/uuid.lib"

echo
echo Running HelloWorld
./HelloWorld.exe

