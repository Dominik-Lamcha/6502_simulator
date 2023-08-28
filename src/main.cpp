// 6502 CPU Emulator
#include <cstdio>

using Byte = unsigned char; // 8 bits
    using Word = unsigned short; // 16 bits
    using u32 = unsigned int; // 32 bits
struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64; // 64KB
    Byte Data[MAX_MEM]; // 64KB of memory

    // read 1 byte
    Byte operator[](u32 address) const
    {
        // assert here if address is larger than MAX_MEM
        return Data[address];
    }
    // write 1 byte
    Byte& operator[](u32 address)
    {
        // assert here if address is larger than MAX_MEM
        return Data[address];
    }

    void initialize()
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
    void reset(Mem& memory)
    {
        PC = 0xFFFC; // Program starts at 0xFFFC
        SP = 0x0100; // Stack starts at 0x0100 and grows downwards
        C = Z = I = D = B = V = N = 0; // Clear all status flags
        A = X = Y = 0; // Clear all registers
        memory.initialize();
    }

    Byte fetchByte(u32 Cycles, Mem& memory)
    {
        Byte data = memory[PC];
        PC++;
        Cycles--;
        return data;
    }
    // Opcodes
    static constexpr Byte 
        INS_LDA_IM = 0xA9;

    void execute(u32 Cycles, Mem& memory)
    {
        while (Cycles > 0)
        {
            Byte ins = fetchByte(Cycles, memory);
            switch (ins)
            {
            case INS_LDA_IM: // LDA Immediate - Load accumulator with value in next byte 
            {
                Byte Value = fetchByte(Cycles, memory);
                A = Value;                // Load value into accumulator
                Z = (A == 0);             // Set Z flag if A = 0
                N = (A & 0b10000000) > 0; // Set N flag if bit 7 is set
            } break;
            default:
            {
                printf("Instruction not handled %d", ins);
            } break;
            }
        }

    }

};

int main()
{
    Mem mem;
    CPU cpu;
    cpu.reset(mem);
    // Write some test code to memory
    mem[0xFFFC] = CPU::INS_LDA_IM;
    mem[0xFFFD] = 0x42; // LDA 0x42
    //
    cpu.execute(2,mem);
    //Print values of changed mem
    printf("A = %d\n", cpu.A);
    printf("Z = %d\n", cpu.Z);
    printf("N = %d\n", cpu.N);

    return 0;
}