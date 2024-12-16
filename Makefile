# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguinea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 15:29:23 by aguinea           #+#    #+#              #
#    Updated: 2024/12/10 15:56:11 by aguinea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 COLOR CODE                                   #
################################################################################

BOLD			= \033[1m

END         	= \e[0m

DEF_COLOR   	= \033[0;39m

ORANGE    		= \033[38;5;214m

PINK      		= \033[38;5;213m

BLUE      		= \033[0;94m

YELLOW    		= \033[0;93m

BOLD_YELLOW 	= \033[1;33m

WHITE 			= \033[0;97m

ITALIC 			= \033[3m

GREEN =			\033[0;92m


################################################################################
#                             COMPILATION & MORE                               #
################################################################################

NAME 			= pipex

CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra -g -fsanitize=address

MAKE_LIB 		= ar -rcs

RM 				= rm -f


################################################################################
#                                 PATH/TO/SRCS                                 #
################################################################################

SRCS_D 		= ./mandatory/src

OBJ_D 		= ./mandatory/obj

LIBFT_D 	= ./mandatory/libft

INCLUDE_D	= ./mandatory/include


################################################################################
#                               SRCS && OBJS                                   #
################################################################################

LIBFT 			= $(LIBFT_D)/libft.a

HEADER			= $(INCLUDE_D)/pipex.h
HEAD_LIBFT		= $(LIBFT_D)/libft.h
INCLUDE			= $(HEADER) $(HEAD_LIBFT)

SRCS 			= $(SRCS_D)/pipex.c			\
				  $(SRCS_D)/pipex_utils.c	\

OBJS			= $(patsubst $(SRCS_D)/%.c,$(OBJ_D)/%.o,$(SRCS))

DEP				= $(OBJ:.o=.d) $(MAIN_OBJ:.o=.d)
-include $(DEP)

################################################################################
#                                 MAKEFILE                                     #
################################################################################

all					: libs $(NAME)

libs				:
					@make -C $(LIBFT_D) > /dev/null
					@make -C $(LIBFT_D) bonus > /dev/null

$(NAME)				: $(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_D) -lft -o $(NAME)
					@echo "\n$(PINK)[ＯＫ✔]		➤➤		$(GREEN)Executable created$(DEF_COLOR)\n"

$(OBJ_D)/%.o		: $(SRCS_D)/%.c $(INCLUDE) Makefile | $(OBJ_D)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "\n$(PINK)[ＯＫ✔]		➤➤		$(GREEN)Created object file: $@$(DEF_COLOR)\n"
				

$(OBJ_D)			:
					@mkdir -p $(OBJ_D)

clean:
					@$(MAKE) -C $(LIBFT_D) clean > /dev/null
					@rm -rf $(OBJ_D)
					@echo "\n$(PINK)[ＯＫ✔]		➤➤		$(GREEN)Cleaned up object$(DEF_COLOR)\n"

fclean: 			clean
					@$(MAKE) -C $(LIBFT_D) fclean > /dev/null
					@rm -f $(NAME)
					@echo "\n$(PINK)[ＯＫ✔]		➤➤		$(GREEN)All executables and objects removed$(DEF_COLOR)\n"

re					: fclean all

.PHONY: all clean fclean re
