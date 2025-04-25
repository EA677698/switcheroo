#ifndef INSTRUCTION_TYPE_HPP
#define INSTRUCTION_TYPE_HPP

namespace switcheroo::aarch64
{
    enum class InstructionType
    {

        INVALID,
        EXTENDED_REGISTER,
        SHIFTED_REGISTER,
        REGISTER,
        IMMEDIATE,
        LITERAL,
        BITMASK_IMMEDIATE,
        INVERTED_WIDE_IMMEDIATE,
        TO_FROM_SP,
        WIDE_IMMEDIATE,
        // Unsure about these. Will keep them for now
        EXCEPTION_LEVEL_SYSTEM,
        PC_RELATIVE_LITERAL,
        CONDITION_CODE,
        COMPOUND_OPERAND,
        LOAD_STORE_PAIR,
        ATOMIC,
        VECTOR_SCALAR

    };
}

#endif // INSTRUCTION_TYPE_HPP