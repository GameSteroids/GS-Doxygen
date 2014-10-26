
//!  Namespace with memory functions
namespace Memory {
    ///Class to read and write from memory
    class MemoryBuffer {
        public:
            ///Constructor, takes virtual address and length
            MemoryBuffer(int address, int nLen);
            ///Reads a 1byte unsigned integer and increases position by 1
            BYTE Read();
            ///Reads a 1byte signed integer and increases position by 1
            char ReadChar();
            ///@see Read()
            BYTE ReadByte();
            ///Reads a 2byte signed integer and increases position by 2
            short ReadShort();
            ///Reads a 2byte unsigned integer and increases position by 2
            WORD ReadWord();
            ///Reads a 4byte signed integer and increases position by 4
            int ReadInt();
            ///Reads a 4byte unsigned integer and increases position by 4
            UINT ReadUInt();
            ///Reads a null terminated ASCII string and increases position by the size
            string ReadString();
            ///Writes a 1 byte unsigned integer and increases position by 1
            void Write(BYTE value);
            ///Writes a 1 byte signed integer and increases position by 1
            void WriteChar(char value);
            ///@see Write(BYTE value)
            void WriteByte(BYTE value);
            ///Writes a 2 byte signed integer and increases position by 2
            void WriteShort(short value);
            ///Writes a 2 byte unsigned integer and increases position by 2
            void WriteWord(WORD value);
            ///Writes a 4 byte signed integer and increases position by 4
            void WriteInt(int value);
            ///Writes a 4 byte unsigned integer and increases position by 4
            void WriteUInt(UINT value);
            ///Writes a null terminated string and increases position by the size
            void WriteString(string value);
    };
    /**
    * Reads a 32bit integer from memory.
    * @see WriteDword(int address,int value)
    * @param address Address in memory.
    * @return Integer(4bytes) read from virtual address.
    */
    int ReadDword(int address);
    /**
    * Writes a 32 bit integer to memory.
    * @see ReadDword(int address)
    * @param address Address in memory.
    * @param value Value to be written.
    */
    void WriteDword(int address, int value);
    /**
    * Reads a 16bit integer from memory.
    * @see WriteWord(int address,int value)
    * @param address Address in memory.
    * @return Integer(2bytes) read from virtual address.
    */
    int ReadWord(int address);
    /**
    * Writes a 16 bit integer to memory.
    * @see ReadWord(int address)
    * @param address Address in memory.
    * @param value Value to be written.
    */
    void WriteWord(int address, int value);
    /**
    * Reads a 32bit floating point from memory.
    * @see WriteFloat(int address,int value)
    * @param address Address in memory.
    * @return float read from virtual address.
    */
    double ReadFloat(int address);
    /**
    * Writes a 32bit floating point to memory.
    * @see ReadFloat(int address)
    * @param address Address in memory.
    * @param value Value to be written.
    */
    void WriteFloat(int address, double value);
    /**
    * Reads a 8bit integer from memory.
    * @see WriteByte(int address,int value)
    * @param address Address in memory.
    * @return Integer read from virtual address.
    */
    int ReadByte(int address);
    /**
    * Writes a 8bit integer to memory.
    * @see ReadByte(int address)
    * @param address Address in memory.
    * @param value Value to be written.
    */
    void WriteByte(int address, int value);
}