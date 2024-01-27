FLAG = -Wall -Werror -Wextra
FILES=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${FILES})
GCO=--coverage
UNAME := $(shell uname)

TEST= ./test_SmartCalc/*.c

ifeq ($(UNAME), Linux)
	GFLAGS = -lcheck -lpthread -lrt -lm -lsubunit
endif

ifeq ($(UNAME), Darwin)
	GFLAGS = -lcheck
endif

all:

install: uninstall
	mkdir build
	@cd Front/FrontCalc/ && qmake && make && make clean && rm Makefile

uninstall:
	rm -rf build

run:
	open build/FrontCalc.app

dvi:
	open ./Use_Calc.md
	
dist:
	mkdir SmartCalc_v1.0/
	mkdir SmartCalc_v1.0/src
	cp -R Front test_SmartCalc *.c *.h Makefile SmartCalc_v1.0/src
	tar cvzf SmartCalc_v1.0.tgz SmartCalc_v1.0/
	rm -rf SmartCalc_v1.0

test: clean 
	@gcc $(FLAG) -o test $(TEST) $(FILES) $(GFLAGS)
	./test

main: clean
	gcc $(FLAG) -g -o main $(FILES)
	./main


gcov_report: clean
	@gcc $(FLAG) $(GCO) SmartCalc_Math.c SmartCalc_Validator.c SmartCalc_Parse.c SmartCalc_PolishNotation.c Stack_func.c -o test test_SmartCalc/*.c $(GFLAGS)
	./test
	lcov --capture --directory . --output-file=coverage.info
	genhtml coverage.info --output-directory=res
	open ./res/index.html

clean:
	-rm -rf main *.dSYM test *.gcda *.gcno *.info ./res
	clear

leaks: 
	@leaks -atExit -- ./test

valgrind:
	@valgrind --tool=memcheck --leak-check=yes ./test