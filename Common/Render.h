
//!  Namespace with rendering functions and structures
namespace Render {
    //!  Class used by font objects
    class Font {
        public:
            Font(string fontName, int dwSize);
    };

    //!  Generic class used by render objects
    class Object {
        public:
            bool bHide;
            bool Show();
            bool Hide();
    };

    //!  Class used by the render manager
    class Manager {
        public:
            void Add(Object obj);
    };
    //!  Class used by text render objects
    class Text : public Object {
        public:
            Text(string fontName);
            Text(string fontName, DWORD dwSize);
            Text(string fontName, DWORD dwSize, DWORD x, DWORD y);
            Text(string fontName, DWORD dwSize, DWORD x, DWORD y, Font font);
            void Draw();
            Vector2 GetTextArea();
            string text;
            int argb;
            Vector2 pos;
            Font font;
    };
    //!  Class used by rectangle render objects
    class Rect : public Object {
        public:
            Rect(float x, float y, float width, float height);
            Rect(float x, float y, float width, float height, int color);
            void Draw();
            Vector4 rc;
            int color1;
            int color2;
    };
    //!  Class used by game circle render objects
    class GameCircle : public Object {
        public:
            GameCircle(LoL.Unit unit, float fRange, int color);
            GameCircle(float x, float y, float z, float fRange, int color);
            void Draw();
            Unit unit;
            Vector3 pos;
            float radius;
            int color;
    };
    //!  Class used by sprite render objects
    class Sprite : public Object {
        public:
            Sprite(string path, int x, int y);
            void Draw();
            void DrawEx(D3DRECT srcRect, Vector3 pCenter, Vector3 pPosition);
            void SetScale(float xScale, float yScale);
            string path;
            Vector2 pos;

    };
    //!  Class used by circle render objects
    class Circle : public Object {
        public:
            Circle(float x, float y, float z, int minRadius, int maxRadius, int innerColor, int outerColor);
            Circle(float x, float y, int minRadius, int maxRadius, int innerColor, int outerColor);
            Circle(float x, float y, int radius, int color);
            void Draw();
            void SetPosition(float x, float y, float z);
            void SetPosition(float x, float y);
            void SetColor(int InnerColor);
            void SetColor(int InnerColor, int OuterColor);
            void SetRadius(int radius);
            void SetRadius(int minRadius, int maxRadius);
            //Unit unit;
            //Vector3 pos;
            //float radius;
            //int color;
    };
    //! Class used to render lines
    class Line : public Object {
        public:
            Line(Vector2 start, Vector2 end, float width, number Color);
            Line(Vector3 start, Vector3 end, float width, number Color);
            Vector2 from;
            Vector2 to;
            float width;
            number color;
    };
}
