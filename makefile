output: abelianSandpile.o
	gcc abelianSandpile.o -o output

abelianSandpile.o: abelianSandpile.c
	gcc -c abelianSandpile.c

run: output
	./output --fps 1 2 2 7 3 2 8 4 2 8 2 3 -1
	
clean:
	rm *.o
	rm output
