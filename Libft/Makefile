# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoods <awoods@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 12:02:07 by awoods            #+#    #+#              #
#    Updated: 2021/04/19 20:57:01 by awoods           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c \
       ft_strlcpy.c \
       ft_strlcat.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_strncmp.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_atoi.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strmapi.c \
	   ft_itoa.c \
	   ft_split.c \
	   libft.h

B_SRCS = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c\
		 libft.h

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus	:	$(B_OBJS)
	ar rc $(NAME) $(B_OBJS)

%.o : %.c libft.h
	gcc $(CFLAGS) -c $< -o $@

clean   :
	rm -f *.o

fclean	:	clean
	$(RM) $(NAME)

re	    :	fclean all

.PHONY	:	all clean fclean re bonus
