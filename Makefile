CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = cryo-zip

SRC = \
	src/frequency.c \
	src/main.c

OBJ = $(SRC:.c=.o)

TEST_SRC = \
	tests/test_main.c \
	tests/test_frequency.c \
	src/frequency.c

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) example-data/test.txt

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all

debug: CFLAGS += -g -DDEBUG
debug: rebuild

test:
	$(CC) $(CFLAGS) $(TEST_SRC) -o test_runner
	./test_runner

clean-test: 
	rm -f test_runner

.PHONY: all run clean rebuild debug