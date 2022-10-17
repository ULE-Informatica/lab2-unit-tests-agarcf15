# dps-laboratory2

A la hora de instalar GTest, he usado la informacion de las siguientes páginas:

https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

He segido los pasos de esta página, pero "actualizando" los comandos a una versión compatible con ubuntu 22.04

https://installati.one/ubuntu/22.04/googletest/

https://www.linuxcapable.com/how-to-install-cmake-on-ubuntu-22-04-lts/


Los comandos de instalación ha sido:

`sudo apt -y install googletest` ¿?

`sudo apt-get install libgtest-dev`

`sudo apt -y install cmake`

Después de instañar, debemos movernos a la carpeta gtest

`cd /usr/src/googletest`

Y aquí, compilar con cmake la liberia

`sudo cmake CMakeList.txt`

Y ejecuramos cmake

`sudo make`

Ahora copiamos los ficheros libgtest generados (el propio libgtest.a y libgtest_main.a) de /lib a /usr/lib

`cp ./lib/libgtest*.a /usr/lib`

Tras esto, abrimos los ficheros y comprobamos que tests.cpp tiene un error en: #include <gtest/gtest.h>
Para solucionarlo, en mi caso usando VSC, añadimos en el include path "/usr/lib" para que pueda acceder a las librerias de gtest instaladas

Volvemos a nuestro ejercicio

`cd /Documents/DPS/lab2-unit-tests-agarcf15/`

Y compilamos y ejecutamos los test:

`cmake CMakeList.txt`

Compila con warnings: 

Target "runTests" links to target "Threads::Threads" but the target was not  found.  Perhaps a find_package() call is missing for an IMPORTED target, or  an ALIAS target is missing?

`make`

al ejecutar, obtengo la siguiente salida:

alex@alex-HP-Pavilion-Power-Laptop-15-cb0xx:~/Documents/DPS/lab2-unit-tests-agarcf15$ make
[ 50%] Building CXX object CMakeFiles/runTests.dir/tests.cpp.o
[100%] Linking CXX executable runTests
/usr/bin/ld: cannot find -lThreads::Threads: No such file or directory
collect2: error: ld returned 1 exit status
make[2]: *** [CMakeFiles/runTests.dir/build.make:98: runTests] Error 1
make[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/runTests.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
alex@alex-HP-Pavilion-Power-Laptop-15-cb0xx:~/Documents/DPS/lab2-unit-tests-agarcf15$ 

`./runTest`
