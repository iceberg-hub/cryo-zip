CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = cryo-zip

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

TEST_SRC = \
	$(wildcard tests/*.c) \
	$(filter-out src/main.c, $(SRC))

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