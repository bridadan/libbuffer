SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCLUDE = include
LIB_ARCHIVE = libbuffer.a

TEST_SRC = $(wildcard test/*.c)
TEST_OBJ =$(TEST_SRC:.c=.o)

LDFLAGS = -L . -l buffer
CFLAGS = -g

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(CFLAGS)

$(LIB_ARCHIVE): $(OBJ)
	ar rcs $@ $^

test/test: $(TEST_OBJ) $(LIB_ARCHIVE)
	$(CC) -o $@ $(TEST_SRC) $(LDFLAGS) -I $(INCLUDE) $(CFLAGS)


test: test/test
	./test/test

.PHONY: clean
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(LIB_ARCHIVE)
