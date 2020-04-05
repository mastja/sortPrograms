# macro tells which compiler to use
CC = g++

# macro says using c++11 standard
CFLAGS = -std=c++11 -c

#run "make all" in the command line to compile all 3 programs
all: insertsort mergesort

# make command for insert sort program
insertsort: insertsort.o
	$(CC) $(CFLAGS) -o insertsort.cpp

# make command for merge sort program
mergesort: mergesort.o
	$(CC) $(CFLAGS) -o mergesort.cpp

# data.txt file for testing
#data.txt:
#	echo "4 19 2 5 11" > data.txt
#	echo "8 1 2 3 4 5 6 1 2" >> data.txt

#merge sort program
#mergesort: MergeSortDriver.o
#	$(CC) MergeSortDriver.o -o mergesort

#MergeSortDriver.o:
#	$(CC) $(CFLAGS) MergeSortDriver.cpp

clean:
	rm *.o
	rm -f merge.out
	rm -f insert.out
	rm -f *.txt

#clean and then compile

refresh: clean all