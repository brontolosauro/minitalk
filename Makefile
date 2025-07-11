CC		= cc
CFLAGS	= -g -Wall -Werror -Wextra

SERVER	= server
CLIENT	= client

SRCS_SERVER = server.c
SRCS_CLIENT	= client.c

OBJS_SERVER = $(SRCS_SERVER:%.c=%.o)
OBJS_CLINET = $(SRCS_CLIENT:%.c=%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFTDIR)

$(SERVER): $(OBJS_SEVER)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re	
