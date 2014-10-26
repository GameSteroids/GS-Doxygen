
//!  Namespace with Windows OS functions
namespace Windows {
    //!  Namespace with utility functions
    namespace Clipboard {
        /// Sets the clipboard text
        void SetText(string szText);
        /// Returns the clipboard text
        string GetText();
    }
    /// The window position
    Vector3 GetWindowPos();
    /// The cursor position in the window client area
    Vector3 GetCursorPos();
}
//!  Namespace with Keyboard functions
namespace Keyboard {
    /**
    * @brief Converts ascii key to key code
    * @return key code
    */
    BYTE GetKey(string szKey);
    /**
    * @brief Gets the ascii corespondent of a key value
    * @return ascii char
    */
    string ToAscii(int ch);
    /**
    * @brief Returns if the key is down
    * @return is key down status
    * @see IsKeyPressed(BYTE bKey)
    */
    bool IsKeyDown(BYTE bKey);
    /**
    * @brief Returns if the key is pressed
    * @return is key pressed status
    * @see IsKeyDown(BYTE bKey)
    */
    bool IsKeyPressed(BYTE bKey);
}

//!  Namespace with general utility functions
namespace Utility {
    /**
     *  @brief returns a table that is saved on exit and loaded on start.
     *  It has the following preset functions:
     *  @code 
     *  save = GetSave("MySave")
     *  save:Save() --saves it manually
     *  save:Reload() --reloading from file
     *  save:Remove() --deletes the file (still getting saved afterwards if not cleared)
     *  save:Clear() --clears the table
     *  save:IsEmpty() --returns true if it has no content
     *  @endcode
     */
    table GetSave(string name);
    ///Checks if a file exists on the file system
    bool FileExists(std::string sPath);
    /**
    * @brief Reads a file text content.
    * @see SaveFile(string encodedString)
    * @param sPath path to file.
    * @return string with file text content.
    */
    string ReadFile(string sPath);
    /**
    * @brief Saves text to file.
    * @see ReadFile(string sPath)
    * @param sPath path to file.
    * @param text text to write.
    */
    void WriteFile(string szPath, string text);
    /**
    * @brief Reads a file binary.
    * @see SaveFile(string encodedString)
    * @param sPath path to file.
    * @return Memory buffer of file binary
    */
    Memory::MemoryBuffer ReadBinary(string sPath);
    /**
    * @brief Saves a memory buffer to file.
    * @see ReadFile(string sPath)
    * @param sPath path to file.
    * @param buffer buffer to write.
    */
    void WriteBinary(string szPath, Memory.MemoryBuffer buffer);
    namespace Base64 {
        /**
        * @brief Encodes a string to base64.
        * @see Base64Decode(string encodedString)
        * @param rawString string to be encoded.
        * @return Base64 result
        */
        string Encode(string rawString);
        /**
        * @brief Decodes a base64 string.
        * @see Base64Encode(string rawString)
        * @param encodedString String to be decoded.
        * @return Decoded base64 result
        */
        string Decode(string encodedString);
    }
}
