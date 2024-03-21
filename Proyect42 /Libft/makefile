# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 12:13:06 by alvdelga          #+#    #+#              #
#    Updated: 2024/03/20 10:28:31 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strrchr.c \
       ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_tolower.c \
       ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_toupper.c \
       ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strnstr.c ft_strncmp.c \
	   ft_substr.c ft_strjoin.c ft_itoa.c ft_strmapi.c ft_putstr_fd.c ft_putchar_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c
		
 		  
OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
