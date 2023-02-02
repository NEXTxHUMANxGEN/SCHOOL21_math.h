CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage -ls21_math
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit --coverage
	OPEN = xdg-open
else
	CHECK_FLAGS = -lcheck
	OPEN = open
endif

TEST_COMPILE = $(CC+FLAGS) s21_math.a math_check.c $(CHECK_FLAGS) -L. -ls21_math

all: s21_math.a

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM

rebuild: clean all

test: 
	$(CC+FLAGS) -c s21_main.c --coverage -o s21_math.o
	ar rcs libs21_math.a *.o
	rm -rf *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a
	$(TEST_COMPILE)
	./a.out

gcov_report: test
	$(CC+FLAGS)  math_check.c s21_math.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	$(OPEN) ./report/index.html
	rm -rf *.gcda *.gcno *.info *.g*

s21_math.a: s21_math.o
	ar rcs libs21_math.a *.o
	rm -rf *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a

s21_math.o:
	$(CC+FLAGS) -c s21_main.c -o s21_math.o

check:
	clang-format -style=google -n *.c *.h
	make test