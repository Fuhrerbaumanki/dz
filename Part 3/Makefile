CC=g++
CFLAGS=-std=c++11

SRCS=main.cpp Application.cpp Pair.cpp Money.cpp Fraction.cpp
OBJS=$(SRCS:.cpp=.o)
TARGET=program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
CC=g++
CFLAGS=-std=c++11

SRCS=main.cpp Application.cpp Pair.cpp Money.cpp Fraction.cpp
OBJS=$(SRCS:.cpp=.o)
TARGET=program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
