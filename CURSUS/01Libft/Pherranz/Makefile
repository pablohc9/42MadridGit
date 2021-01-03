# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 23:35:51 by pherranz          #+#    #+#              #
#    Updated: 2020/11/05 18:42:31 by pherranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror

SRCS	= 	ft_atoi.c				\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c 		\
				ft_isalpha.c		\
				ft_isascii.c 		\
				ft_isdigit.c 		\
				ft_isprint.c		\
				ft_itoa.c			\
				ft_memccpy.c		\
				ft_memchr.c			\
				ft_memcmp.c 		\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c 		\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_strchr.c 		\
				ft_strdup.c 		\
				ft_strjoin.c 		\
				ft_strlcat.c 		\
				ft_strlcpy.c 		\
				ft_strlen.c 		\
				ft_strmapi.c		\
				ft_strncmp.c 		\
				ft_strnstr.c 		\
				ft_strrchr.c 		\
				ft_strtrim.c 		\
				ft_substr.c 		\
				ft_tolower.c 		\
				ft_toupper.c	
SRCS_B	=	ft_lstadd_back.c		\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c
			
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	cc
RM		=	rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
			ar rc  $(NAME) $(OBJS)
			ranlib $(NAME)
bonus:		$(OBJS) $(OBJS_B)
			ar rc $(NAME) $(OBJS) $(OBJS_B)
			ranlib $(NAME)
all:		$(NAME)
clean:
			$(RM) $(OBJS) $(OBJS_B)
fclean:		clean
			$(RM) $(NAME)
debug:		CFLAGS += -g3 -fsanitize=address
debug:		all
re:			fclean bonus
.PHONY:		bonus all clean fclean re
