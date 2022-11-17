########################
###     VARIABLES    ###
########################

### COLORS ###
RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
BLUE	=	\033[0;94m
END_C	=	\033[0m

### FILES AND DIRECTORIES ###
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
INCLUDES = include

DIR_IS = ft_is/
FILES_IS = ft_isalnum ft_isalpha ft_isascii\
	 ft_isdigit ft_isprint

DIR_LST = ft_lst/
FILES_LST = ft_lstnew ft_lstadd_front ft_lstsize\
	 ft_lstlast ft_lstadd_back ft_lstdelone\
	 ft_lstclear ft_lstiter ft_lstmap

DIR_MEM = ft_mem/
FILES_MEM = ft_bzero ft_calloc ft_memchr\
	 ft_memcmp ft_memcpy ft_memmove ft_memset

DIR_PUT = ft_put/
FILES_PUT = ft_putchar_fd ft_putendl_fd ft_putnbr_fd\
	 ft_putstr_fd

DIR_STR = ft_str/
FILES_STR = ft_split ft_strchr ft_strdup\
	 ft_striteri ft_strjoin ft_strlcat\
	 ft_strlcpy ft_strlen ft_strmapi\
	 ft_strncmp ft_strnstr ft_strrchr\
	 ft_strtrim ft_substr

DIR_TO = ft_to/
FILES_TO = ft_atoi ft_itoa ft_tolower ft_toupper

DIR_GNL = ft_gnl/
FILES_GNL = ft_gnl ft_gnl_utils

DIR_PRINT = ft_printf/
FILES_PRINT = ft_print_hex ft_print_num ft_print_ptr\
	 ft_print_str ft_printf

DIR_SRC = src/
FILES_SRC += $(addprefix $(DIR_IS), $(FILES_IS))
FILES_SRC += $(addprefix $(DIR_LST), $(FILES_LST))
FILES_SRC += $(addprefix $(DIR_MEM), $(FILES_MEM))
FILES_SRC += $(addprefix $(DIR_PUT), $(FILES_PUT))
FILES_SRC += $(addprefix $(DIR_STR), $(FILES_STR))
FILES_SRC += $(addprefix $(DIR_TO), $(FILES_TO))
FILES_SRC += $(addprefix $(DIR_GNL), $(FILES_GNL))
FILES_SRC += $(addprefix $(DIR_PRINT), $(FILES_PRINT))

DIR_OBJ = obj/
FILES_OBJ = $(addprefix $(DIR_OBJ), $(addsuffix .o, $(FILES_SRC)))


#####################
### PROGRAM RULES ###
#####################

all: $(NAME)

$(NAME): $(FILES_OBJ)
	@ar rsc $(NAME) $(FILES_OBJ)
	@echo "[$(BLUE)> LIBFT LIBRARY COMPILED $(END_C)][$(GREEN) SUCCESS! $(END_C)] $(NAME)"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c | DIRECTORIES
	@gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	@echo "[$(YELLOW) *LIBFT* COMPILED OBJECT $(END_C)][$(GREEN)-->$(END_C)] $@"

DIRECTORIES:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_IS))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_LST))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_MEM))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_PUT))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_STR))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_TO))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_GNL))
	@mkdir -p $(addprefix $(DIR_OBJ), $(DIR_PRINT))


###################
### CLEAN RULES ###
###################

clean:
	@rm -rf $(DIR_OBJ)
	@echo "[$(RED) -LIBFT- OBJECTS DELETED $(END_C)][$(GREEN) CLEANED SUCCESS! $(END_C)]"

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(RED) -LIBFT- LIBRARY DELETED $(END_C)][$(GREEN) CLEANED SUCCESS! $(END_C)]"


re:	fclean all
