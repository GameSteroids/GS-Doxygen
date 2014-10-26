
//!  Namespace with graphic functions and structures
namespace Graphics {

    //int FPUGetPrecision();
    //bool FPUGetPrecision(int iPrecision);
    //void SetProfilerMode(int iMode);
    double GetProfilerFPS();
    /**
     *  @brief Color object, used in Draw functions
     *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172721(v=vs.85).aspx
     */
    class Color {
        public:
            /// Default constructor
            Color();
            /// Copy constructor
            Color(Color &v);
            /**
             *  @brief Creates Color Object
             *  @param a alpha: .0f-1.0f
             *  @param r red: .0f-1.0f
             *  @param g green: .0f-1.0f
             *  @param b blue: .0f-1.0f
             */
            Color(float a, float r, float g, float b);
            /**
             *  @brief Creates Color Object
             *  @param argb color value 0 - 0xFFFFFFFF
             */
            Color(DWORD argb);
            /// + operator
            Color operator +(Color c);
            /// - operator.
            Color operator -(Color c);
            /// * operator.
            Color operator *(Color c);
            /// * operator.
            Color operator *(float s);
            /// == operator.
            bool operator ==(Color c);
            /// alpha value .0f - 1.0f
            float a;
            /// red value .0f - 1.0f
            float r;
            /// green value .0f - 1.0f
            float g;
            /// blue value .0f - 1.0f
            float b;
            /**
             * @brief Color as Number
             * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172721(v=vs.85).aspx
             */
            DWORD ToNumber();
            /**
             * @brief Adjusts the contrast value of a color.
             * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172723(v=vs.85).aspx
             */
            Color AdjustContrast(float s);
            /**
             * @brief Adjusts the saturation value of a color.
             * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172724(v=vs.85).aspx
             */
            Color AdjustSaturation(float s);
            /**
             *  @brief Uses linear interpolation to create a color value.
             *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172725(v=vs.85).aspx
             */
            Color Lerp(Color C, float s);
            /**
             *  @brief Blends two colors.
             *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172726(v=vs.85).aspx
             */
            Color Modulate(Color C);
            /**
             *  @brief Creates the negative color value of a color value.
             *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172727(v=vs.85).aspx
             */
            Color Negative();
            /**
             *  @brief Scales a color value.
             *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172728(v=vs.85).aspx
             */
            Color Scale(float s);
            
            /**
             *  each color channel seperate
             *  @return the color values
             */
            a r g b unpack();
    };
    
    //!  Class used by BoL Sprites
    class Sprite {
        public:
            /// Sets the sprite drawing scale
            void SetScale(float xScale, float yScale);
            /// Draws the sprite
            void Draw(int x, int y);
            /// Draws the sprite
            void DrawEx(int x, int y, int idk);
            /// Releases the sprite resources.
            void Release();
            /// returns the sprite width.
            int width;
            /// returns the sprite height.
            int height;
    };
    ///Creates a color from red, green, blue and alpha
    Color RGBA(int r, int g, int b, int a);
    ///Creates a color from alpha, red, green and blue
    Color ARGB(int a, int r, int g, int b);
    ///Creates a color from red, green and blue
    Color RGB(int r, int g, int b);
    /**
    * Draws text to the screen.
    * @see DrawTextEx()
    * @param text string to be drawn.
    * @param fontSize size of the font.
    * @param x x position.
    * @param y y position.
    * @param color text color.
    */
    void DrawText(string text, int fontSize, float x, float y, int color);
    /// Draws a circle to the game screen
    void DrawCircle();
    /// Draws a line to the screen
    void DrawLine();
    /// Draws lines to the screen
    void DrawLines();
    /*
    /// Draws an arrow to the game screen
    void DrawArrow();
    ///  Draws a rectangle to the screen
    void DrawRectangle();
    
    /// creates a sprite
    float CreateSprite(string szPath);


    /// Returns the game latency
    Vector3 WorldToScreen();
    /// Returns the game latency
    Vector3 UnitToScreen();
    */
}