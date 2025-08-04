NAME = philo
CC = cc
FLAGS = -g3 -Wall -Werror -Wextra

SRCS = main.c \
	   check_arguments.c \
	   ft_init_all.c \
	   get_current_time.c \
	   utils.c \
	   utils2.c \
	   philo_routine.c \
	   monitor_routine.c \
	   philo_state.c \
	   ft_free_philo.c \
	   set_philos.c \
	   simulation_finished.c


OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

# Create objects directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile individual object files and place them in objects directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

# Clean object files and remove objects directory
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re