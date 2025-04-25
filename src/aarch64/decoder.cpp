#include "../../include/switcheroo/aarch64/decoder.hpp"
#include <iostream>

using namespace switcheroo::aarch64;

Decoder::Decoder()
{
    this->pc = 0;
    this->decoded_bin = new std::vector<Instruction>();
}

void Decoder::decode_bin(const uint8_t *bin, size_t size)
{
    split_instructions(bin, size);
}

std::vector<Instruction> *Decoder::get_instructions() const
{
    return this->decoded_bin;
}

void Decoder::split_instructions(const uint8_t *bin, size_t size)
{

    if (size % 4 != 0)
    {
        throw std::runtime_error("Text section not aligned to 4 bytes.");
    }

    this->decoded_bin->clear();
    this->pc = 0;

    for (size_t i = 0; i < size; i += 4)
    {
        Instruction instruction;
        instruction.word = *(reinterpret_cast<const uint32_t *>(bin + i));
        instruction.v_address = this->pc;
        this->decoded_bin->push_back(instruction);
        this->pc += 4;
    }
}

void Decoder::first_dispatch(const uint32_t instruction)
{
    uint8_t op0 = (instruction >> 25) & 0xF; // bits 25 - 28

    if ((op0 >> 2) == 0x0)
    {
        // unallocated encoding
    }
    else if (op0 >> 2 == 0x2)
    {

        if (op0 & 0x2 == 0x0)
        {
            // Data processing - immediate
        }
        else
        {
            // Branches, Exception generating, and system instructions
        }
    }
    else if (op0 & 0x1 == 0x0)
    {
        // Loads and stores
    }
    else if (op0 & 0x2 == 0x2)
    {
        // Data Processing - Scalar Floating Point and Advanced SIMD
    }
    else
    {
        // Data Processing - Register
    }
}