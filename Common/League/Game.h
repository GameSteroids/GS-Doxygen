namespace Graphics {
    //!  Float Text Types
    enum FloatTextMode {
        INVULNERABLE = 0, ///< Invulnerable
        SPECIAL = 1,  ///< Special
        HEAL = 2, ///< Heal
        MANA_HEAL = 3, ///< ManaHeal
        MANA_DAMAGE = 4, ///< ManaDamage
        DODGE = 5, ///< Dodge
        CRITICAL = 6, ///< Critical
        EXPERIENCE = 7, ///< Experience
        GOLD = 8, ///< Gold
        LEVEL = 9,  ///< Level
        DISABLE = 10, ///< Disable
        QUEST_RECEIVED = 11, ///< QuestReceived
        QUEST_COMPLETED = 12, ///< QuestComplete
        SCORE = 13, ///< Score
        PHYSICAL_DAMAGE = 14, ///< PhysicalDamage
        MAGIC_DAMAGE = 15, ///< MagicDamage
        TRUE_DAMAGE = 16, ///< TrueDamage
        ENEMY_PHYSICAL_DAMAGE = 17,///< EnemyPhysicalDamage
        ENEMY_MAGIC_DAMAGE = 18,///< EnemyMagicDamage
        ENEMY_TRUE_DAMAGE = 19,///< EnemyTrueDamage
        ENEMY_CRITICAL = 20,///< EnemyCritical
        COUNT_DOWN = 21,///< CountDown
        LEGACY = 22,///< Legacy
        LEGACY_CRITICAL = 23,///< LegacyCritical
        DEBUG = 24,///< Debug
    };
    /**
    * @brief Emits a Ping Signal
    * @param text text to print
    * @param x text x
    * @param y text y
    * @param iType Game.FloatTextMode
    */
    void PrintFloatText(string text, float x, float y, Game.FloatTextMode iType);
}

//!  Namespace with LoL functions and structures
namespace Game {

    //!  Unit resource types.
    enum PARType {
        UNLIMITED = 0, ///< No PAR Limit
        MANA = 1, ///< Depends on mana pool
        ENERGY = 2, ///< Depends on energy pool
        BLOOD = 3, ///< Depends on blood pool
    };

    //!  Unit Teams
    enum Team {
        NONE = 0, ///< No Team
        BLUE = 100, ///< Blue Team
        RED = 200, ///< Red Team
        NEUTRAL = 300, ///< Neutral Team
    };

    //!  Ping Types
    enum Ping {
        NORMAL = 0, ///< Normal Ping
        UNKNOWN_PING = 1, ///< ?
        DANGER = 2, ///< Danger Ping
        MISSING = 3, ///< Missing Ping
        ON_MY_WAY = 4, ///< On my way Ping
        FALLBACK = 5, ///< Fallback Ping
        ASSIST = 6, ///< Assist Ping
    };

    //!  Spell Slots
    enum Slots {
        SPELL_1 = 0, ///< Q Spell
        SPELL_2 = 1, ///< W Spell
        SPELL_3 = 2, ///< E Spell
        SPELL_4 = 3, ///< R Spell
        ITEM_1 = 4, ///< Slot 1 Item
        ITEM_2 = 5, ///< Slot 2 Item
        ITEM_3 = 6, ///< Slot 3 Item
        ITEM_4 = 7, ///< Slot 4 Item
        ITEM_5 = 8, ///< Slot 5 Item
        ITEM_6 = 9, ///< Slot 6 Item
        ITEM_7 = 10, ///< Slot 7 Trinket
        RECALL = 11, ///< Recall
        SUMMONER_1 = 12, ///< Summoner 1
        SUMMONER_2 = 13, ///< Summoner 2
    };

    //!  Spell States
    enum SpellState {
        READY = 0, ///< Spell is ready for us
        NOT_LEARNED = 2, ///< Spell not learned yet
        SUPRESSED = 3, ///< Spell is supressed
        COOLDOWN = 4, ///< Spell is in cooldown
        NO_MANA = 5, ///< Not enough mana for spell
        UNKNOWN_STATE = 10, ///< ?
    };

    class SyncBlock {
    public:
        /// Returns the player id
        int id;
        ///Returns the player name
        string name;
        ///Returns the player hero
        string type;
        /// Returns the player rank
        string rank;
        /// Returns the player team ID
        int team;
        /// Returns if the player is a bot
        bool bot;
    };

    namespace Window {
        /// Returns if LoL window is in Window mode
        void IsWindowed();
        /// Returns LoL window position
        Vector3 GetPos();
        /// Returns if the game is focused
        bool IsFocused();
        /// Updates LoL window positions
        void UpdateWindow();
        /// Sends a message to the game HWND
        void SendMessage();

        /**
        * Blocks the HWND Message from being processed by the client
        * @see AllowKeyInput
        */
        void BlockMsg();
    }

    /**
    * @brief World object list count
    *
    * @code
    * for i = 0,Game.ObjectCount() do
    *   local obj = Game.Object(i)
    *   --Use the obj here
    * end
    * @endcode
    *
    * @return Total number of object to cycle trough
    * @see Object(int index), ObjectByNetworkId(int networkID)
    */
    int ObjectCount();
    /**
    * @brief Gets an object from the world list by index.
    *
    * @code
    * for i = 0,Game.ObjectCount() do
    *   local obj = Game.Object(i)
    *   --Use the obj here
    * end
    * @endcode
    *
    * @return Unit object based on index.
    * @see ObjectCount(), ObjectByNetworkId(int networkID)
    */
    Game::Unit Object(int index);
    /**
    * @brief Gets an object from the world list by network ID.
    * @return Unit object based on networkID.
    * @see ObjectCount(), Object(int networkID)
    */
    Game::Unit ObjectByNetworkId(int networkID);


    /**
    * @brief World hero list count
    *
    * @code
    * for i = 0,Game.HeroCount() do
    *   local hero = Game.Hero(i)
    *   --Use the hero here
    * end
    * @endcode
    *
    *
    * @return Total number of heroes to cycle trough
    * @see Hero(index)
    */
    int HeroCount();
    /**
    * @brief Gets an hero from the world hero list
    *
    * @code
    * for i = 0,Game.HeroCount() do
    *   local hero = Game.Hero(i)
    *   --Use the hero here
    * end
    * @endcode
    *
    *
    * @return Hero unit based on index.
    * @see HeroCount()
    */
    Game::Unit Hero(int index);

    //!  Class used by HPBar templates.
    class HPBarTemplate {
        public:
            Graphics::Vector2 percentageOffset;
            Graphics::Vector2 screenSpaceOffset;
            Graphics::Vector2 healthOffset;
            Graphics::Vector2 parOffset;
            Graphics::Vector2 locOffset;
            Graphics::Vector2 levelTextOffset;
            Graphics::Vector2 titleTextOffset;
            Graphics::Vector2 chatBubbleOffset;
            float fadeSpeed;
    };

    /**
    * @brief Gets the local hero
    *
    * @return Returns local hero
    * @see Target()
    */
    Game::Unit MyHero();
    /**
    * @brief Gets the targeted unit.
    *
    * @return Returns targeted unit.
    * @see MyHero(),Target(Game.Unit unit)
    */
    Game::Unit Target();
    /**
    * @brief Sets the targeted unit.
    *
    * @return Returns targeted unit.
    * @see MyHero(),Target()
    */
    Game::Unit Target(Game.Unit unit);

    /**
    * @brief Gets the server timer.
    *
    * @return Returns server timer.
    * @see Timer()
    */
    float ServerTimer();

    /**
    * @brief Gets the in game timer.
    *
    * @return Returns in game timer.
    * @see ServerTimer()
    */
    float Timer();

    /**
    * @brief Gets the game latency.
    *
    * @return Returns game latency.
    * @see ServerTimer()
    */
    float Latency();

    /**
    * @brief Emits a Ping Signal
    * @param iMode Game.Ping
    * @param x ping x
    * @param y ping y
    * @param z ping z
    * @param bReal Send Ping (true), Recv Ping (false)
    */
    void PingSignal(Game.Ping iMode, float x, float y, float z, bool bReal);


    namespace Chat {
        /**
        * @brief Prints text to the game chat window
        * @param text text to print
        * @see Send(string text)
        */
        void Print(string text);
        /**
        * @brief Sends text to the chat server
        * @param text text to send
        * @see Print(string text)
        */
        void Send(string text);
        /**
        * @brief Blocks the current chat message from being sent to server
        * @see BlockChat()
        */
        void Block();

        /**
        * @brief Enables or Disables the game chat window
        * @param status Game chat window status
        * @see AllowKeyInput()
        */
        void SetChatStatus(bool status);
    }

    /**
    * @brief Levels up a spell.
    * @param slot Spell Slot
    */
    float LevelSpell(Game.Slots slot);

    /**
    * @brief Buys an item
    * @param itemID ID of the desired item
    * @see SellItem()
    */
    void BuyItem(int itemID);
    /**
    * @brief Sells an item slot.
    * @param slot Slot to be sold
    * @see BuyItem()
    */
    void SellItem(Game.Slots slot);


    /**
    * @brief Creates and applies a particle to unit
    * @param particle Particle Name
    * @param unit1 Unit to apply the particle
    * @param unit2 Unknown
    * @param unit3 Unknown
    * @param wFlag Unknown
    * @param pos1 Unknown
    * @param pos2 Unknown
    * @param fVal Unknown
    * @return Game.Unit New Particle
    * @see DeleteObject
    */
    Game::Unit ApplyParticle(string particle, Game.Unit unit1, Game.Unit unit2, Game.Unit unit3, int wFlag, Vector3 pos1, Vector3 pos2, float fVal);
    /**
    * @brief Deletes a game object
    * @param unit Unit to be deleted
    */
    void DeleteObject(Game.Unit unit);

    namespace HPTemplate {

        /**
        * @brief Returns the HP Bar Template for the local player
        * @see GetFriendlyBarData(),GetEnemyBarData()
        */
        Game::HPBarTemplate Self();
        /**
        * @brief Returns the HP Bar Template for friendly players
        * @see GetSelfBarData(),GetEnemyBarData()
        */
        Game::HPBarTemplate Friendly();
        /**
        * @brief Returns the HP Bar Template for enemy players
        * @see GetSelfBarData(),GetFriendlyBarData()
        */
        Game::HPBarTemplate Enemy();
    }


    /**
    * @brief Enables or Disables the game key processing
    * @param status Key Input Processing status
    * @see BlockMsg(),AllowCameraInput()
    */
    void AllowKeyInput(bool status);
    /**
    * @brief Enables or Disables the game camera movement
    * @param status Camera Input Processing status
    * @see AllowKeyInput()
    */
    void AllowCameraInput(bool status);


    /**
    * @brief Returns if the position is a grass field
    * @param position Map Position to be scanned
    * @see IsWall()
    */
    bool IsGrass(Vector3 position);
    /**
    * @brief Returns if the position is a wall
    * @param position Map Position to be scanned
    * @see IsGrass()
    */
    bool IsWall(Vector3 position);

    /**
    * @brief Returns the navigation path for the unit based on endPos
    * @param endPos Destination Position
    */
    NavigationPath CalculatePath(Unit unit,Vector3 endPos)
    /**
    * @brief Returns if the game server region
    */
    string Game.GetRegion();
    /**
    * @brief Returns the hash of string
    * @param text string to be hashed
    */
    int Game.GetSkillHash(string text);

    /**
    * @brief Returns unit hp bar pos
    * @return Vector3
    * @see GetUnitHPBarOffset()
    */
    Vector3 GetUnitHPBarPos();
    /**
    * @brief Returns unit hp bar offset
    * @see GetUnitHPBarPos()
    */
    float GetUnitHPBarOffset();

    /**
    * @brief Draws green or red click animation to the position on the screen.
    * @param position Position to draw the click animation.
    */
    void ShowCursorClick(Vector3 position, bool bAttackCursor);

    //!  Class used by Spell Processor callback
    class Spell {
        public:
            /// returns the spell source position.
            Vector3 startPos;
            /// returns the spell destination position.
            Vector3 endPos;
            /// returns the projectile networkID.
            int projectileID;
            /// returns the spell level.
            int level;
            /// returns the spell name.
            string name;
            /// returns the target.
            Unit target;
            /// returns the spell wind up time.
            float windUpTime;
            /// returns the spell animation time.
            float animationTime;
    };

    //!  Class used by game buffs
    class Buff {
        public:
            /// returns if the buff is valid.
            bool valid;
            /// returns the buff start time.
            float startT;
            /// returns the buff end time.
            float endT;
            /// returns the buff name.
            string name;
    };

    //!  Class used by game spell data
    class SpellData {
        public:
            /// returns the spell name.
            string name;
            /// returns the spell mana cost.
            int mana;
            /// returns the spell cooldown.
            int cd;
            /// returns the spell range.
            int range;
            /// returns the spell channel duration.
            int channelDuration;
            /// returns the spell current cooldown.
            float currentCd;
            /// returns if the spell is a toggle.
            bool isToggleSpell;
    };

    //!  Class used by game items
    class Item {
        public:
            /// returns the item name.
            string name;
            /// returns the item id.
            int id;
            /// returns the item stack count.
            int stacks;
    };
    //! Mastery information of Players
    class MasteryData {
        public:
            ///id of mastery
            number id;
            ///points of mastery
            byte points;
    };

    class NavigationPath {
    public:
        /// returns if the path is valid and active
        bool valid;
            /// Returns the number of points in the move path
            int count;
            /// Returns the index of the current path
            int curPath;
            /// Returns the start position of the path
            Vector3 startPath;
            /// Returns the end position of the path
            Vector3 endPath;
            /// Returns the path position based on the index
            Vector3 Path(int iIndex);
    };
    
    //!  Class used by all game units.
    class Unit {
        public:
            /// returns if the unit is dead.
            bool dead;
            /**
            * Returns the unit team.
            * @return Game.Team
            */
            Team team;

            /// returns if the unit is valid.
            bool valid;
            /// returns the unit index.
            int index;
            /// returns the next unit index.
            int nextIndex;
            /// returns if the unit is visible.
            bool visible;
            /// returns the unit level.
            int level;

            /// returns the player name.
            string name;
            /// returns the character name.
            string charName;

            /// returns the unit type.
            string type;
            /// returns the unit position.
            Vector3 pos;
            /// returns the unit server position.
            Vector3 visionPos;

            /// returns the x position axis. (Horizontal)
            float x;
            /// returns the y position axis. (Depth)
            float y;
            /// returns the z position axis. (Vertical)
            float z;

            /// returns the unit minimum bounding box.
            Vector3 minBBox;
            /// returns the unit maximum bounding box.
            Vector3 maxBBox;

            /// returns the unit buff count.
            int buffCount;

            /// returns the unit network ID.
            int networkID;

            /// returns if the unit is invulnerable.
            bool isInvulnerable;
            /// returns if the unit is physically immune.
            bool isPhysImune;
            /// returns if the unit is magically immune.
            bool isMagicImune;
            /// returns if the unit is controlled by the local player.
            bool controlled;
            /// returns if the unit is melee.
            bool isMelee;
            /// returns if the unit is ranged.
            bool isRanged;
            /// returns if the unit is AI (Bot).
            bool isAI;
            /// returns if the unit is the local player.
            bool isMe;
            /// Returns if the unit is moving
            bool isMoving;
            /// returns if the unit can attack.
            bool canAttack;
            /// returns if the unit can cast.
            bool canCast;
            /// returns if the unit can move.
            bool canMove;
            /// returns if the unit is winding up.
            bool isWindingUp;
            /// returns if the unit is stealthed.
            bool isStealthed;
            /// returns if the unit is RevealSpecificUnit.
            bool isRevealSpecificUnit;
            /// returns if the unit is taunted.
            bool isTaunted;
            /// returns if the unit is charmed.
            bool isCharmed;
            /// returns if the unit is feared.
            bool isFeared;
            /// returns if the unit is asleep.
            bool isAsleep;
            /// returns if the unit is nearSight.
            bool isNearSight;
            /// returns if the unit is ghosted.
            bool isGhosted;
            /// returns if the unit has no Render flag.
            bool isNoRender;
            /// returns if the unit is fleeing.
            bool isFleeing;
            /// returns if the unit is forceRenderParticles.
            bool isForceRenderParticles;
            /// returns if the unit is targetable.
            bool isTargetable;
            /// returns if the unit is targetableToTeam.
            bool isTargetableToTeam;
            /// returns the unit range.
            float range;
            /// returns the unit deathTimer.
            float deathTimer;
            /// returns the unit minionScore.
            float minionScore;
            /// returns the unit currentSpell.
            int currentSpell;
            /// returns the unit collision radius.
            float collisionRadius;
            /// returns the unit collision height.
            float collisionHeight;
            /// returns the unit path Collision Radius.
            float pathCollisionRadius;
            /// returns the unit vision radius.
            float visionRadius;

            /// returns the unit cooldown reduction.
            float cdr;
            /// returns the unit current health.
            float health;
            /// returns the unit maximum health.
            float maxHealth;
            /// returns the unit current mana.
            float mana;
            /// returns the unit maximum mana.
            float maxMana;
            /**
            * returns the unit resource type.
            * @return Game.PARType
            */
            PARType parType;

            /// returns the unit hp pool.
            float hpPool;
            /// returns the unit hp regeneration rate.
            float hpRegen;
            /// returns the unit mp regeneration rate.
            float mpRegen;
            /// returns the unit critical chance.
            float critChance;
            /// returns the unit critical damage.
            float critDmg;
            /// returns the unit attack speed.
            float attackSpeed;
            /// returns the unit exp bonus.
            float expBonus;
            /// returns the unit life steal.
            float lifeSteal;
            /// returns the unit spellvamp.
            float spellVamp;
            /// returns the unit physical reduction.
            float physReduction;
            /// returns the unit magical reduction.
            float magicReduction;
            /// returns the unit armor penetration.
            float armorPen;
            /// returns the unit magic penetration.
            float magicPen;
            /// returns the unit armor penetration percent.
            float armorPenPercent;
            /// returns the unit magic penetration percent.
            float magicPenPercent;
            /// returns the unit total damage.
            float totalDamage;
            /// returns the unit added damage.
            float addDamage;
            /// returns the unit Ability Power.
            float ap;
            /// returns the unit damage.
            float damage;
            /// returns the unit armor.
            float armor;
            /// returns the unit magic armor.
            float magicArmor;
            /// returns the unit movement speed.
            float ms;
            /// returns the local unit current gold.
            float gold;

            /// returns the unit nav mesh
            NavigationPath path;
            /// returns if the unit nav mesh is active
            bool isMoving;

            /// Returns if the object is a unit or object
            bool IsUnit();
            /// Sets the unit vision radius
            void SetVisionRadius(float fRadius);
            /// Stops movement
            void Stop();
            /// Holds movement
            void Hold();
            /// Sets the position client side
            void SetPosition(Vector3 vPosition);
            /// Issues an Move command
            void Move(float x, float y);
            /// Issues an AttackMove command
            void AttackMove(float x, float y);
            /// Issues an Attack Command
            void Attack(float x, float y);
            /// Issues an Attack Command
            void Attack(Game.Unit target);
            /// Returns the distance from this unit and the target
            float DistanceTo(float x, float y);
            /// Returns the distance from this unit and the target
            float DistanceTo(Vector2 vPosition);
            /// Returns the distance from this unit and the target
            float DistanceTo(Vector3 vPosition);
            /// Returns the distance from this unit and the target
            float DistanceTo(Game.Unit target);
            /// Calculates the damage that would be dealt to target
            void CalcDamage(Game.Unit target, float fDamage);
            /// Calculates the damage that would be dealt to target
            void CalcMagicDamage(Game.Unit target, float fDamage);
            /**
            * Returns the spell data object
            * @return Game.SpellData
            */
            Game.SpellData GetSpellData(Game.Slots spellIndex);
            /**
            * Returns the spell status
            * @return Game.SpellState
            */
            Game.SpellState CanUseSpell(Game.Slots slotIndex);
            /// Casts a spell
            void CastSpell(Game.Slots spellIndex);
            /// Casts a spell
            void CastSpell(Game.Slots spellIndex, float x, float y);
            /// Casts a spell
            void CastSpell(Game.Slots spellIndex, Game.Unit target);
            /**
            * Returns the buff object
            * @return Game.Buff
            */
            Game.Buff GetBuff(int iIndex);
            /// Gets the itemID at inventory
            int getInventorySlot(int iIndex);
            /**
            * Returns the item object from inventory
            * @return Game.Item
            */
            Game.Item GetItem(Game.Slots slot);

            /// Returns if the unit has a move path
            bool hasMovePath;
            /**
            * @brief Returns iterator to MasterData
            * @code
            * for mastery in myHero.masteries do
            *   print(mastery.id .. '|' .. mastery.points)
            * end
            * @endcode
             */
            iterator<MasteryData> masteries;
            /// Returns iterator to Quint ID's
            iterator<number> quints;
            /// Returns iterator to Glyph ID's
            iterator<number> glyphs;
            /// Returns iterator to Seal ID's
            iterator<number> seals;
            /// Return iterator to Mark ID's
            iterator<number> marks;
            
            //! Default unit constructor.
            Unit() {
            }
    };
    
    //! Class obtained by ArchiveEntry content
    class IniBin {
        public:
            ///Merges IniBin with other IniBin, so the access of variables is more convenient.
            void MergeWith(IniBin other);
            ///Gets specific Value of IniBin
            object Get(string section, string variableName);
    };
    //! Entry of Archive
    class ArchiveEntry {
        public:
            ///Extracts to content to filesystem
            void Extract(const string& path);
            string path;
            /**
             *  @brief Content of entry. Might be inibin, txt etc.
             *  
             *  Will throw an error if you try to open an unsupported format.
             *  In that case, please let us know so we can add it.
             */
            object content;
    };
    /**
     *  Access to Archived Game Files via file path.
     *  @code
     *  local path = ""
     *  for p, entry in pairs(Game.Archive) do
     *      local path = tostring(p)
     *      break;
     *  end
     *  print(Game.Archive[path].path)
     *  @endcode
     */
    table<string, ArchiveEntry> Archive;
}