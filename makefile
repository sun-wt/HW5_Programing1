all: hw0501.o hw0501another.c hw0502.o hw0502another.c hw0503.o hw0503another.c hw0504.o hw0504another.c hw0505.o hw0505another.c
	gcc hw0501another.c hw0501.o -o hw0501
	gcc hw0502another.c hw0502.o -o hw0502
	gcc hw0503another.c hw0503.o -o hw0503
	gcc hw0504another.c hw0504.o -o hw0504 -lm
	gcc hw0505another.c hw0505.o -g -o hw0505  

hw0501: hw0501.c
	gcc -c hw0501.c -o hw0501.o
	gcc -shared hw0501.o -o libhw0501.so

hw0502: hw0502.c
	gcc -c hw0502.c -o hw0502.o
	gcc -shared hw0502.o -o libhw0502.so

hw0503: hw0503.c
	gcc -c hw0503.c -o hw0503.o
	gcc -shared hw0503.o -o libhw0503.so

hw0504: hw0504.c
	gcc -c hw0504.c -o hw0504.o -lm
	gcc -shared hw0504.o -o libhw0504.so

hw0505: hw0505.c
	gcc -c hw0505.c -g -o hw0505.o 
	gcc -shared hw0505.o -o libhw0505.so

