############################################################
#
# Author: Brian Gianforcaro - b.gianfo@gmail.com
#
############################################################
CC = g++ -g -Wall -Wextra 

default: atoi itoa merge quick

merge: mergesort.cpp
	$(CC) mergesort.cpp -o merge

quick: quicksort.cpp
	$(CC) quicksort.cpp -o quick

atoi: atoi.cpp
	$(CC) atoi.cpp -o atoi

itoa: itoa.cpp
	$(CC) itoa.cpp -o itoa


clean:
	rm -rf atoi
	rm -rf atoi.d*
	rm -rf itoa
	rm -rf itoa.d*
	rm -rf merge 
	rm -rf merge.d*
	rm -rf quick
	rm -rf quick.d*


