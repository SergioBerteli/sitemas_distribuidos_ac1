CXX = mpiCC 
CXXFLAGS = -Wall -Wextra 

SRCS = main.c primos.c lista.c 
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm  ./*.o
	rm  ./${TARGET}