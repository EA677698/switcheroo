#include "../../include/switcheroo/aarch64/decoder.hpp"
#include <iostream>

Decoder::Decoder()
{
    this->pc = 0;
    this->decoded_bin = new std::vector<InstructionInfo>();
}

void Decoder::decode_bin(const uint8_t* bin, size_t size)
{

    split_instructions(bin, size);

}

std::vector<InstructionInfo>* Decoder::get_instructions() const
{
    return this->decoded_bin;
}

void Decoder::split_instructions(const uint8_t* bin, size_t size)
{

    if (size % 4 != 0)
    {
        throw std::runtime_error("Text section not aligned to 4 bytes.");
    }

    this->decoded_bin->clear();
    this->pc = 0;

    for (size_t i = 0; i < size; i += 4)
    {
        InstructionInfo instruction;
        instruction.word = *(reinterpret_cast<const uint32_t*>(bin + i));
        instruction.v_address = this->pc;
        this->decoded_bin->push_back(instruction);
        this->pc += 4;
    }
}

void Decoder::decode_main_group(const uint32_t instruction)
{
    
}