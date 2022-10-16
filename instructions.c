#include <stdbool.h>
#include <stdio.h>
typedef enum { PSH, ADD, POP, STOP } InstructionSet;
const int program[] = {0x0005, 0x0106, 0x1201, 0x2200, 0x3000};
// add 5 to reg0
// add 6 to reg1
// add reg0 and reg1 store in reg2
// pop reg2
// stop
int pc = -1;
int imm = 0;
int _reg0 = 0;
int _reg1 = 0;
int _reg2 = 0;
int instrNum = 0;

int registers[5];
bool running = true;

void fetch();
void decode();
void eval();

int main() {
  while (running) {
    fetch();
    decode();
    eval();
  }
}
void fetch() { pc++; }
void decode() {                       // disassembler
  int _instr = program[pc];           // fetch instruction
  instrNum = (_instr & 0xF000) >> 12; // instruction number
  _reg0 = (_instr & 0xF00) >> 8;
  _reg1 = (_instr & 0xF0) >> 4;
  _reg2 = (_instr & 0xF);
  imm = (_instr & 0xFF);
}
void eval() {
  switch (instrNum) {
  case STOP:
    running = false;
    break;
  case PSH:
    registers[_reg0] = imm;
    break;
  case ADD:
    registers[_reg0] = registers[_reg1] + registers[_reg2];
    break;
  case POP:
    printf("%d", registers[_reg0]);
    registers[_reg0] = 0;
    break;
  }
}
