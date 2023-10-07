NAME = rsa-cpu

CC = gcc
CFLAGS = -I includes/ -O3
SRC = sources/uassign.c \
      sources/udump.c \
      sources/udumpbin.c \
      sources/usize.c \
      sources/urand.c \
      sources/ulshift.c \
      sources/urshift.c \
      sources/ueq.c \
      sources/usup.c \
      sources/uinf.c \
      sources/usupeq.c \
      sources/uinfeq.c \
      sources/uadd.c \
      sources/usub.c \
      sources/umul.c \
      sources/udivmod.c \
      sources/umodexp.c \
      sources/upseudoprime.c \
      sources/uphi.c \
      sources/uegcd.c \
      sources/umodinv.c \
      sources/ursakeygen.c \
      sources/ursaimportkey.c \
      sources/ursaexportkey.c \
      sources/ursarun.c \
      sources/keygen.c \
      sources/sencrypt.c \
      sources/sdecrypt.c \

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
