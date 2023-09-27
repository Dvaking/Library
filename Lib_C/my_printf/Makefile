##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/toolbox/decimal_to_other_base.c		\
    			src/toolbox/my_compute_power_rec.c		\
    			src/toolbox/my_printf.c					\
    			src/toolbox/my_revstr.c					\
    			src/toolbox/my_strlen.c					\
				src/toolbox/my_strlowcase.c				\
    			src/toolbox/print_char.c				\
    			src/toolbox/print_string.c				\
				src/flags/obtain_c.c					\
				src/flags/obtain_percent.c				\
				src/flags/obtain_s.c					\
				src/flags/obtain_d_i.c					\
				src/flags/obtain_u.c					\
				src/flags/obtain_x.c					\
				src/flags/obtain_x_maj.c				\
				src/flags/obtain_o.c					\
				src/flags/obtain_f.c					\
				src/flags/obtain_f_sub.c				\
				src/flags/obtain_f_ters.c				\
				src/flags/obtain_e.c					\
				src/flags/obtain_e_sub.c				\
				src/flags/obtain_e_ters.c				\
				src/flags/obtain_e_quad.c				\
				src/flags/obtain_p.c					\
				src/flags/obtain_b.c					\
				src/flags/obtain_g.c					\
				src/flags/obtain_precision.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy_printf.a

CPPFLAGS	=	-I./include/

LDLIBS		=	-lcriterion

MY			=	my.h

$(NAME): $(OBJ)
	ar rc $@ $^
	mv ${NAME} ../

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f unit_tests*

re: fclean all

unit_tests:	re
		gcc -o unit_tests $(SRC) tests/test_printf.c $(CPPFLAGS)\
		--coverage -lcriterion

tests_run:	unit_tests
			./unit_tests

.PHONY: all re fclean clean
