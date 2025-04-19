
header_file = None

def create_header(enum_class_name: str):
    global header_file
    header_file = open("instruction_enums.hpp", "w")
    header_file.write("#ifndef INSTRUCTION_ENUMS_HPP\n")
    header_file.write("#define INSTRUCTION_ENUMS_HPP\n")
    header_file.write("\n")
    header_file.write("enum class " + enum_class_name + " {\n")
    header_file.write("    INVALID")


def close_header():
    global header_file
    header_file.write("\n};\n")
    header_file.write("#endif // INSTRUCTION_ENUMS_HPP\n")
    header_file.close()

def add_instructions(instructions: dict):
    global header_file
    SPACES = 15
    prev_modes = ""
    prev_len = 0
    line = ""
    for instruction in instructions:
        line += ","
        if prev_modes != "":
            line += (" " * (SPACES - prev_len)) + " // " + prev_modes
        line += "\n    " + instruction
        prev_modes = instructions[instruction]
        prev_len = len(instruction)
    if prev_modes != "":
            line += (" " * (SPACES - prev_len)) + " // " + prev_modes
    header_file.write(line)

def extract_instructions(filename: str):
    with open(filename, 'r') as file:
        lines = file.readlines()
        instructions = {}
        for line in lines:
            if line.startswith("    <div class=\"iformindex\"><p class=\"iformindex\"><span class=\"insnheading\"><a href=\""):
                index = line.find("html\">") + len("html\">")
                if index == -1:
                    continue
                end_index = line.find("</a>")
                instruction_name = line[index:end_index]
                instruction_name = instruction_name.replace(" ", "")
                if "," in instruction_name:
                    instruction_name = instruction_name[0:instruction_name.index(",")]
                instruction_name = instruction_name.replace(".", "_")
                if "&lt;cc&gt;" in instruction_name:
                    instruction_name = instruction_name.replace("&lt;cc&gt;", "_cc")
                modes = ""
                if "(immediate)" in instruction_name:
                    instruction_name = instruction_name.replace("(immediate)", "")
                    modes += "I,"
                if "(register)" in instruction_name:
                    instruction_name = instruction_name.replace("(register)", "")
                    modes += "R,"
                if "(shiftedregister)" in instruction_name:
                    instruction_name = instruction_name.replace("(shiftedregister)", "")
                    modes += "SR,"
                if "(extendedregister)" in instruction_name:
                    instruction_name = instruction_name.replace("(extendedregister)", "")
                    modes += "ER,"
                if "(literal)" in instruction_name:
                    instruction_name = instruction_name.replace("(literal)", "")
                    modes += "L,"
                if "(bitmaskimmediate)" in instruction_name:
                    instruction_name = instruction_name.replace("(bitmaskimmediate)", "")
                    modes += "BMI,"
                if "(invertedwideimmediate)" in instruction_name:
                    instruction_name = instruction_name.replace("(invertedwideimmediate)", "")
                    modes += "IWI,"
                if "(to/fromSP)" in instruction_name:
                    instruction_name = instruction_name.replace("(to/fromSP)", "")
                    modes += "SP,"
                if "(wideimmediate)" in instruction_name:
                    instruction_name = instruction_name.replace("(wideimmediate)", "")
                    modes += "WI,"
                if instruction_name in instructions.keys():
                    instructions[instruction_name] += ", " + modes[0:len(modes) - 1]
                else:
                    instructions[instruction_name] = modes[0:len(modes) - 1]
        add_instructions(instructions)


create_header("A64Instruction")
extract_instructions("A64.htm")
close_header()