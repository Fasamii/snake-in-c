#include <termios.h>
#include <sys/select.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "./typedef.h"

int kb_hit() {
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &fds);
}

void noBlock() {
	struct termios ttyStat;
	tcgetattr(STDIN_FILENO, &ttyStat);
	ttyStat.c_lflag &= ~ICANON;
	ttyStat.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &ttyStat);
}

void block() {
	struct termios ttyStat;
	tcgetattr(STDIN_FILENO, &ttyStat);
	ttyStat.c_lflag |= ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &ttyStat);
}
