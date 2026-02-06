CC = g++
CFLAGS = -g3

TARGET1 = oss
TARGET2 = user

all: $(TARGET1) $(TARGET2)

oss: oss.o
	$(CC) oss.o -o oss
user: user.o
	$(CC) user.o -o user

oss.o: oss.cpp
	$(CC) $(CFLAGS) -c oss.cpp
user.o: user.cpp

clean:
	rm -f *.o oss user
