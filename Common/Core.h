#pragma once
#include "Unit.h"

#undef RGB
#define KEY_DOWN WM_KEYDOWN
#define KEY_UP WM_KEYUP

//!  Class used by strings.
class string {
    public:
};
//!  Class used any lua object.
class object {
    public:

};
//! Integer type.
class int {
    public:

};
//! Boolean type.
class bool {
    public:

};
//! Float type.
class float {
    public:

};
//! Double type.
class double {
    public:

};
//!  No return type.
class void {
    public:

};
//!  String type.
class string {
    public:

};



//!  Namespace with core functions
namespace Core {
    ///@see http://msdn.microsoft.com/en-us/library/windows/desktop/ms724408(v=vs.85).aspx
    int GetTickCount();

    /// Returns Dll Build Date
    string GetBuildDate();
    /// Outputs a string to DbgView
    void OutputDebugString(string szOutput...);
    namespace Console {
        /**
        * Shows the debug console.
        * @see Hide(),SetConsolePos(int x,int y)
        */
        void Show();
        /**
        * Hides the debug console.
        * @see Show(),SetConsolePos(int x,int y)
        */
        void Hide();
        /**
        * Sets the console position.
        * @see ShowConsole()
        * @param x X Position.
        * @param y Y Position.
        */
        void SetPos(int x, int y);
        /**
         *  Gets the console position
         *  @returns the position of the console window
         */
        Vector2 GetPos();
    }
}