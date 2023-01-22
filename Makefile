CC = c++
DFLAGS = -fsanitize=addresss -g

src = main.cpp

NAME = bin

all: $(NAME)

$(NAME):$(src)
	@rm -rf bin
	$(CC) -Wall -Wextra -Werror -std=c++98 $(src) -o $(NAME)

debug:
	$(CC) $(src) $(DFLAGS)

clean:
	rm -rf $(NAME)
