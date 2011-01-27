############################################################
#
# Author: Brian Gianforcaro - b.gianfo@gmail.com
#
############################################################
CC = g++ -g -Wall -Wextra 

default: atoi itoa merge quick hashmap btsearch trie

trie: trie.cpp
	$(CC) trie.cpp -o trie

btsearch: btsearch.cpp
	$(CC) btsearch.cpp -o btsearch

hashmap: hashmap.cpp
	$(CC) hashmap.cpp -o hashmap

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
	rm -rf hashmap
	rm -rf hashmap.d*
	rm -rf btsearch
	rm -rf btsearch.d*



