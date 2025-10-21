CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -O0


TARGET = main
OBJS = main.o linklist.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c linklist.h
	$(CC) $(CFLAGS) -c main.c

linklist.o: linklist.c linklist.h
	$(CC) $(CFLAGS) -c linklist.c

clean:
	rm -f $(TARGET) $(OBJS)
