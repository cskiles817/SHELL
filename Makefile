wish: main.c shell.c shell.h
	gcc -Wall -Werror -o wish main.c shell.c

clean:
	rm -f wish
