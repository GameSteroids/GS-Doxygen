

//!  Namespace with Smite functions and structures
namespace Game {

    /**
    * @brief Gets the lobby state
    *
    * @return Returns inside lobby state
    */
    bool IsLobby();
    /**
    * @brief Aims at the targeted pawn
    *
    * @see AimAtVector(Vector3 pos)
    */
    void AimAtPlayer(Pawn pawn);
    /**
    * @brief Aims at the targeted vector
    *
    * @see AimAtPlayer(Pawn pawn)
    */
    void AimAtVector(Vector3 pos);

    /**
    * @brief Emits a Ping Signal
    * @param text text to print
    * @param x text x
    * @param y text y
    * @param iType Game.FloatTextMode
    */
    void DrawText(float x, float y,string text,float xScale,float yScale,Color color);




    //!  Class used by Colors
    class Color {
        public:
            /// Color constructor
            Color(char A,char R,char G,char B);
            /// alpha
            char A;
            /// red
            char R;
            /// green
            char G;
            /// blue
            char B;
    };


    //!  Class used by TargetAim Methods
    class AimData {
        public:
            /// returns the spell source position.
            Vector3 startTrace;
            /// returns the spell destination position.
            Vector3 endTrace;
            /// returns the spell destination position.
            Vector3 aimVector;
            /// returns the actor to be hit
            Pawn hitActor;
            /// returns if the result is valid
            bool bResult;
    };

    //!  Class used by attack devices (weapons and skills)
    class AttackDevice {
        public:
            /// returns if is a hand device
            bool isHandDevice;
            ///
            int skillID;
            ///
            int deviceID;
            ///
            float range;
            ///
            float speed;
            ///
            int level;
            ///
            int totalPoints;
            ///
            bool isMeleeAttack;
            ///
            bool isRangedAttack;
            /// returns the lock on target AimData
            AimData worldMapLockOnTargetAim;
            /// returns the  AimData
            AimData spawnPointTargetAim;
            /// returns the  AimData
            AimData lockOnTargetAim;
            /// returns the  AimData
            AimData deployAim;
            /// returns the  AimData
            AimData groundTargetAim;
            /// returns the  AimData
            AimData linearTargetAim;
            /// returns the  AimData
            AimData selfTargetAim;
            /// returns the  AimData
            AimData aoeTargetAim;
            /// returns the  AimData
            AimData coneTargetAim;
            /// returns the  AimData
            AimData meleeTargetAim;
            /// returns the  AimData
            AimData reticleTargetAim;
            /// returns the  AimData
            AimData targetingAim;
            /// returns the device name.
            string name;


            /// Enters targetting mode
            void EnterTargetingMode();
            /// Exits targetting mode
            void ExitTargetingMode();
            /// Adds a skill point
            void AddSkillPoint();
    };

    //!  Class used by game items
    class Pawn {
        public:
            /// returns the item name.
            string name;
            /// returns the pawn distance from local pawn
            float distance;
            /// returns the hand device (weapon)
            AttackDevice handDevice;
            /// returns the pawn angle in relation to local camera angle
            float angle;
            /// returns the pawn team
            int team;
            /// returns the pawn health
            float health;
            /// returns the pawn position in world
            Vector3 pos;
            /// returns the pawn position in screen
            Vector3 screenPos;
            /// returns the pawn speed in relation to the ground
            float groundSpeed;
            /// returns the pawn velocity vector
            Vector3 velocity;
            /// returns the pawn head position
            Vector3 headPos;
            /// returns the attack device list (weapons and skills)
            List<AttackDevice> attacks;

            /// Gets distance from pawn to vector
            float Distance(Vector3 pos);
            /// Draws pawn ESP
            void DrawESP(Color color);
            /// Aims at pawn
            void AimAt();
            /// Moves pawn by deltaPos
            void MoveTo(Vector3 deltaPos);
            /// Moves pawn close to pos
            void MoveToV(Vector3 pos);
    };

    //!  Class used by gods
    class Character : public Pawn {
        public:
        
    };

    //!  Class used by local player
    class LocalPlayer {
        public:
            /// returns local player name
            string name;
            /// returns local player god
            Character god;
            /// returns camera viewPosition
            Vector3 viewPos;
    };


    //!  Class used by smite helper
    class SmiteHelper {
        public:
            /// returns local player object
            LocalPlayer localPlayer;
            /// returns a list of pawns
            List<Pawn> pawns;
            /// returns a list of minions
            List<Pawn> minions;
            /// returns a list of towers
            List<Pawn> towers;
            /// returns a list of gods
            List<Pawn> gods;
            /// returns a list of ally gods
            List<Pawn> allyGods;
            /// returns a list of enemy gods
            List<Pawn> enemyGods;
            /// returns the local username
            string username;

    };
}