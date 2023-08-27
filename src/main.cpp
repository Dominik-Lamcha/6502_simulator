// 6502 CPU Emulator
struct CPU
{
    
    using Byte = unsigned char; // 8 bits
    using Word = unsigned short; // 16 bits

    Word PC; // Program Counter
    Word SP; // Stack Pointer

    Byte A, X, Y; // Registers

    Byte C : 1; // Status Flags
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

    // Reset the CPU to a known state
    void reset()
    {
        PC = 0xFFFC; // Program starts at 0xFFFC
        SP = 0x0100; // Stack starts at 0x0100 and grows downwards
        C = Z = I = D = B = V = N = 0; // Clear all status flags
        A = X = Y = 0; // Clear all registers
    }

};

int main()
{
    CPU cpu;
    cpu.reset();
    return 0;
}