NAME = Snake

SRCS = main.c evenement.c

OBJS = $(SRCS:.c=.o)

CFLAGS = `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all
