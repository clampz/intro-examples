all: bears malloc pwnme formatstring wildcopy reverseme

bears:
	gcc -m32 -z relro -z now -fPIE -pie -fstack-protector-all -o bears bears.c

malloc:
	gcc -m32 malloc.c -o malloc

pwnme:
	gcc -m32 -fno-stack-protector pwnme.c -o pwnme

formatstring:
	gcc -m32 -o formatstring formatstring.c

wildcopy:
	gcc -m32 -fno-stack-protector -o wildcopy wildcopy.c

reverseme:
	gcc -m32 reverseme.c -o reverseme
	rm reverseme.c

