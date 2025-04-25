#ifndef RECOMPILER_HPP
#define RECOMPILER_HPP

#include <cstdint>
#include <vector>
#include "instruction.hpp"

namespace recompiler
{

    class Recompiler
    {

    public:

        Recompiler() = default;
        ~Recompiler() = default;

        void load_bin_code(const uint8_t* bin, size_t size = 0);

        std::vector<uint8_t> compile();

    private:
        
        const uint8_t* src_bin = nullptr;
        size_t src_bin_size = 0;
        std::vector<switcheroo::aarch64::Instruction>* decoded_bin;


    };

}

#endif // RECOMPILER_HPP