// 6502 CPU Emulator

    
    using Byte = unsigned char; // 8 bits
    using Word = unsigned short; // 16 bits
    using u32 = unsigned int; // 32 bits
struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64; // 64KB
    Byte Data[MAX_MEM]; // 64KB of memory

    void Initialize()
    {
        for (u32 i = 0; i < MAX_MEM; i++)
        {
            Data[i] = 0;
        }
    }

};
struct CPU
{
    Word PC; // Program Counter
    Word SP; // Stack Pointer

    Byte A, X, Y; // Registers (A = Accumulator, X = Index, Y = Index)

    Byte C : 1; // Status Flags C = Carry
    Byte Z : 1; // Z = Zero
    Byte I : 1; // I = Interrupt Disable
    Byte D : 1; // D = Decimal Mode (unused in NES)
    Byte B : 1; // B = Break Command
    Byte V : 1; // V = Overflow
    Byte N : 1; // N = Negative

    // Reset the CPU to a known state
    void reset( Mem& memory)
    {
        PC = 0xFFFC; // Program starts at 0xFFFC
        SP = 0x0100; // Stack starts at 0x0100 and grows downwards
        C = Z = I = D = B = V = N = 0; // Clear all status flags
        A = X = Y = 0; // Clear all registers
        memory.Initialize();
    }

};

int main()
{
    Mem mem;
    CPU cpu;
    cpu.reset(mem);
    return 0;
}