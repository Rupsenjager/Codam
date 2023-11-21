NAME =		libftprintf.a
CC = 		cc
CFLAGS =	-Wall -Wextra -Werror
HEADER =	libftprintf.h
LIBFTDIR = 	./libft

sourcefiles = 	ft_printf.c\
				ft_putnbr.c\
				print_cases.c\
				print_char.c\
				print_str.c\
				check_length.c\
				print_adres.c\

objects =		$(sourcefiles:.c=.o)

all:			$(NAME)

$(NAME): $(objects)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@mv libft.a $(NAME)
	ar r $(NAME) $(objects)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(objects) $(LIBFTDIR)/*.o

fclean: clean
	rm -f $(NAME)

re: 			fclean all

.PHONY: all clean fclean re
