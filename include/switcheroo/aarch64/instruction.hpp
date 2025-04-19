#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>

typedef struct 
{
    uint32_t word;
    uint8_t opcode;
    uint8_t rd, op1, op2;
    size_t v_address; // Virtual address

} InstructionInfo;


#endif // INSTRUCTION_HPP