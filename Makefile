# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=Unity

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -Wfatal-errors

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/identifier.c \
  test/TestIdentifier.c \
  test/test_runners/TestIdentifier_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=

### END Unity Configuration

SRC = src/identifier.c
CPPCHECK_FLAGS = --enable=all
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all
SANITIZER_FLAGS = -fsanitize=address
OUT = identifier
#ALL = identifier

#all: $(ALL)
cppcheck: clean run-cppcheck
valgrind: clean identifier run-valgrind
sanitizers: clean run-sanitizers run-identifier
test: clean compile-tests run-tests

identifier: src/identifier.c
	$(C_COMPILER) $(CFLAGS) -o $(OUT) $(SRC)

cov: src/identifier.c
	$(C_COMPILER) $(CFLAGS) -fprofile-arcs -ftest-coverage -o $(OUT) $(SRC)

run-cppcheck:
	cppcheck $(CPPCHECK_FLAGS) $(SRC)

run-valgrind:
	valgrind $(VALGRIND_FLAGS) ./$(OUT) < $(ARGS)
	
run-sanitizers:
	$(C_COMPILER) $(CFLAGS) $(SANITIZER_FLAGS) -o $(OUT) $(SRC)
	
run-identifier:
	- ./$(OUT) < $(ARGS)

# Unity tests
compile-tests:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

run-tests:
	- ./$(TARGET1) -v

# Clean up all
clean:
	$(CLEANUP) $(ALL) $(TARGET1) $(OUT) *.o cov* *.dSYM *.gcda *.gcno *.gcov

