##
## Makefile for libmy_extended in /home/aurelien/Documents/Lib_etna/castel_a/libmy_extended
## 
## Made by CASTELLARNAU Aurelien
## Login   <castel_a@etna-alternance.net>
## 
## Started on  Wed Feb  1 09:37:15 2017 CASTELLARNAU Aurelien
## Last update Sat Jul  1 01:39:24 2017 CASTELLARNAU Aurelien
##

CC      =       gcc

NAME    =       demo

LIB     =       ./libmy

CFLAGS  =       -W -Wextra -Werror -Wall -g -Iinclude/ -Ilibmy

LDFLAGS =       -lzmq -lczmq -L ./libmy -lmy

SRC     =       main.c \
		src/tools/argument.c \
		src/server/protocol.c \

OBJ     =       ${SRC:%.c=%.o}

RM      =       rm -f

all	:	lib	$(NAME)

lib	:
		$(MAKE)	-C	$(LIB)

libPar	:
		$(MAKE)	-C	$(LIBPAR)

re	:	clean	all

$(NAME)	:	$(OBJ)
		$(CC)	$(CFLAGS)	$(OBJ)	$(LDFLAGS)	-o	$(NAME)

clean	:
		$(RM)	$(OBJ)

fclean	:	clean
		$(RM)	$(NAME)

.PHONY	:	all	clean	fclean
