//!  Global namespace with functions, shared by all environments
namespace Global {
    /**
        *  @brief Operating System Facilities
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-os
        *  @note This library is implemented through table os.
     */
    class os {
    public:
        /**
            *  @brief Opens the shell and executes a command
            *  @code os.execute("ping 1.1.1.1 /n 1 /w 100 >nul") @endcode
         */
        bool execute(string command = nil);
        
        /// renames a file / directory
        string, error rename(string oldname, string newname);
        
        /// terminates the process
        bool exit(int code = true, bool close = true);
        /// Returns the value of the process environment variable varname, or nil if the variable is not defined.
        string getenv(string varname);
        /// @see http://www.lua.org/manual/5.2/manual.html#pdf-os.date
        string date(string format, double time);
        /// Deletes the file (or empty directory, on POSIX systems) with the given name. If this function fails, it returns nil, plus a string describing the error and the error code.
        string, error remove(string filename);
        /// returns t2 - t1
        double difftime(double t2, double t1);
        /**
            *  @brief Sets the current locale of the program.
            *  @see http://www.lua.org/manual/5.2/manual.html#pdf-os.setlocale
        */
        string setlocale (string locale , category = "");
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-os.time
        double time(table t);
        /**
            *  @brief Returns an approximation of the amount in seconds of CPU time used by the program.
            *  clock() / CLOCKS_PER_SEC
            *  @see http://www.cplusplus.com/reference/ctime/clock/
        */
        double clock();
        /**
            *  @brief Returns a string with a file name that can be used for a temporary file. 
            *  @see http://www.lua.org/manual/5.2/manual.html#pdf-os.tmpname
        */
        string tmpname();
    };
    /**
        *  @brief Bitwise operations
        *  @see http://bitop.luajit.org/api.html
     */
    class bit {
    public:
        /**
            *  @brief Returns the bitwise <b>not</b> of its argument.
            *  @code
            *  print(bit.bnot(0))            --> -1
            *  print(bit.bnot(-1))           --> 0
            *  print(bit.bnot(0xffffffff))   --> 0
            *  @endcode
         */
        int bnot(int x);
        
        /**
            *  @brief Arithmetic right shift
            *  @code
            *  print(bit.arshift(256, 8))           --> 1
            *  print(bit.arshift(-256, 8))          --> -1
            *  @endcode
         */
        int arshift(int x, int n);
        
        /**
            *  @brief Bitwise logical <b>left-shift</b>
            *  @code
            *  print(bit.lshift(1, 0))              --> 1
            *  print(bit.lshift(1, 8))              --> 256
            *  print(bit.lshift(1, 40))             --> 256
            *  @endcode
         */
        int lshift(int x, int n);
        
        /**
            *  @brief Bitwise logical <b>right-shift</b>
            *  @code
            *  print(bit.rshift(256, 8))            --> 1
            *  print(bit.rshift(-256, 8))           --> 16777215
            *  @endcode
         */
        int rshift(int x, int n);
        
        /**
            *  @brief Bitwise <b>or</b>
            *  @code
            *  print(bit.bor(1, 2, 4, 8))                --> 15
            *  @endcode
         */
        int bor(int x1, ...);
        
        /**
            *  @brief Bitwise <b>and</b>
            *  @code
            *  printx(bit.band(0x12345678, 0xff))        --> 0x00000078
            *  @endcode
         */
        int band(int x1, ...);
        
        /**
            *  @brief Bitwise <b>exclusive or (xor)</b>
            *  @code
            *  printx(bit.bxor(0xa5a5f0f0, 0xaa55ff00))  --> 0x0ff00ff0
            *  @endcode
         */
        int bxor(int x, ...);
        
        /**
            *  @brief Bitwise <b>swap</b>
            *  @code
            *  printx(bit.bswap(0x12345678)) --> 0x78563412
            *  printx(bit.bswap(0x78563412)) --> 0x12345678
            *  @endcode
            *  @note This can be used to convert little-endian 32 bit numbers to big-endian 32 bit numbers or vice versa.
         */
        int bswap(int x);
        
        /**
            *  @brief Bitwise <b>left rotation</b>
            *  @code
            *  printx(bit.rol(0x12345678, 12))   --> 0x45678123
            *  @endcode
         */
        int rol(int x, int n);
        
        /**
            *  @brief Bitwise <b>right rotation</b>
            *  @code
            *  printx(bit.ror(0x12345678, 12))   --> 0x67812345
            *  @endcode
         */
        int ror(int x, int n);
        
        /**
            *  @brief Bit string
            *  @code
            *  print(0xffffffff)                --> 4294967295 (*)
            *  print(bit.tobit(0xffffffff))     --> -1
            *  printx(bit.tobit(0xffffffff))    --> 0xffffffff
            *  print(bit.tobit(0xffffffff + 1)) --> 0
            *  print(bit.tobit(2^40 + 1234))    --> 1234
            *  @endcode
            *  @note Normalizes a number to the numeric range for bit operations and returns it. This function is usually not needed since all bit operations already normalize all of their input arguments.
         */
        string tobit(int x);
        
        /**
            *  @brief Hex string
            *  @code
            *  print(bit.tohex(1))              --> 00000001
            *  print(bit.tohex(-1))             --> ffffffff
            *  print(bit.tohex(0xffffffff))     --> ffffffff
            *  print(bit.tohex(-1, -8))         --> FFFFFFFF
            *  print(bit.tohex(0x21, 4))        --> 0021
            *  print(bit.tohex(0x87654321, 4))  --> 4321
            *  @endcode
            *  @note Converts its first argument to a hex string. The number of hex digits is given by the absolute value of the optional second argument. Positive numbers between 1 and 8 generate lowercase hex digits. Negative numbers generate uppercase hex digits. Only the least-significant 4*|n| bits are used. The default is to generate 8 lowercase hex digits.
         */
        string tohex(int x ,int n = nil);
    };
    
    /**
        *  @brief Table Manipulation
        *  @code
        *  local tbl = {
        *      Ezreal = { relationshipStatus = "In Love With Taric", prefers = "Men"  },
        *      Taric  = { relationshipStatus = "In Love With Gems",  perfers = "Gems" },
        *  }
        *  @endcode
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-table
        *  @note This library provides generic functions for table manipulation. It provides all its functions inside the table table.
        *  Remember that, whenever an operation needs the length of a table, the table should be a proper sequence or have a __len metamethod (see §3.4.6). All functions ignore non-numeric keys in tables given as arguments.
        *  For performance reasons, all table accesses (get/set) performed by these functions are raw.
     */
    class table {
    public:
        /**
            *  @brief Sorts list elements in a given order, in-place, from list[1] to list[#list].
            *  @param t The table with elements to be sorted in
            *  @param comparator (optional) If comp is given, then it must be a function that receives two list elements and returns true when the first element must come before the second in the final order (so that not comp(list[i+1],list[i]) will be true after the sort). If comp is not given, then the standard Lua operator < is used instead.
            *  @code
            *  local tbl = { {id = 5}, {id = 2}, {id = 4}, {id = 3}, {id = 1} }
            *  table.sort(tbl, function(a, b)
            *      return a.id > b.id
            *  end)
            *  @endcode
            *  @see http://www.lua.org/manual/5.2/manual.html#pdf-table.sort
            *  @note The sort algorithm is not stable; that is, elements considered equal by the given order may have their relative positions changed by the sort.
         */
        void sort(table t, function comparator = nil);
        
        /**
            *  @brief Checks if an element is inside the table
            *  @param t The table to search through
            *  @param obj The object to look for
            *  @param member (optional) the member to check in each object of the table
        */
        bool contains(table t, object obj, string member = nil);
        
        /**
            * @brief Creates a shallow / deep copy of the table
            * @param t The table to copy
            * @param deep Should be true if a deep copy is required, it will make copies of tables inside table t.
            * @return table The copy of the table
        */
        table copy(table t, bool deep = false);
        
        /**
            *  @brief Iterates a table.
            *  @see pairs
        */
        void foreach(table t,function f);
        
        /**
            *  @brief iterates a table.
            *  @see ipairs
        */
        void foreachi(table t,function f);
        
        /**
            *  @brief merges two tables shallow or deep, inserting and overwriting in the base table.
            *  @code
            *  local tbl1, tbl2 = { "aaa", "bbb" }, { "ccc", "ddd" }
            *  table.merge(tbl1, tbl2)
            *  
            *  for i, v in pairs(tbl1) do
            *      print(i .. ": " .. v)
            *  end
            *  
            *  -- Output:
            *  -- 1: aaa
            *  -- 2: bbb
            *  -- 3: ccc
            *  -- 4: ddd
            *  @endcode
        */
        void merge(table base, table t, bool deep = false);
        
        /**
            *  @brief protects a table. only read only operations are allowed afterwards.
            *  @note iterations won't work afterwards.
        */
        table protect(table t);
        
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-table.concat
        string concat(table t, string delimiter = nil, int i = nil, int j = nil);
        
        ///http://www.lua.org/manual/5.2/manual.html#pdf-table.remove
        /**
            *  @brief Removes an element from the table <b>t</b> and returns it.
            *  @param t The table you want to remove the element from.
            *  @param pos (optional) Index of the element you want to be removed.
            *  @return object The removed element.
            *  @code
            *  local tbl = { "aaa", "bbb", "ccc" }
            *  print(tbl[2])                    --> bbb
            *  print(table.remove(tbl, 2))      --> bbb
            *  print(tbl[2])                    --> ccc
            *  @endcode
         */
        object remove(table t, object pos = 1);
        
        ///@brief traverses all elements to find the highest integer index. O(n)
        int maxn(table t);
        
        ///@brief return the highest continuous array index beginning at index one. O(1)
        int getn(table t);
        
        ///@brief clears all elements from the table
        void clear(table t);
        
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-table.insert
        insert(table t, int pos = nil, object value);
    };
    
    /**
        *  @brief Mathematical Functions
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-math
        *  @note This library is an interface to the standard C math library. It provides all its functions inside the table math.
     */
    class math {
    public:
        ///Returns the smallest integer larger than or equal to val.
        double ceil(double val);
        ///Returns the largest integer smaller than or equal to x.
        double floor(double x);
        ///rounds the value to 10^b
        double round(double x, double b = 0);
        ///Returns the tangent of val (assumed to be in radians).
        double tan(double val);
        ///Returns the logarithm of val in 10.
        double log10(double val);
        ///Checks if val is not a number.
        bool isNaN(double val);
        ///Limits val between min and max.
        double limit(double val, double min, double max);
        ///Returns m*pow(2,e).
        double ldexp(double m, int e);
        ///Returns the angle x (given in radians) in degrees.
        double deg(double x);
        ///Returns the hyperbolic cosine of x.
        double cosh(double x);
        ///Returns the minimum value among its arguments.     
        double min(double x, ...);
        ///Returns m and e such that x = m*pow(2,e), the absolute value of m is in the range [0.5, 1) (or zero when x is zero).
        int double frexp(double x);
        ///Returns the value e^x.
        double exp(double x);
        
        /**
            *  @brief This function is an interface to the simple pseudo-random generator function rand provided by ANSI C. (No guarantees can be given for its statistical properties.)
            *  @param m (optional) When called with an integer number m, math.random returns a uniform pseudo-random integer in the range [1, m].
            *  @param n (optional) When called with two integer numbers m and n, math.random returns a uniform pseudo-random integer in the range [m, n].
            *  @code
            *  print(math.random() >= 0.9 and "rare" or "popular")
            *  @endcode
            *  @see http://www.lua.org/manual/5.1/manual.html#pdf-math.random
            *  @see randomseed
            *  @note For better "randomness" it's better to set custom seed with math::randomseed , for example the result of os::clock
         */
        double random(int m = 0,int n = 1);
        
        /**
            *  @brief Sets x as the "seed" for the pseudo-random generator: equal seeds produce equal sequences of numbers.
            *  @code
            *  math.randomseed(os.clock())
            *  local rnd = math.random(0,10)
            *  @endcode
            *  @see random
            *  @note For better "randomness" of math::random it's better to set custom seed with this function, for example the result of os::clock
         */
        void randomseed(double x);
        
        ///Returns the angle x (given in degrees) in radians.
        double rad(double x);
        /// Returns the sine of x (assumed to be in radians).
        double sin(double x);
        ///Returns the cosine of x (assumed to be in radians).
        double cos(double x);
        ///@see fmod
        double mod(double x);
        ///Returns the hyperbolic tangent of x.
        double tanh(double x);
        ///Returns the maximum value among its arguments.
        double max(double x, ...);
        ///Returns x^y. (You can also use the expression x^y to compute this value.)
        double pow(double x, double y);
        ///Returns the arc cosine of x (in radians).
        double acos(double x);
        ///Returns the hyperbolic sine of x.
        double sinh(double x);
        ///Returns the absolute value of x.
        double abs(double x);
        ///The value of pi.
        const double pi;
        ///Returns the natural logarithm of x.
        double log(double x);
        ///Returns the remainder of the division of x by y that rounds the quotient towards zero.
        double fmod(double x, double y);
        ///Returns the arc tangent of y/x (in radians), but uses the signs of both parameters to find the quadrant of the result. (It also handles correctly the case of x being zero.)
        double atan2(double x, double y);
        ///Returns the arc sine of x (in radians).
        double asin(double x);
        ///Returns two numbers, the integral part of x and the fractional part of x.
        double modf(double x);
        ///Returns the arc tangent of x (in radians).
        double atan(double x);
        ///The value HUGE_VAL, a value larger than or equal to any other numerical value.
        const double huge;
        ///Returns the square root of x. (You can also use the expression x^0.5 to compute this value.)
        double sqrt(double x);
    };
    /**
        *  @brief Input and Output Facilities
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-io
        *  @note The I/O library provides two different styles for file manipulation. The first one uses implicit file descriptors; that is, there are operations to set a default input file and a default output file, and all input/output operations are over these default files. The second style uses explicit file descriptors.
        *  When using implicit file descriptors, all operations are supplied by table io. When using explicit file descriptors, the operation io.open returns a file descriptor and then all operations are supplied as methods of the file descriptor.
        *  The table io also provides three predefined file descriptors with their usual meanings from C: io.stdin, io.stdout, and io.stderr. The I/O library never closes these files.
        *  Unless otherwise stated, all I/O functions return nil on failure (plus an error message as a second result and a system-dependent error code as a third result) and some value different from nil on success. On non-Posix systems, the computation of the error message and error code in case of errors may be not thread safe, because they rely on the global C variable errno.
     */
    class io {
    public:
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.input
        void input(file file = nil);
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.stdin
        file stdin();
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.tmpfile
        file tmpfile();
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.read
        string read(...);
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.close
        void close(file h = nil);
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.write
        file err write(string fileName, string mode = "r");
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.popen
        file popen(string prog, string mode = "r");
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.type
        string type(file h);
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.flush
        void flush();
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.lines
        string_iterator lines(string filename... = nil);
        ///see http://www.lua.org/manual/5.2/manual.html#pdf-io.stdout
        file stdout();
        ///@see http://www.lua.org/manual/5.2/manual.html#pdf-io.stderr
        file stderr();
    private:
        class file {
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:close
            void close();
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:flush
            void flush();
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:read
            string read(...);
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:lines
            string_iterator lines(string filename... = nil);
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:seek
            int seek(string whence = nil, int offset = nil);
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:setvbuf
            void setvbuf(string mode, int size = nil);
            ///@see http://www.lua.org/manual/5.2/manual.html#pdf-file:write
            file write(...);
        };
    };
    /**
         *  @brief String Manipulation.
         *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string
         *  @note This library provides generic functions for string manipulation, such as finding and extracting substrings, and pattern matching.
         *  When indexing a string in Lua, the first character is at position 1 (not at 0, as in C). Indices are allowed to be negative and are interpreted as indexing backwards, from the end of the string. Thus, the last character is at position -1, and so on.
         *  The string library provides all its functions inside the table string. It also sets a metatable for strings where the __index field points to the string table. Therefore, you can use the string functions in object-oriented style. For instance, string.byte(s,i) can be written as s:byte(i).
         *  The string library assumes one-byte character encodings.
     */
    class string {
    public:
        /**
             *  @brief Looks for the first match of pattern in the string s. If it finds a match, then find returns the indices of s where this occurrence starts and ends; otherwise, it returns nil. A third, optional numerical argument init specifies where to start the search; its default value is 1 and can be negative. A value of true as a fourth, optional argument plain turns off the pattern matching facilities, so the function does a plain "find substring" operation, with no characters in pattern being considered magic. Note that if plain is given, then init must be given as well.
             *  @see http://www.lua.org/manual/5.1/manual.html#pdf-string.find
             *  @note If the pattern has captures, then in a successful match the captured values are also returned, after the two indices.
         */
        int int string find(string s, string pattern, int init = 1, bool plain = false);
        
        /**
            *  @brief Receives a string and returns its length.
            *  @see http://www.lua.org/manual/5.1/manual.html#pdf-string.len
            *  @note The empty string "" has length 0. Embedded zeros are counted, so "a\000bc\000" has length 5.
         */
        int len(string s);
        
        /**
            *  @brief Looks for the first match of pattern in the string s. If it finds one, then match returns the captures from the pattern; otherwise it returns nil. If pattern specifies no captures, then the whole match is returned. A third, optional numerical argument init specifies where to start the search; its default value is 1 and can be negative.
            *  @see http://www.lua.org/manual/5.1/manual.html#pdf-string.match
         */
        int match(string s, string pattern, int init = 1);
        
        /**
             *  @brief Receives a string and returns a copy of this string with all lowercase letters changed to uppercase. All other characters are left unchanged. The definition of what a lowercase letter is depends on the current locale.
             *  @code
             *  print(string.upper("such TEST much WoW"))   --> SUCH TEST MUCH WOW
             *  
             *  local str = "such WoW omg"
             *  print(str:upper())                          --> SUCH WOW OMG
             *  @endcode
             *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string.upper
         */
        string upper(string s);
        
        /**
             *  @brief Receives a string and returns a copy of this string with all uppercase letters changed to lowercase. All other characters are left unchanged. The definition of what an uppercase letter is depends on the current locale.
             *  @code
             *  print(string.lower("such TEST much WoW"))   --> such test much wow
             *  
             *  local str = "such WoW omg"
             *  print(str:lower())                          --> such wow omg
             *  @endcode
             *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string.lower
         */
        string lower(string s);
        
        /**
            *  @brief Returns the substring of s that starts at i and continues until j; i and j can be negative. If j is absent, then it is assumed to be equal to -1 (which is the same as the string length). In particular, the call string.sub(s,1,j) returns a prefix of s with length j, and string.sub(s, -i) returns a suffix of s with length i.
            *  @see http://www.lua.org/manual/5.1/manual.html#pdf-string.sub
            *  @note If, after the translation of negative indices, i is less than 1, it is corrected to 1. If j is greater than the string length, it is corrected to that length. If, after these corrections, i is greater than j, the function returns the empty string.
         */
        string sub(string s, int i, int j = -1);
        
        ///@see http://www.lua.org/manual/5.1/manual.html#pdf-string.char
        int ... char(...);
        
        ///@see table.concat
        string join(table t, string delimiter);
        
        /**
             *  @brief Splits a string on a delimiter
             *  @code
             *  -- Example #1:
             *  local myString = "One|Two"
             *  print(string.split(myString, '|')[2])   --> Two
             *  @endcode
             *  @code
             *  -- Example #2:
             *  local preferencesString = "Ezreal=men|Taric=gems|Gragas=beer"
             *  local preferences = {}
             *  
             *  for i, s1 in pairs(preferencesString:split('|')) do
             *      local s2 = s1:split('=')
             *      preferences[s2[1]] = s2[2]
             *  end
             *  
             *  for hero, preference in pairs(preferences) do
             *      print(hero .. " loves " .. preference)
             *  end
             *  
             *  -- Output:
             *  -- Ezreal loves men
             *  -- Taric loves gems
             *  -- Gragas loves beer
             *  @endcode
         */
        table split(string s, string delimiter);
        
        /**
         *  @brief Returns a string that is the concatenation of n copies of the string s separated by the string sep. The default value for sep is the empty string (that is, no separator).
         */
        string rep(string s, int n);
        
        /**
             *  @brief Returns a copy of s in which all (or the first n, if given) occurrences of the pattern have been replaced by a replacement string specified by repl, which can be a string, a table, or a function. gsub also returns, as its second value, the total number of matches that occurred. The name gsub comes from Global SUBstitution.
             *  @code
             *  x = string.gsub("hello world", "(%w+)", "%1 %1")
             *  print(x)                                                                --> hello hello world world
             *  print(string.gsub("hello world", "%w+", "%0 %0", 1))                    --> hello hello world
             *  print(string.gsub("hello world from Lua", "(%w+)%s*(%w+)", "%2 %1"))    --> world hello Lua from
             *  print(string.gsub("home = $HOME, user = $USER", "%$(%w+)", os.getenv))  --> home = /home/roberto, user = roberto
             *  @endcode
             *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string.gsub
         */
        string gsub(string s, string pattern, object repl, int n);
        
        /**
             *  @brief Returns an iterator function that, each time it is called, returns the next captures from pattern over the string s. If pattern specifies no captures, then the whole match is produced in each call.
             *  @code
             *  -- As an example, the following loop will iterate over all the words from string s, printing one per line:
             *  s = "hello world from Lua"
             *  for w in string.gmatch(s, "%a+") do
             *      print(w)
             *  end
             *  
             *  -- The next example collects all pairs key=value from the given string into a table:
             *  t = {}
             *  s = "from=world, to=Lua"
             *  for k, v in string.gmatch(s, "(%w+)=(%w+)") do
             *      t[k] = v
             *  end
             *  @endcode
             *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string.gmatch
         */
        iterator gmatch(string s, string pattern);
        
        /**
             *  @brief Returns a string that is the string s reversed.
             *  @code
             *  local myString = "Awesome!"
             *  print(myString:reverse())   --> !emosewA
             *  @endcode
             *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string.reverse
         */
        string reverse(string s);
        
        /**
             *  @brief Returns the internal numerical codes of the characters s[i], s[i+1], ..., s[j]. The default value for i is 1; the default value for j is i. These indices are corrected following the same rules of function string.sub.
             *  @see http://www.lua.org/manual/5.5/manual.html#pdf-string.byte
             *  @note Numerical codes are not necessarily portable across platforms.
         */
        int byte(string s, int i = 1, int j = i);
        
        ///Removes white spaces of a string on front and back.
        void trim(string s);
        
        ///Replaces escape characters with the equivalent escape code.
        void unescape(string f);
        
        ///@see string.gmatch
        iterator gfind(string s, string pattern);
        
        /**
             *  @brief Returns a formatted version of its variable number of arguments following the description given in its first argument (which must be a string). The format string follows the same rules as the ANSI C function sprintf. The only differences are that the options/modifiers *, h, L, l, n, and p are not supported and that there is an extra option, q. The q option formats a string between double quotes, using escape sequences when necessary to ensure that it can safely be read back by the Lua interpreter.
             *  @code
             *  print(string.format('%q', 'a string with "quotes" and \n new line'))
             *  -- Output:
             *  -- a string with \"quotes\" and \
             *  -- new line
             *  @endcode
             *  @see http://www.lua.org/manual/5.2/manual.html#pdf-string.format
             *  @note Options A and a (when available), E, e, f, G, and g all expect a number as argument. Options c, d, i, o, u, X, and x also expect a number, but the range of that number may be limited by the underlying C implementation. For options o, u, X, and x, the number cannot be negative. Option q expects a string; option s expects a string without embedded zeros. If the argument to option s is not a string, it is converted to one following the same rules of tostring.
         */
        string format(string formatstring, ...);
    };
    ///@see http://www.lua.org/manual/5.2/manual.html#pdf-next
    object next(table t, object index);
    /**
        *  @brief Loads the given module. DLL's are blocked.
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-require
     */
    object require(string modname);
    /**
        *  @brief Sets the environment to be used by the given function.
        *  @see http://www.lua.org/manual/5.1/manual.html#pdf-setfenv
     */
    void setfenv(function f, table t);
    /**
        * @brief issues an error
        * @see http://www.lua.org/manual/5.2/manual.html#pdf-assert
    */
    bool assert(bool v, string message = nil);
    /**
        *  @brief throws an error
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-error
    */
    void error(string message, int level = 0);
    
    /**
        *  @brief registers the table as namespace in the global env
    */
    void namespace_(string name, table environment);
    
    /**
        *  @brief Tries to convert its argument to a number
        *  @code
        *  print(tonumber("1.5") + 3.5)     --> 5
        *  @endcode
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-tonumber
    */
    double tonumber(string e, double base);
    /**
        *  @brief Gets the real value of table[index], without invoking any metamethod.
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-rawget
    */
    object rawget(table t, object index);
    
    /**
        *  @brief Sets the real value of table[index] to value, without invoking any metamethod. 
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-rawset
    */
    table rawset(table, index, value);
    
    /**
        *  @brief Returns the iterator for a table, used in for loops.
        *  @code
        *  local tbl = { abc = 1, cde = 1+1, zzz = "3" }
        *  
        *  for key, val in pairs(tbl) do
        *      print(key .. ": " .. val)
        *  end
        *  
        *  -- Output:
        *  -- abc: 1
        *  -- cde: 2
        *  -- zzz: 3
        *  @endcode
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-pairs
    */
    iterator pairs(table t);
    
    /**
        *  @brief Returns the array iterator for a table, used in for loops.
        *  @code
        *  local tbl = { 1, 1+1, 3, "4", "five", ["sixth"] = 6 }
        *  
        *  for key, val in ipairs(tbl) do
        *      print(key .. ": " .. val)
        *  end
        *  
        *  -- Output:
        *  -- 1: 1
        *  -- 2: 2
        *  -- 3: 3
        *  -- 4: 4
        *  -- 5: five
        *  @endcode
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-ipairs
        *  @note Continuous array access beginning at index 1.
    */
    iterator ipairs(table t);
    
    /**
        *  @brief secure lua call
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-pcall
    */
    bool error pcall(function f, arg... = nil);
    
    /**
        *  @brief Imports environments / libraries.
        *  @code
        *      import { Geometry }
        *      local a = Vector2(0, 0)
        *  @endcode
    */
    void import(table env, ...);
    
    /**
        *  @brief returns the function signature. 
        *  @note this function may be removed or renamed in future releases.
    */
    string CopyFunction(function f);
    /**
        *  @brief returns the metatable of an object
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-getmetatable
    */
    table getmetatable(object obj);
    /**
        *  @brief Sets the metatable for the given table
        *  @see http://www.lua.org/manual/5.2/manual.html#pdf-setmetatable
    */
    table setmetatable(object obj, table metatable);
    ///luabind class info
    classinfo class_info(object obj);
    /**
         *  @brief Creates and registers a luabind class
         *  @see http://www.rasterbar.com/products/luabind/docs.html#defining-classes-in-lua
         *  @code
         *  class 'MyClass'     -- also can be used class("MyClass")
         *  function MyClass:__init(name, text)
         *      self.name = name
         *      self.text = text
         *      return self
         *  end
         *  function MyClass:print()
         *      print(self.name .. ": " .. self.text)
         *  end
         *  
         *  MyClass("Ezreal", "I <3 Taric"):print()
         *  local Taric = MyClass("Taric", "I <3 Gems")
         *  Taric:print()
         *  
         *  -- Output:
         *  -- Ezreal: I <3 Taric
         *  -- Taric: I <3 Gems
         *  @endcode
     **/
    void class_(string classname);
    /// Returns the object string interpretation
    string tostring(object obj);
    /// Returns the object type or class type for luabind classes
    string type(object obj);
    /// Prints a string to the debug console
    void print(string szPrint);
    ///@see http://www.lua.org/manual/5.2/manual.html#pdf-select
    object select(int index, ...);
    ///@see http://www.lua.org/manual/5.2/manual.html#pdf-unpack
    ... unpack(table list, int i, int j);
    ///@see http://www.lua.org/manual/5.1/manual.html#pdf-getfenv
    table getfenv(function f = nil);
    
    /**
        *  @brief Mouse position instance (position of the mouse in the game world).
     */
    Vector3 mousePos;
    
    /// Camera position Instance
    Vector3 cameraPos;
    
    /**
        *  @brief My Hero Instance.
        *  @code
        *  print("My champion's name is " .. player.charName)   --> My champion's name is Ezreal
        *  @endcode
     */
    Game::Unit player;
    
    /**
        *  @brief My Hero Instance.
        *  @code
        *  print("My champion's name is " .. myHero.charName)   --> My champion's name is Ezreal
        *  @endcode
     */
    Game::Unit myHero;
    
    /// Identifies the enemy team
    Game::Team TEAM_ENEMY;
}