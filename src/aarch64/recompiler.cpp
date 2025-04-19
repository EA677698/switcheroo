#include "../../include/switcheroo/aarch64/recompiler.hpp"

void recompiler::Recompiler::load_bin_code(const uint8_t* bin, size_t size)
{
    this->src_bin = bin;
    this->src_bin_size = size;

    if (size == 0) // If size is not provided, calculate it ourselves
    {
        this->src_bin_size = sizeof(bin) / sizeof(bin[0]);
    }
}