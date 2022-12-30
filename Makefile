CC = c++
DFLAGS = -fsanitize=addresss -g

src = main.cpp

NAME = bin

all:$(NAME)
	$(CC) $(src) -o $(NAME)

debug:
	$(CC) $(src) $(DFLAGS)	