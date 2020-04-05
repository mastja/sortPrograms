# macro tells which compiler to use
CC = g++

# macro says using c++11 standard
CFLAGS = -std=c++11 -c

#run "make all" in the command line to compile all 3 programs
all: insertsort merge

#merge sort program
merge: mergesort.o
	$(CC) mergesort.o -o merge

mergesort.o:
	$(CC) $(CFLAGS) mergesort.cpp

#insert sort program
insert: insertsort.o
	$(CC) insertsort.o -o insert

insertsort.o:
	$(CC) $(CFLAGS) insertsort.cpp

# make command for insert sort program
#insert: insertsort.o

#insertsort.o: insertsort.cpp data.txt
#	$(CC) $(CFLAGS) -o insertsort.cpp data.txt

# make command for merge sort program
#merge: mergesort.o

#mergesort.o: mergesort.cpp data.txt
#	$(CC) $(CFLAGS) mergesort.cpp -o data.txt

# data.txt file for testing
#data.txt:
#	echo "4 19 2 5 11" > data.txt
#	echo "8 1 2 3 4 5 6 1 2" >> data.txt


clean:
	rm *.o
#	rm -f merge.out
#	rm -f insert.out
#	rm -f *.txt