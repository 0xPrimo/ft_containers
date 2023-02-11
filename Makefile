CC = c++
DFLAGS = -fsanitize=addresss -g

src = main.cpp

NAME = bin

all: $(NAME)

$(NAME):$(src)
	@rm -rf bin
	$(CC)  $(src) -o $(NAME)

debug:
	$(CC) $(src) $(DFLAGS)

clean:
	rm -rf $(NAME)

re:clean all