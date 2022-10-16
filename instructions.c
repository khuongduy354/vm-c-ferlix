#include <stdbool.h>
#include <stdio.h>
typedef enum { PSH, ADD, POP, STOP } InstructionSet;

const int program[] = {PSH, 5, PSH, 6, ADD, POP, STOP};

int stack[256];
int ip = 0;  // instruction pointer
int sp = -1; // stack pointer
bool running = true;

int fetch();
void eval();

int main() {
  while (running) {
    int next_instr = fetch();
    eval(next_instr);
    if (next_instr == STOP) {
      running = false;
    }
    ip++;
  }
}
int fetch() { return program[ip]; }

void eval(InstructionSet instr) {
  switch (instr) {
  case STOP:
    running = false;
    break;
  case PSH: {
    sp++;
    stack[sp] = program[++ip];
    break;
  }
  case POP: {
    int val_popped = stack[sp--];
    printf("popped %d\n", val_popped);
    break;
  }
  case ADD: {
    int val_1 = stack[sp--];
    int val_2 = stack[sp--];
    stack[++sp] = val_1 + val_2;
  }
  }
}
