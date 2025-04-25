#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>
#include "instruction_type.hpp"

namespace switcheroo::aarch64{

    typedef struct {
        uint32_t word;
        uint8_t opcode;
        uint8_t rd, op1, op2;
        size_t v_address; // Virtual address
        InstructionType type;

    } Instruction;

}


#endif // INSTRUCTION_HPP