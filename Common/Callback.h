
//!  Namespace that handles callback bindings
namespace Callback {
    //!  Anonymous namespace with callback binding functions
    enum CallBacks {
        LOAD = "Load", ///< Load
        UNLOAD = "Unload", ///<Unload
        EXIT = "Exit", ///<Exit
        TICK = "Tick", ///<Tick
        DRAW = "Draw", ///<Draw
        RESET = "Reset", ///<Reset
        SEND_CHAT = "SendChat", ///<SendChat
        RECV_CHAT = "RecvChat", ///<RecvChat
        WND_MSG = "WndMsg", ///<WndMsg
        CREATE_OBJ = "CreateObj", ///<CreateObj
        DELETE_OBJ = "DeleteObj", ///<DeleteObj
        UPDATE_OBJ = "UpdateObj", ///<UpdateObj
        PROCESS_SPELL = "ProcessSpell", ///<ProcessSpell
        SEND_PACKET = "SendPacket", ///<SendPacket
        RECV_PACKET = "RecvPacket", ///<RecvPacket
        CRASH = "Crash", ///<BugSplat
        ANIMATION = "Animation", ///<Animation
        NOTIFY = "Notify", ///<Notify
        APPLY_PARTICLE = "ApplyParticle", ///<ApplyParticle
        CALLBACK_COUNT = 19, ///<19
    };

    //!  Class used by callback functions.
    class callbackFunction {
        public:
            /// Load
            void Load();
            /// Unload
            void Unload();
            /// Exit
            void Exit();
            /// Tick
            void Tick();
            /// Draw
            void Draw();
            /// Reset
            void Reset();
            /// SendChat
            void SendChat(string text);
            /// RecvChat
            void RecvChat(string from, string text);
            /// WndMsg
            void WndMsg(int iMsg, int wParam);
            /// CreateObj
            void CreateObj(Game.Unit obj);
            /// DeleteObj
            void DeleteObj(Game.Unit obj);
            /// ProcessSpell
            void ProcessSpell(Game.Unit from, Game.SpellData spell);
            /// Event called whenever a packet is send
            void SendPacket(Network.EnetPacket packet);
            /// Event called whenever a packet is received
            void RecvPacket(Network.EnetPacket packet);
            /// Crash / Bugsplat
            void Crash();
            /// Animation
            void Animation(Game.Unit unit, string animation);
            /// Notify
            void Notify(string event, Game.Unit unit);
            /// UpdateObj
            void UpdateObj(Game.Unit unit, string prop, float fOldVal, float fNewVal);
            /// AplyParticle
            void AplyParticle(Game.Unit unit, Game.Unit particle);
            /// WebView loading state
            void WebState(WebView.State state, WebView view, string url);
            /// WebView finished loading
            void WebInit(WebView view, string url);
    };

    /**
     *  @brief Binds a callback
     *  @code
     *  Callback.Bind("Load", function() 
     *      print("Hello World")
     *  end)
     *  @endcode
     */
    bool Bind(string szCallback, callbackFunction fnc);
    /// Binds a callback
    bool Bind(CallBacks eCallback, callbackFunction fnc);
    /// Unbinds a callback
    bool Unbind(string szCallback, callbackFunction fnc);
    /// Triggers a callback list
    bool Trigger(string szCallback, object param1);
    /// Returns a callback list
    ipairs<callbackFunction> GetCallbacks(string szCallback);
}
}