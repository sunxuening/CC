all: script
script:
	gcc -O2 bitset.c -lm -o bitset
	gcc -O2 comparison-sort.c -lm -o comparison-sort
	gcc -O2 isprime.c -lm -o isprime
	gcc -O2 lis.c -lm -o lis

clean:
	rm bitset
	rm comparison-sort
	rm lis
	rm isprime
