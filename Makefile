# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/03/14 16:29:37 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftbi.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g
INC=-I inc
LIB=

SRC=src/ftbi_cond_1.c src/ftbi_cond_2.c src/ftbi_del.c src/ftbi_del.c \
	src/ftbi_new.c src/ftbi_alloc.c src/ftbi_set_digit.c src/ftbi_utils_1.c \
	src/ftbi_add.c src/ftbi_neg.c src/ftbi_new_special.c src/ftbi_sub.c \
	src/ftbi_mul.c src/ftbi_utils_2.c src/ftbi_div_special.c \
	src/ftbi_div_backend.c src/ftbi_div.c

SRC_TEST=testing/main.c testing/test.c testing/assert.c
UNIT_TEST_FILE=testing/unit_tests.c
INDEXED_TESTS=testing/unit_tests_indexed.c

OBJ:=$(shell echo $(SRC) | sed "s/\.c/\.o/g" | sed "s/src\//bin\//g")

OBJ_TEST:=$(shell echo $(SRC_TEST) | sed "s/\.c/\.o/g" | sed "s/testing\//bin\//g")

all: $(NAME)

$(NAME): bin
	@ar rs $(NAME) $(OBJ)
	@echo "Libftbi compiled."

bin: $(SRC)
	@mkdir -p bin
	@$(CC) -c $(CFLAGS) $(INC) $(SRC)
	@mv *.o bin/

clean:
	@rm -rf bin
	@rm -f test_results.txt
	@rm -f $(INDEXED_TESTS)
	@echo "libftbi: Object files removed."

fclean:
	@rm -rf bin
	@rm -f test_results.txt
	@rm -f $(NAME)
	@rm -f $(INDEXED_TESTS)
	@rm -rf test.dSYM
	@rm -rf test
	@echo "libftbi: Object files and library removed."

re:
	@make fclean
	@make all

test_index: $(UNIT_TEST_FILE)
	@cp $(UNIT_TEST_FILE) $(INDEXED_TESTS)
	@echo "const t_unit_test g_unit_tests[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*//g" | sed "s/(void)/,/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)
	@echo "" >> $(INDEXED_TESTS)
	@echo "const char *g_unit_test_names[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*/\"/g    " | sed "s/(void)/\",/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)

test: $(NAME) $(SRC_TEST) test_index
	@rm -f test_results.txt
	@$(CC) $(CFLAGS) $(INC) $(LIB) -o test $(NAME) $(SRC_TEST) $(INDEXED_TESTS)

t:
	@make re
	@make test

f:
	@make fclean
