#pragma once
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




//!  Namespace with MenuConfig Functions
namespace MenuConfig {
    /// Initiates the Menu. Id is optional
    __init(string Id, string Name);
    /// Create a Sub-Menu in your Menu
    Menu(string Id,string Name);
    /// Create a Boolean-Field in your Menu. DefaultValue, callback and ForceDefault are optional
    Boolean(string Id, string Name, bool DefaultValue, function callback, bool ForceDefault);
    /// Create a Number-Field in your Menu. DefaultValue, MinValue, MaxValue, callback and ForceDefault are optional
    Number(string Id, string Name, int DefaultValue, int MinValue, int MaxValue, function callback,bool ForceDefault);
    /// Create a Separator-Field in your Menu
    Separator();
    /// Create a Section-Field in your Menu
    Section(string Id,string Name);
    /// Create a KeyBinding-Field in your Menu. callback and ForceDefault are optional
    KeyBinding(string Id,string Name,string Key,function callback,bool ForceDefault);
    /// Create a DropDown-Field in your Menu. callback and ForceDefault are optional
    DropDown(string Id,string Name,int DefaultValue,table DropTable,function callback,bool ForceDefault);
    /// Create a Slider-Field in your Menu. DefaultValue, MinValue, MaxValue, Step, callback and ForceDefault are optional
    Slider(string Id,string Name,int DefaultValue,int MinValue,int MaxValue,int Step,function callback,bool ForceDefault);
    /// Create a ColorPick-Field in your Menu. DefaultValue, callback and ForceDefault are optional
    ColorPick(string Id,string Name,string DefaultValue,function callback,bool ForceDefault);
    /// Create a Button-Field in your Menu. callback is optional
    Button(string Id,string Name,function callback);
    /// Create a Info-Field in your Menu
    Info(string Id,string Name);
    /// Create a TargetSelector in your Menu. Mode, Range, DmgType, FocusSelected and OwnTeam are optional.
    TargetSelector(string Id,string Name,int Mode,int Range,string DmgType,bool FocusSelected,bool OwnTeam);



    namespace Boolean {
        /// Sets the State of the Boolean. If NewValue is empty, it will return the current State
        bool Value(bool NewValue);
        /// Sets the Name of the Boolean. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Boolean. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Creates a Note, that will be show when u hover your Mouse over the Boolean. If NewNote is empty, it will return the current Note
        string Note(string NewNote);
    },

    namespace Number {
        /// Sets the Value of the Number. If NewValue is empty, it will return the current State
        int Value(int NewValue);
        /// Sets the Name of the Number. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Number. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Creates a Note, that will be show when u hover your Mouse over the Number. If NewNote is empty, it will return the current Note
        string Note(string NewNote);
    },

    namespace Section {
        /// Sets the Name of the Section. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Section. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
    },

    namespace KeyBinding {
        /// Sets the Key of the KeyBinding. If NewValue is empty, it will return the current Key
        string Value(string NewValue);
        /// Sets the Name of the KeyBinding. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the KeyBinding. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Creates a Note, that will be show when u hover your Mouse over the KeyBinding. If NewNote is empty, it will return the current Note
        string Note(string NewNote);
        /// Returns if the current Key is Pressed or not
        bool IsPressed();
        /// Sets the State of the KeyBinding into ToggleMode(=true) or HoldMode(=false)
        void Toggle(bool NewState);
    },

    namespace DropDown {
        /// Sets the Value of the DropDown. If NewValue is empty, it will return the current Value
        int Value(int NewValue);
        /// Sets the Name of the DropDown. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the DropDown. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
    },

    namespace Slider {
        /// Sets the Value of the Slider. If NewValue is empty, it will return the current Value
        int Value(int NewValue);
        /// Sets the Name of the Slider. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Slider. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
    },

    namespace Info {
        /// Sets the Value of the Info. If NewValue is empty, it will return the current Value
        int Value(int NewValue);
        /// Sets the Name of the Info. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Info. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Changes the Icon. If NewIcon is empty, it will return the current Icon
        string Icon(string NewIcon)
    },

    namespace Button {
        /// Sets the Value of the Button. If NewValue is empty, it will return the current Value
        int Value(int NewValue);
        /// Sets the Name of the Button. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Button. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Changes the Icon. If NewIcon is empty, it will return the current Icon
        string Icon(string NewIcon)
    },

    namespace ColorPick {
        /// Sets the Name of the DropDown. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the DropDown. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Returns the Color in Hex
        string Value();
        /// Returns the Color as Color
        Color Color();
        /// Returns the Color as Int
        int Int();
    },

    namespace TargetSelector {
        /// Sets the Name of the Info. If NewName is empty, it will return the current Name
        string Name(string NewName);
        /// Hides of Shows the Info. If HideStatus is empty, it will return the current State
        bool Hide(bool HideStatus);
        /// Returns the Current Target
        unit GetTarget(int CustomRange, function Condition)
        /// Changes the Icon. If NewIcon is empty, it will return the current Icon
        string Icon(string NewIcon)
    }

}