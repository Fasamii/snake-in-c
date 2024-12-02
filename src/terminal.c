#include <termios.h>
#include <sys/select.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <time.h>
#include <fcntl.h>
#include "./typedef.h"

int kb_hit() {
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	fd_set fd;
	FD_ZERO(&fd);
	FD_SET(STDIN_FILENO, &fd);
	select(STDIN_FILENO + 1, &fd, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &fd);
}

char parse_input(char move) {
	char key;
	while(kb_hit() == 1) {
		printf("<|\e[38;5;23mpars input\e[0m|> >==< <|key -> %c|>\n", key);
		key = fgetc(stdin);
		if(key == 'w' || key == 's' || key == 'a' || key == 'd' || key == 'q') {
			move = key;
		}
	}
	return move;
}

vec get_term_size() {
	 struct winsize win_size;
	 ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);
	 vec size;
	 size.x = win_size.ws_row;
	 size.y = win_size.ws_col;
	 return size;
}

void init_term() {
	printf("\e7\e[?47h");
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag &= ~ICANON;
	tty.c_cc[VMIN] = 1;
	tty.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void close_term() {
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag |= ICANON;
	tty.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
	printf("\e[2J\e[?47l\e8");
}

void listen_for_close(void *foo) {
	signal(SIGINT, foo);
}
