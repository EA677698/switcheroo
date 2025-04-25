#ifndef DECODER_HPP
#define DECODER_HPP

#include <cstdint>
#include <vector>
#include "instruction.hpp"

namespace switcheroo::aarch64
{
    class Decoder
    {

    public:
        Decoder();
        ~Decoder() = default;

        void decode_bin(const uint8_t *bin, size_t size);

        std::vector<Instruction> *get_instructions() const;

    private:
        void split_instructions(const uint8_t *bin, size_t size);

        void first_dispatch(const uint32_t instruction); // Main group encoding

        size_t pc; // Program Counter
        std::vector<Instruction> *decoded_bin;
    };
}

#endif // DECODER_HPP