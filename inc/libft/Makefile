NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FUNCTIONS = ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_itoa.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memfree.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_split.c \
			ft_strchr.c \
			ft_isspace.c \
			ft_isnbr.c	\
			ft_atoll.c	\
			ft_lstmap.c \
			ft_lstiter.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstnew.c	\
			get_next_line.c \
			get_next_line_utils.c \

OBJECTS = $(FUNCTIONS:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@rm -f $(NAME) $(OBJECTS_BONUS)

re: fclean all

.PHONY:	re clean fclean all bonus