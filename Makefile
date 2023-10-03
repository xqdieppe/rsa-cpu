NAME = rsa-cpu

CC = gcc
CFLAGS = -I includes/ -g3
SRC = sources/uassign.c \
      sources/udump.c \
      sources/urand.c \
      sources/ulshift.c \
      sources/usup.c \
      sources/uinf.c \
      sources/usupeq.c \
      sources/uadd.c \
      sources/usub.c \
      sources/umul.c \
      sources/udiv.c \

NAME_SRC = sources/rsa-cpu.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(NAME_SRC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
