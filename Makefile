
CC=gcc
SRC=t9search.c
OUT=t9search
FLAGS= -o 
BFLAGS=-std=c99 -Wall -Wextra -Werror

all:
	$(CC) $(BFLAGS) $(SRC) $(FLAGS) $(OUT)

test:
	./t9search 686 <textfile.txt
	./t9search 12 <textfile.txt

clean:
	rm *.exe