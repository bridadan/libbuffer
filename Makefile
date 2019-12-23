SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCLUDE = include
LIBRARY_ARCHIVE = libbuffer.a
INC_DIR = include
INC_HEADER = buffer.h

DEST_PREFIX= /usr/local
DEST_LIB_DIR= $(DEST_PREFIX)/lib
DEST_INC_DIR= $(DEST_PREFIX)/include

TEST_SRC = $(wildcard test/*.c)
TEST_OBJ =$(TEST_SRC:.c=.o)

LDFLAGS = -L . -l buffer
CFLAGS = -g

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(CFLAGS)

$(LIBRARY_ARCHIVE): $(OBJ)
	ar rcs $@ $^

test/test: $(TEST_OBJ) $(LIBRARY_ARCHIVE)
	$(CC) -o $@ $(TEST_SRC) $(LDFLAGS) -I $(INCLUDE) $(CFLAGS)

test: test/test
	./test/test

install: $(LIBRARY_ARCHIVE)
	mkdir -p $(DEST_LIB_DIR) $(DEST_INC_DIR)
	install -m 644 $(LIBRARY_ARCHIVE) $(DEST_LIB_DIR)
	install -m 644 $(INC_DIR)/$(INC_HEADER) $(DEST_INC_DIR)

uninstall:
	rm -f $(addprefix $(DEST_LIB_DIR)/,$(LIBRARY_ARCHIVE))
	rm -f $(addprefix $(DEST_INC_DIR)/,$(INC_HEADER))

.PHONY: clean
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(LIBRARY_ARCHIVE)
