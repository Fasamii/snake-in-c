#pragma once
// defining terminal control utilities

// handles key press and returns pressed key
char parse_input(char move);

// gets terminal size in cols and rows and returns struct with x and y
vec get_term_size();

// sets terminal stat to non canonical and disables echo
void init_term();

// sets terminal back to canonical and echo mode
void close_term();

// listens for ctrl + c and executes passed foo
void listen_for_close(void *foo);
