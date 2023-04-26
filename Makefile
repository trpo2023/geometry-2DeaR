APP_NAME = geometry
LIB_NAME = libgeometry

CFLAGS = -Wall -w
CPPFLAGS = -I src -MMD
GDB = -g -O0

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

#test
TEST_DIR := test
TEST_PATH = $(OBJ_DIR)/$(TEST_DIR)
TEST_OBJ = $(OBJ_DIR)/geometry-test/parser_test.o $(OBJ_DIR)/geometry-test/main.o 

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all clean run test
all: $(LIB_PATH) test $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(GDB) $(CPPFLAGS) $^ -o $@ -lm

$(TEST_PATH) : $(TEST_OBJ) $(LIB_PATH)
	$(CC) $(CFLAGS) $^ -o  $@

$(OBJ_DIR)/geometry-test/main.o: $(TEST_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -Ithirdparty -I$(SRC_DIR) -L$(BIN_DIR) -lgeometry -o $@

$(OBJ_DIR)/geometry-test/parser_test.o: $(TEST_DIR)/parser_test.c
	$(CC) $(CFLAGS) -c $< -Ithirdparty -I$(SRC_DIR) -L$(BIN_DIR) -lgeometry -o $@

test: $(LIB_PATH) $(TEST_PATH)
	./$(TEST_PATH)		

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(GDB) $(CPPFLAGS) $< -o $@ 
run:
	./$(APP_PATH)

clean:
	@rm -f  $(APP_PATH) $(LIB_PATH) $(LIB_OBJECTS) $(APP_OBJECTS) $(DEPS)