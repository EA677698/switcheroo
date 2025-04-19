#ifndef X64_INSTRUCTION_HPP
#define X64_INSTRUCTION_HPP

#include <cstdint>

typedef struct 
{
    uint32_t raw;
    uint8_t opcode;
    uint8_t rd, op1, op2;
    size_t v_address; // Virtual address
    size_t source_address; // Original ARM address

} X64Instruction;


#endif // X64_INSTRUCTION_HPP