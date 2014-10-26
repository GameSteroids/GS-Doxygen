#pragma once

#include "General.h"

//!  Class used by all game units. 
class Unit {
public:
	/// returns if the unit is valid.
	bool valid;
	/// returns the team of the unit.
	int team;

	/// returns the unit ID.
	int uid;

	/// returns the player name.
	string name;

	/// returns the unit type.
	int type;
	/// returns the unit position.
	Geometry.Vector3 pos;
	/// returns the hero position.
	Geometry.Vector3 heroPos;

	/// Returns if the unit is a client
	bool isClientState;
	/// Returns if the unit is a camera
	bool isEntityCamera;
	/// Returns if the unit is a chest
	bool isEntityChest;
	/// Returns if the unit is a effect
	bool isEntityEffect;
	/// Returns if the unit is a game info
	bool isGameInfo;
	/// Returns if the unit is a game stats
	bool isGameStats;
	/// Returns if the unit is a linear affector
	bool isLinearAffector;
	/// Returns if the unit is a player
	bool isPlayer;
	/// Returns if the unit is a playerview
	bool isPlayerView;
	/// Returns if the unit is a shop info
	bool isShopInfo;
	/// Returns if the unit is a shop item info
	bool isShopItemInfo;
	/// Returns if the unit is a team info
	bool isTeamInfo;
	/// Returns if the unit is a affector info
	bool isAffectorInfo;
	/// Returns if the unit is a bit info
	bool isBitEntityInfo;
	/// Returns if the unit is a building
	bool isBuildingEntity;
	/// Returns if the unit is a creep
	bool isCreepEntity;
	/// Returns if the unit is a critter
	bool isCritterEntity;
	/// Returns if the unit is a ability
	bool isEntityAbility;
	/// Returns if the unit is a ability attribute
	bool isEntityAbilityAttribute;
	/// Returns if the unit is a item
	bool isEntityItem;
	/// Returns if the unit is a proxy ability
	bool isEntityProxyAbility;
	/// Returns if the unit is a state
	bool isEntityState;
	/// Returns if the unit is a state nect accum
	bool isEntityStateNetAccum;
	/// Returns if the unit is a tool
	bool isEntityTool;
	/// Returns if the unit is a familiar
	bool isFamiliarEntity;
	/// Returns if the unit is a gadget
	bool isGadgetEntity;
	/// Returns if the unit is a game
	bool isGameEntity;
	/// Returns if the unit is a hero
	bool isHeroEntity;
	/// Returns if the unit is a light
	bool isLightEntity;
	/// Returns if the unit is a neutral boss
	bool isNeutralBossEntity;
	/// Returns if the unit is a neutral
	bool isNeutralEntity;
	/// Returns if the unit is a order
	bool isOrderEntity;
	/// Returns if the unit is a powerup
	bool isPowerupEntity;
	/// Returns if the unit is a projectile
	bool isProjectileEntity;
	/// Returns if the unit is a pop
	bool isPropEntity;
	/// Returns if the unit is a shop
	bool isShopEntity;
	/// Returns if the unit is a slave
	bool isSlaveEntity;
	/// Returns if the unit is a spawner
	bool isSpawnerEntity;
	/// Returns if the unit is a unit
	bool isUnitEntity;
	/// Returns if the unit is a visual
	bool isVisualEntity;
	/// Returns if the unit is a waypoint
	bool isWaypointEntity;
	/// Returns if the unit is a hero pet
	bool isHeroPetEntity;

	/// returns the unit health.
	float health;
	/// returns the unit max health.
	float maxHealth;
	/// returns the unit mana.
	float mana;
	/// returns the unit max mana.
	float maxMana;
	/// returns the unit level.
	int level;
	/// returns the unit armor.
	float armor;
	/// returns the unit range.
	float range;
	/// returns the unit baseDamage.
	float baseDamage;
	/// returns the unit magicArmor.
	float magicArmor;
	/// returns the unit movement speed.
	float ms;
	/// returns the unit respawn Time.
	float respawnTime;
	/// returns if the unit can Attack.
	bool canAttack;
	/// returns the unit minimum damage.
	float dmgMin;
	/// returns the unit maximum damage.
	float dmgMax;
	/// Returns if the unit is a hero
	bool isHero;
	/// Returns the linked hero unit
	Unit hero;
	/// Returns if the unit is currently moving
	bool isMoving;
	/// Returns if the unit is currently attacking
	bool isAttacking;
	/// Returns if the unit is currently casting
	bool isCasting;

	//! Default unit constructor.
	Unit() {

	}
};