#pragma once

// sets termianal mode to canonical
void block();

// sets terminal to non canonical mode
void noBlock();

// returns 1 if keyboard was triggered
int kb_hit();
