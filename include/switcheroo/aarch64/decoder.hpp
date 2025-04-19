#ifndef DECODER_HPP
#define DECODER_HPP

#include <cstdint>
#include <vector>
#include "instruction.hpp"

class Decoder
{

    public:

        Decoder();
         ~Decoder() = default;

        void decode_bin(const uint8_t* bin, size_t size);

        std::vector<InstructionInfo>* get_instructions() const;

        private:

        void split_instructions(const uint8_t* bin, size_t size);

        void decode_main_group(const uint32_t instruction);

        size_t pc; // Program Counter
        std::vector<InstructionInfo>* decoded_bin;

};

#endif // DECODER_HPP