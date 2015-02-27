
CC=g++ -ggdb3

problems := $(patsubst %.c++,%,$(wildcard *.c++))

all: $(problems)

%.o: %.c++
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f %.o $(problems)
