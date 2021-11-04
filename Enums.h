#pragma once
namespace EffectSupply {
	enum Type {
		Heal = 1 << 0,
		MajorHeal = 1 << 1,
		Cure = 1 << 2,
		Feed = 1 << 3,
		Arcana = 1 << 4,
		Buff = 1 << 5,
		Debuff = 1 << 6,

	};
}


// version avec des map similaire abilitie
enum class SupplyEffect {
	Heal, majorHeal, Cure, Feed, Buff, Arcana, Debuff,

};
enum class Effect {
	Burn, Blinded, AcidSolving, Freeze, Paralized, Grounded, Charmed, Scared, Enraged, Bleed, Cure,
};

enum class TargettingType {
	Self, AllAllies, AllEnemie, AllExceptMe, MeAndOneAlly, OneEnnemie, OneAlly, OneUnit,
};
enum class AbilitieType {
	PhysicalMelee, physicalRanged, MagicalMelee, MagicalRanged
};

