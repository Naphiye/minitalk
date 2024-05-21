
COMPIL = cc
FLAGS = -Wall -Werror -Wextra 
PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m

HEADER_F = header/minitalk.h

CLIENT_SRCS = client.c

SERVER_SRCS = server.c

LIBFT = header/libft.a

PCLIENT = $(addprefix srcs/, $(CLIENT_SRCS))
PSERVER = $(addprefix srcs/, $(SERVER_SRCS))

C_OBJS = $(PCLIENT:srcs/%.c=objs/%.o)

S_OBJS = $(PSERVER:srcs/%.c=objs/%.o)

all : server client

objs/%.o : srcs/%.c
	@mkdir -p objs
	@$(COMPIL) $(FLAGS) -c $< -o $@

server : $(S_OBJS) $(HEADER_F)
	@$(COMPIL) $(FLAGS) -o server $(S_OBJS) $(LIBFT) 
	@echo  "$(PINK)\n     SERVER COMPILED \n$(NC)"

client : $(C_OBJS) $(HEADER_F)
	@$(COMPIL) $(FLAGS) -o client $(C_OBJS) $(LIBFT) 
	@echo  "$(BLUE)\n     CLIENT COMPILED \n$(NC)"


clean :
	@rm -rf objs/*.o
	@echo  "$(BLUE) \n     MINITALK CLEANED \n$(NC)"

fclean : clean
	@rm -f client server

re : fclean all

.PHONY : all clean fclean re bonus