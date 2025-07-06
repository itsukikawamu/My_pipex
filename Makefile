# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:17:32 by ikawamuk          #+#    #+#              #
#    Updated: 2025/07/06 18:52:02 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
BONUS_NAME = 

CC = cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))
AR = ar
ARFLAGS = rcs
RM = rm -f
RMDIR = rm -rf

SRCDIR = src
# BONUS_SRCDIR = src/bonus
OBJDIR = obj
# BONUS_OBJDIR = obj/bonus
INCDIR = include
LIBFTDIR = libft
TMPDIR = ar_tmp

SRCFILES =	main.c\
			split_cmd_str.c\
			split_util.c\
			error.c\
			validate.c\
			utils.c\
			set_ctx.c\
			pipex_core.c\
			
			
# BONUS_SRCFILES = $(patsubst %.c, %_bonus.c, $(SRCFILES))

SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
# BONUS_SRCS = $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
# BONUS_OBJS = $(patsubst $(BONUS_SRCDIR)/%.c, $(BONUS_OBJDIR)/%.o, $(BONUS_SRCS))

INCLUDES = $(INCDIR) $(LIBFTDIR)/include

LIBFT = $(LIBFTDIR)/libft.a

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all

all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@mkdir -p $(BONUS_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean	
	@$(RMDIR) $(OBJDIR) $(BONUS_OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@	

test: all
	@$(CC) $(CFLAGS) test.c $(LIBFT) -o test
	$(VALGRIND) $(VALGRIND_FLAGS) ./test

.PHONY:all clean fclean re test bonus
