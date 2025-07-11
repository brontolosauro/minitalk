CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

SERVER	= server
CLIENT	= client

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): server.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(CLIENT): client.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
