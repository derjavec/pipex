NAME		=	pipex
NAME_B		= 	pipex_bonus
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror
RM			=	rm -rf
SRC			=	pipex.c  utils/ft_initialize_null.c utils/error.c utils/error_bonus.c utils/ft_cmd.c utils/free_all_bonus.c  utils/find_path.c utils/ft_split.c utils/ft_split_utils.c utils/ft_strchr.c utils/ft_strjoin.c utils/ft_substr.c utils/ft_strlen.c utils/ft_strdup.c utils/ft_strncmp.c utils/pars_path.c utils/pars_arg.c utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c  
OBJ			=	$(SRC:.c=.o)
SRC_B		=	Bonus/pipex_bonus.c Bonus/heredoc.c utils/ft_initialize_null.c utils/error.c utils/error_bonus.c utils/ft_cmd.c utils/free_all_bonus.c  utils/find_path.c utils/ft_split.c utils/ft_split_utils.c utils/ft_strchr.c utils/ft_strjoin.c utils/ft_substr.c utils/ft_strlen.c utils/ft_strdup.c utils/ft_strncmp.c utils/pars_path.c utils/pars_arg.c utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c  
OBJ_B		=	$(SRC_B:.c=.o)

HEADER		= pipex.h utils/gnl/get_next_line.h Bonus/pipex_bonus.h


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)
	
fclean: clean
	rm -f $(NAME) $(NAME_B)
	
re: fclean all

.PHONY: all clean fclean re