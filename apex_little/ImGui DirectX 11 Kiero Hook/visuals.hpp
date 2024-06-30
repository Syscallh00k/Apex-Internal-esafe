#include "classes.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <array>
#include <typeinfo> 
#include <D3D11.h>
inline uintptr_t GameAddress;
inline bool bbox;
inline bool operatorESP = false;
inline bool bname;
inline bool bdistance;
inline bool SpeedHack;
inline bool heirloomchanger = false;
inline bool autograple;
inline bool SpectatorCount = false;
inline int autograpleKey, autograpleState;
inline bool bhealth;
inline bool fakeduck = false;
inline bool bshield;
inline bool HideName;
inline bool IncreaseDrive;
inline bool FastSkyDrive;
inline bool ChargeRifle;
inline int maxDistance = 1000;
inline bool bGlow;
inline float levelCol[4] = { 255,255,255,255 };
inline bool bLevel = false;
inline bool bInfo = false;
inline ImColor idColors[] =
{
	{168, 50, 50},
	{168, 91, 50},
	{168, 127, 50},
	{168, 166, 50},
	{105, 168, 50},
	{50, 168, 62},
	{50, 168, 160},
	{50, 115, 168},
	{50, 62, 168},
	{70, 50, 168},
	{117, 50, 168},
	{146, 50, 168},
	{168, 50, 131},
	{168, 50, 85},
	{255, 255, 255},
	{0, 0, 0},
	{105, 105, 105},
	{255, 153, 153},
	{255, 0, 183},
	{255, 140, 0}
};
inline bool bTeamCol;
//inline ID3D11ShaderResourceView* PathFinder_texture = nullptr;
//inline ID3D11ShaderResourceView* revenat_texture = nullptr;
//inline ID3D11ShaderResourceView* seer_texture = nullptr;
//inline ID3D11ShaderResourceView* Maggie_texture = nullptr;
//inline ID3D11ShaderResourceView* Bangladesh_texture = nullptr;
//inline ID3D11ShaderResourceView* bloodhound_texture = nullptr;
//inline ID3D11ShaderResourceView* catalyst_texture = nullptr;
//inline ID3D11ShaderResourceView* Fuse_texture = nullptr;
//inline ID3D11ShaderResourceView* Gibraltar_texture = nullptr;
//inline ID3D11ShaderResourceView* newcastle_texture = nullptr;
//inline ID3D11ShaderResourceView* wattson_texture = nullptr;
//inline ID3D11ShaderResourceView* wraith_texture = nullptr;
//inline ID3D11ShaderResourceView* ash_texture = nullptr;
//inline ID3D11ShaderResourceView* ballistic_texture = nullptr;
//inline ID3D11ShaderResourceView* caustic_texture = nullptr;
//inline ID3D11ShaderResourceView* crypto_texture = nullptr;
//inline ID3D11ShaderResourceView* lifeline_texture = nullptr;
//inline ID3D11ShaderResourceView* loba_texture = nullptr;
//inline ID3D11ShaderResourceView* mirage_texture = nullptr;
//inline ID3D11ShaderResourceView* octane_texture = nullptr;
//inline ID3D11ShaderResourceView* rampart_texture = nullptr;
//inline ID3D11ShaderResourceView* valk_texture = nullptr;
//inline ID3D11ShaderResourceView* vantage_texture = nullptr;
//inline ID3D11ShaderResourceView* horizon_texture = nullptr;
//inline ID3D11ShaderResourceView* Empty_Texture = nullptr;
inline float rounding;
inline bool vis;
inline bool bHands;
inline bool bWeapon;
inline bool WeaponName;
inline bool airstuck;
inline bool NoSpread; inline float pitchSTR = 1;
inline float yawSTR = 1;
inline bool ItemGlow;
inline bool bIgnoreDowned;
static int cases = 0;
inline int testing_int = 7;
static int r = 1.00, g = 0.00, b = 1.00;
inline bool bThirdPerson;
inline const char* GlowMethods[] = { "Red Pulse", "Plasma", "Blueberry", "Matrix", "Hot Rod", "Citrus", "Purple" };
inline int GlowMethodInt = 0;
inline bool aimTeamCheck;
inline bool renderFov;
inline int seerFov = 10;
inline float FOVCOLOR[4] = { 255,255,255,255 };
inline bool Heirloom;
inline bool bTrigger;
inline bool Legendary;
inline bool Epic;
inline bool Rare;
inline bool Common;
inline int glowSelection = 0;
inline int weaponSelection = 0;
inline bool Freecam;
inline int freecamKey, FreeCamState;
inline int AirStuckKey, AirStuckState;
inline int thridPersonKey, thirdPersonState;
inline int triggerKey, triggerState;
inline bool Unlockall;
inline bool SilentAim;
inline int handSelection = 0;
inline int fov = 100;
inline bool bTeamCheck;
inline bool bSeer;
inline bool bCorner;
inline bool bItemEsp;
inline int aimbotDist = 250;
inline const char* playerSelectionOptions[] = { "Standard", "glass", "Pulse", "Outline", "Glitch", "Edit" };
inline const char* weaponSelectionOptions[] = { "Full", "White With Outline", "Outline", "Pulse", "Glitch", "Edit" };
inline const char* handSelectionOptions[] = { "Full", "Pulse", "Outline", "Edit" };
inline bool bVis = false;
inline int maxLootDist = 500;
inline int lootKey = 0;
inline bool bVisCheck;
inline int aimbotkey, aimbotmode;
inline bool fuckjews = false;
inline bool AimbotVis = false;
inline int secondaimbotkey, secondaimbotmode;
inline int hitbox = 0;
inline const char* hitboxes[] = { "Head", "Neck", "Pelvis", };
inline ImFont* esp_font = nullptr;
inline bool bSnaplines;
inline bool GrenadeEsp;
inline float GrenadeColor[4] = { 255,255,255,255 };
inline const char* snaplinePos[] = { "Bottom", "Center", "Top" };
inline int snaplineSelection = 0;
inline float snaplineCol[4] = { 255,255,255,255 };
inline float playerCol[4] = { 255,255,255,255 };
inline float playerColN[4] = { 255,255,255,255 };
inline float weaponCol[4] = { 255,255,255,255 };
inline float handCol[4] = { 255,255,255,255 };
inline float skeletonCol[4] = { 255,255,255,255 };
inline float BoxCol[4] = { 255,255,255,255 };
inline float NBoxCol[4] = { 255,255,255,255 };
inline float NameCol[4] = { 255,255,255,255 };
inline float DistCol[4] = { 255,255,255,255 };
inline int edit1;
inline int edit2;
inline int edit3;
inline int edit4;
inline bool bDrawTarget;
inline int amountofspectatprs = 0;
inline float TargetColor[4] = { 255,255,255,255 };
inline float weaponColor[4] = { 255,255,255,255 };
inline float healsColor[4] = { 255,255,255,255 };
inline float attachemtColor[4] = { 255,255,255,255 };
inline float grenadeColor[4] = { 255,255,255,255 };
inline float armorColor[4] = { 255,255,255,255 };
inline float ammoColor[4] = { 255,255,255,255 };
inline bool showInfo = false;
inline int infoX = GetSystemMetrics(0) * 0.75;
inline int infoY = GetSystemMetrics(0) * 0.3;
inline bool IsDist;
inline float Speed;
inline int helmid = 912;
inline bool DoAimbot = false;
inline bool removeRecoil = false;
inline std::vector<int> RareID;
inline std::vector<std::string> RareName;
inline bool InstantBullet = false;
inline bool TesFet = false;
inline bool SpeedHackV2 = false;
inline bool ShowFps = false;
inline bool SkinIntroVideo = false;
inline bool Gravity = false;
inline bool TwitchDrops = false;
inline bool Brightness = false;
inline bool DisableFog = false;
inline bool ForceCrossPlayer = false;
inline bool FastSwap = false;
inline bool NoWeaponDelay = false;
inline float Brightnessch = 25.0f;
inline float opfov = 10.0f;
inline bool Fovchanger = false;
inline float LPFOV = 25.0f;
inline bool bhop = false;
inline int bhopkey, bhopstate;
inline bool visCheck = false;
inline bool fastrate;
inline bool instantswap;
inline bool fullshoot;
inline float VisColor[4] = { 255,255,255,255 };
inline bool weaponSelections[29];
inline const char* weaponList[29] =
{
	"Kraber",
	"Mastiff",
	"LStar",
	"Havoc",
	"Devotion",
	"Triple Take",
	"Flatline",
	"Hemlok",
	"G7 Scout",
	"Alternator",
	"R99",
	"Prowler",
	"Volt",
	"Longbow",
	"Charge Rifle",
	"Spitfire",
	"R301",
	"EVA-8 Auto",
	"Peacekeeper",
	"Mozambique",
	"Wingman",
	"P2020",
	"RE-45",
	"Sentinel",
	"Bocek Bow",
	"30-30 Repeater",
	"Nemesis",
	"Rampage",
	"Car"
};
inline bool lightWeapons[7];
inline const char* lightOptions[] =
{
	"G7 Scout",
	"Alternator",
	"R99",
	"Spitfire",
	"R301",
	"P2020",
	"RE-45",
};
inline bool heavyWeapons[5];
inline const char* heavyOptions[] =
{
	"Flatline",
	"Hemlok",
	"30-30 Repeater",
	"Rampage",
	"Car"
};
inline bool energyWeapons[5];
inline const char* energyOptions[] =
{
	"Havoc",
	"Devotion",
	"Triple Take",
	"Volt",
	"Nemesis"
};
inline bool sniperWeapons[4];
inline const char* sniperOptions[] =
{
	"Longbow",
	"Charge Rifle",
	"Wingman",
	"Sentinel",
};
inline bool shotgunWeapons[4];
inline const char* shotgunOptions[] =
{
	"EVA-8 Auto",
	"Peacekeeper",
	"Mastiff",
	"Mozambique"
};
inline bool specialWeapons[4];
inline const char* specialOptions[] =
{
	"Kraber",
	"LStar",
	"Prowler",
	"Bocek Bow"
};
inline bool attachmentSelections[45];
inline const char* attachmentOptions[] =
{
	"1x HCOG (Classic)",
	"2x HCOG (Bruiser)",
	"1x Holo",
	"1x-2x Variable Holo",
	"1x Digital Threat",
	"3x HCOG (Ranger)",
	"2x-4x Variable AOG",
	"6x Sniper",
	"4x-8x Variable Sniper",
	"4x-10x Digital Sniper Threat",
	"Barrel Stabilizer Level 1",
	"Barrel Stabilizer Level 2",
	"Barrel Stabilizer Level 3",
	"Laser Sight Level 1",
	"Laser Sight Level 2",
	"Laser Sight Level 3",
	"Light Magazine Level 1",
	"Light Magazine Level 2",
	"Light Magazine Level 3",
	"Light Magazine Level 4",
	"Heavy Magazine Level 1",
	"Heavy Magazine Level 2",
	"Heavy Magazine Level 3",
	"Heavy Magazine Level 4",
	"Energy Magazine Level 1",
	"Energy Magazine Level 2",
	"Energy Magazine Level 3",
	"Energy Magazine Level 4",
	"Sniper Magazine Level 1",
	"Sniper Magazine Level 2",
	"Sniper Magazine Level 3",
	"Sniper Magazine Level 4",
	"Shotgun Bolt Level 1",
	"Shotgun Bolt Level 2",
	"Shotgun Bolt Level 3",
	"Shotgun Bolt Level 4",
	"Standard Stock Level 1",
	"Standard Stock Level 2",
	"Standard Stock Level 3",
	"Sniper Stock Level 1",
	"Sniper Stock Level 2",
	"Sniper Stock Level 3",
	"Turbocharger",
	"Hammerpoint Rounds",
	"Disruptor Rounds"
};
inline bool opticAttachments[10];
inline const char* opticOptions[] =
{
	"1x HCOG (Classic)",
	"2x HCOG (Bruiser)",
	"1x Holo",
	"1x-2x Variable Holo",
	"1x Digital Threat",
	"3x HCOG (Ranger)",
	"2x-4x Variable AOG",
	"6x Sniper",
	"4x-8x Variable Sniper",
	"4x-10x Digital Sniper Threat",
};
inline bool magazineAttachments[16];
inline const char* magazineOptions[] =
{
	"Light Magazine Level 1",
	"Light Magazine Level 2",
	"Light Magazine Level 3",
	"Light Magazine Level 4",
	"Heavy Magazine Level 1",
	"Heavy Magazine Level 2",
	"Heavy Magazine Level 3",
	"Heavy Magazine Level 4",
	"Energy Magazine Level 1",
	"Energy Magazine Level 2",
	"Energy Magazine Level 3",
	"Energy Magazine Level 4",
	"Sniper Magazine Level 1",
	"Sniper Magazine Level 2",
	"Sniper Magazine Level 3",
	"Sniper Magazine Level 4",
};
inline bool stabilizerAttachments[6];
inline const char* stabilizerOptions[] =
{
	"Barrel Stabilizer Level 1",
	"Barrel Stabilizer Level 2",
	"Barrel Stabilizer Level 3",
	"Laser Sight Level 1",
	"Laser Sight Level 2",
	"Laser Sight Level 3",
};
inline bool stockAttachments[10];
inline const char* stockOptions[] =
{
	"Shotgun Bolt Level 1",
	"Shotgun Bolt Level 2",
	"Shotgun Bolt Level 3",
	"Shotgun Bolt Level 4",
	"Standard Stock Level 1",
	"Standard Stock Level 2",
	"Standard Stock Level 3",
	"Sniper Stock Level 1",
	"Sniper Stock Level 2",
	"Sniper Stock Level 3",
};
inline bool hopAttachments[3];
inline const char* hopOptions[] =
{
	"Turbocharger",
	"Hammerpoint Rounds",
	"Disruptor Rounds"
};
inline bool ammoAndHealsSelections[15];
inline const char* ammoAndHealsOptions[] =
{
	"Phoenix Kit",
	"Med Kit",
	"Syringe",
	"Shield Battery",
	"Shield Cell",
	"Thermite Grenade",
	"Frag Grenade",
	"Arc Star",
	"Light Rounds",
	"Energy Ammo",
	"Shotgun Shells",
	"Heavy Rounds",
	"Sniper Rounds",
	"Ultimate Accelerant",
	"Boost Loader",
	"Treasure Pack",
	"Vault Key",
	"Heat Shield",
	"Respawn Beacon",
	"Evac Tower",
};
inline bool medsOther[5];
inline const char* medsOptions[] =
{
	"Phoenix Kit",
	"Med Kit",
	"Syringe",
	"Shield Battery",
	"Shield Cell",
};
inline bool nadeOther[3];
inline const char* nadeOptions[] =
{
	"Thermite Grenade",
	"Frag Grenade",
	"Arc Star",
};
inline bool ammoOther[5];
inline const char* ammoOptions[] =
{
	"Light Rounds",
	"Energy Ammo",
	"Shotgun Shells",
	"Heavy Rounds",
	"Sniper Rounds",
};
inline bool miscOther[6];
inline const char* miscOptions[] =
{
	"Boost Loader",
	"Treasure Pack",
	"Vault Key",
	"Heat Shield",
	"Respawn Beacon",
	"Evac Tower",
};
inline bool armorSelections[21];
inline const char* armorOptions[] =
{
	"Helmet Level 1",
	"Helmet Level 2",
	"Helmet Level 3",
	"Helmet Level 4",
	"Body Armor Level 1",
	"Body Armor Level 2",
	"Body Armor Level 3",
	"Body Armor Level 4",
	"Evo Shield 1",
	"Evo Shield 2",
	"Evo Shield 3",
	"Evo Shield 4",
	"Evo Shield 5"
	"Knockdown Shield Level 1",
	"Knockdown Shield Level 2",
	"Knockdown Shield Level 3",
	"Knockdown Shield Level 4",
	"Backpack Level 1",
	"Backpack Level 2",
	"Backpack Level 3",
	"Backpack Level 4",
};
inline bool helmetArmor[4];
inline const char* helmetOptions[] =
{
	"Helmet Level 1",
	"Helmet Level 2",
	"Helmet Level 3",
	"Helmet Level 4",
};
inline bool bodyArmor[8];
inline const char* bodyOptions[] =
{
	"Body Armor Level 1",
	"Body Armor Level 2",
	"Body Armor Level 3",
	"Body Armor Level 4",
	"Evo Shield 1",
	"Evo Shield 2",
	"Evo Shield 3",
	"Evo Shield 4",
};
inline bool knochdownArmor[4];
inline const char* knockdownOptions[] =
{
	"Knockdown Shield Level 1",
	"Knockdown Shield Level 2",
	"Knockdown Shield Level 3",
	"Knockdown Shield Level 4",
};
inline bool backpackArmor[4];
inline const char* backpackOptions[] =
{
	"Backpack Level 1",
	"Backpack Level 2",
	"Backpack Level 3",
	"Backpack Level 4",
};

inline ImVec2 tranlateTextPos(ImVec2 targetpos, char* text)
{
	int length = strlen(text);
	return ImVec2(targetpos.x - length / 2 * 11, targetpos.y);
}
inline int AutoStrafeeKey, AutoStrafeeState;
namespace items {
	enum Rarity { Weapon, Ammo, Heals, Attachment, Armor, Grenade };

	struct c_prop {
		std::string item_name;
		Rarity m_rarity;
	};

	static inline std::map<uint32_t, c_prop> itemList = {
	{ 1, { "Kraber", Rarity::Weapon }},
	{ 2, { "Mastiff", Rarity::Weapon }},
	{ 7, { "LStar", Rarity::Weapon }},
	{ 13, { "Havoc", Rarity::Weapon }},
	{ 18, { "Devotion", Rarity::Weapon }},
	{ 23, { "Triple Take", Rarity::Weapon }},
	{ 28, { "Flatline", Rarity::Weapon }},
	{ 33, { "Hemlok", Rarity::Weapon }},
	{ 39, { "G7 Scout", Rarity::Weapon }},
	{ 44, { "Alternator", Rarity::Weapon }},
	{ 49, { "R99", Rarity::Weapon }},
	{ 55, { "Prowler", Rarity::Weapon }},
	{ 60, { "Volt", Rarity::Weapon }},
	{ 65, { "Longbow", Rarity::Weapon }},
	{ 70, { "Charge Rifle", Rarity::Weapon }},
	{ 75, { "Spitfire", Rarity::Weapon }},
	{ 80, { "R301", Rarity::Weapon }},
	{ 85, { "EVA-8 Auto", Rarity::Weapon }},
	{ 90, { "Peacekeeper", Rarity::Weapon }},
	{ 95, { "Mozambique", Rarity::Weapon }},
	{ 106, { "Wingman", Rarity::Weapon }},
	{ 111, { "P2020", Rarity::Weapon }},
	{ 116, { "RE-45", Rarity::Weapon }},
	{ 122, { "Sentinel", Rarity::Weapon }},
	{ 127, { "Bocek Bow", Rarity::Weapon }},
	{ 129, { "30-30 Repeater", Rarity::Weapon }},
	{ 135, { "Nemesis", Rarity::Weapon }},
	{ 146, { "Rampage", Rarity::Weapon }},
	{ 151, { "Car", Rarity::Weapon }},

	{ 140, { "Light Rounds", Rarity::Ammo }},
	{ 141, { "Energy Ammo", Rarity::Ammo }},
	{ 142, { "Shotgun Shells", Rarity::Ammo }},
	{ 143, { "Heavy Rounds", Rarity::Ammo }},
	{ 144, { "Sniper Rounds", Rarity::Ammo }},

	{ 182, { "Ultimate Accelerant", Rarity::Heals }},
	{ 183, { "Phoenix Kit", Rarity::Heals }},
	{ 184, { "Med Kit", Rarity::Heals }},
	{ 185, { "Syringe", Rarity::Heals }},
	{ 186, { "Shield Battery", Rarity::Heals }},
	{ 187, { "Shield Cell", Rarity::Heals }},

	{ 188, { "Helmet Level 1", Rarity::Armor }},
	{ 189, { "Helmet Level 2", Rarity::Armor }},
	{ 190, { "Helmet Level 3", Rarity::Armor }},
	{ 191, { "Helmet Level 4", Rarity::Armor }},

	{ 193, { "Body Armor Level 1", Rarity::Armor }},
	{ 194, { "Body Armor Level 2", Rarity::Armor }},
	{ 195, { "Body Armor Level 3", Rarity::Armor }},
	{ 196, { "Body Armor Level 4", Rarity::Armor }},

	{ 198, { "Evo Shield 1", Rarity::Armor }},
	{ 199, { "Evo Shield 2", Rarity::Armor }},
	{ 200, { "Evo Shield 3", Rarity::Armor }},
	{ 201, { "Evo Shield 4", Rarity::Armor }},

	{ 203, { "Knockdown Shield Level 1", Rarity::Armor }},
	{ 204, { "Knockdown Shield Level 2", Rarity::Armor }},
	{ 205, { "Knockdown Shield Level 3", Rarity::Armor }},
	{ 206, { "Knockdown Shield Level 4", Rarity::Armor }},

	{ 207, { "Backpack Level 1", Rarity::Armor }},
	{ 208, { "Backpack Level 2", Rarity::Armor }},
	{ 209, { "Backpack Level 3", Rarity::Armor }},
	{ 210, { "Backpack Level 4", Rarity::Armor }},

	{ 212, { "Thermite Grenade", Rarity::Grenade }},
	{ 213, { "Frag Grenade", Rarity::Grenade }},
	{ 214, { "Arc Star", Rarity::Grenade }},

	{ 215, { "1x HCOG (Classic)", Rarity::Attachment }},
	{ 216, { "2x HCOG (Bruiser)", Rarity::Attachment }},
	{ 217, { "1x Holo", Rarity::Attachment }},
	{ 218, { "1x-2x Variable Holo", Rarity::Attachment }},
	{ 219, { "1x Digital Threat", Rarity::Attachment }},
	{ 220, { "3x HCOG (Ranger)", Rarity::Attachment }},
	{ 221, { "2x-4x Variable AOG", Rarity::Attachment }},
	{ 222, { "6x Sniper", Rarity::Attachment }},
	{ 223, { "4x-8x Variable Sniper", Rarity::Attachment }},
	{ 224, { "4x-10x Digital Sniper Threat", Rarity::Attachment }},

	{ 225, { "Barrel Stabilizer Level 1", Rarity::Attachment }},
	{ 226, { "Barrel Stabilizer Level 2", Rarity::Attachment }},
	{ 227, { "Barrel Stabilizer Level 3", Rarity::Attachment }},

	{ 229, { "Laser Sight Level 1", Rarity::Attachment }},
	{ 230, { "Laser Sight Level 2", Rarity::Attachment }},
	{ 231, { "Laser Sight Level 3", Rarity::Attachment }},

	{ 232, { "Light Magazine Level 1", Rarity::Attachment }},
	{ 233, { "Light Magazine Level 2", Rarity::Attachment }},
	{ 234, { "Light Magazine Level 3", Rarity::Attachment }},
	{ 235, { "Light Magazine Level 4", Rarity::Attachment }},

	{ 236, { "Heavy Magazine Level 1", Rarity::Attachment }},
	{ 237, { "Heavy Magazine Level 2", Rarity::Attachment }},
	{ 238, { "Heavy Magazine Level 3", Rarity::Attachment }},
	{ 239, { "Heavy Magazine Level 4", Rarity::Attachment }},

	{ 240, { "Energy Magazine Level 1", Rarity::Attachment }},
	{ 241, { "Energy Magazine Level 2", Rarity::Attachment }},
	{ 242, { "Energy Magazine Level 3", Rarity::Attachment }},
	{ 243, { "Energy Magazine Level 4", Rarity::Attachment }},

	{ 244, { "Sniper Magazine Level 1", Rarity::Attachment }},
	{ 245, { "Sniper Magazine Level 2", Rarity::Attachment }},
	{ 246, { "Sniper Magazine Level 3", Rarity::Attachment }},
	{ 247, { "Sniper Magazine Level 4", Rarity::Attachment }},

	{ 248, { "Shotgun Bolt Level 1", Rarity::Attachment }},
	{ 249, { "Shotgun Bolt Level 2", Rarity::Attachment }},
	{ 250, { "Shotgun Bolt Level 3", Rarity::Attachment }},
	{ 251, { "Shotgun Bolt Level 4", Rarity::Attachment }},

	{ 252, { "Standard Stock Level 1", Rarity::Attachment }},
	{ 253, { "Standard Stock Level 2", Rarity::Attachment }},
	{ 254, { "Standard Stock Level 3", Rarity::Attachment }},

	{ 255, { "Sniper Stock Level 1", Rarity::Attachment }},
	{ 256, { "Sniper Stock Level 2", Rarity::Attachment }},
	{ 257, { "Sniper Stock Level 3", Rarity::Attachment }},

	{ 258, { "Turbocharger", Rarity::Attachment }},
	{ 272, { "Hammerpoint Rounds", Rarity::Attachment }},
	{ 271, { "Disruptor Rounds", Rarity::Attachment }},
	{ 273, { "Boost Loader", Rarity::Heals }},
	{ 277, { "Treasure Pack", Rarity::Heals }},
	{ 283, { "Vault Key", Rarity::Heals }},
	{ 22, { "Heat Shield", Rarity::Heals }},
	{ 23, { "Respawn Beacon", Rarity::Heals }},
	{ 26, { "Evac Tower", Rarity::Heals }}
	};
}
class PlayerEnt
{
public:
	uintptr_t address = NULL;
	int level = 0;
	int bleedoutSate = 0;
	Vector3 position = { 0, 0, 0 };
	Vector3 camPos = { 0, 0, 0 };
	int teamNumber = 0;
	int health = 0;
	int maxHealth = 0;
	int shield = 0;
	int maxShield = 0;
	int shieldType = 0;
	std::string name = "";
	std::string modelName = "";
	float lastVisTime = 0;

	inline PlayerEnt(uintptr_t address)
	{
		this->address = address;
		if (this->address == NULL)
			return;
		this->level = this->GetPlayerLevel();
		this->bleedoutSate = this->getBleedoutSate();
		this->position = this->getPosition();
		this->camPos = this->getCamPos();
		this->teamNumber = this->getTeamNumber();
		this->health = this->getHealth();
		this->maxHealth = this->getMaxHealth();
		this->shield = this->getShield();
		this->maxShield = this->getMaxShield();
		this->shieldType = this->getShieldType();
		this->name = this->getName();
		this->modelName = this->getModelName();
		this->lastVisTime = this->getLastVisTime();
	}
	inline PlayerEnt()
	{
		this->address = read<uintptr_t>(GameAddress + offsets::LocalPlayer);
		if (this->address == NULL)
		{
			this->address = NULL;
			return;
		}
		this->level = this->GetPlayerLevel();
		this->bleedoutSate = this->getBleedoutSate();
		this->position = this->getPosition();
		this->camPos = this->getCamPos();
		this->teamNumber = this->getTeamNumber();
		this->health = this->getHealth();
		this->maxHealth = this->getMaxHealth();
		this->shield = this->getShield();
		this->maxShield = this->getMaxShield();
		this->shieldType = this->getShieldType();
		this->name = this->getName();
	}
	inline bool isVisable()
	{
		bool isVis;
		float time = read<float>(this->address + offsets::lastVisableTime);

		if (time > this->lastVisTime)
			isVis = true;
		else
			isVis = false;

		this->lastVisTime = time;

		return isVis;
	}
	inline int GetPlayerLevel()
	{
		int m_xp = read<int>(address + offsets::m_xp); //m_xp
		if (m_xp < 0) return 0;
		if (m_xp < 100) return 1;

		int levels[] = { 2750, 6650, 11400, 17000, 23350, 30450, 38300, 46450, 55050, 64100, 73600, 83550, 93950, 104800, 116100, 127850, 140050, 152400, 164900, 177550, 190350, 203300, 216400, 229650, 243050, 256600, 270300, 284150, 298150, 312300, 326600, 341050, 355650, 370400, 385300, 400350, 415550, 430900, 446400, 462050, 477850, 493800, 509900, 526150, 542550, 559100, 575800, 592650, 609650, 626800, 644100, 661550, 679150, 696900, 714800 };

		int level = 56;
		int arraySize = sizeof(levels) / sizeof(levels[0]);

		for (int i = 0; i < arraySize; i++)
		{
			if (m_xp < levels[i])
			{
				return i + 1;
			}
		}

		return level + ((m_xp - levels[arraySize - 1] + 1) / 18000);
	}
	inline int getBleedoutSate()
	{
		return read<int>(address + offsets::m_bleedoutState);
	}
	inline Vector3 getPosition()
	{
		return  read<Vector3>(address + offsets::VecAbs);
	}
	inline Vector3 getBonePos(int id)
	{
		Vector3 pos = read<Vector3>(address + offsets::VecAbs); //PoopSets::M_VecAbsOrigin
		uintptr_t bones = read<uintptr_t>(address + 0x0dd0 + 0x48); //PoopSets::demfuckingBone
		Vector3 bone = {};
		UINT32 boneloc = (id * 0x30);
		bone_t bo = {};
		bo = read<bone_t>(bones + boneloc);

		bone.x = bo.x + pos.x;
		bone.y = bo.y + pos.y;
		bone.z = bo.z + pos.z;
		return bone;
	}
	inline Vector3 getBonePositionByHitbox(int id)
	{
		Vector3 origin = read<Vector3>(address + offsets::VecAbs);

		//BoneByHitBox
		uint64_t Model = *(uint64_t*)(address + offsets::m_pStudioHdr);

		//get studio hdr
		uint64_t StudioHdr = read<uint64_t>(Model + 0x8);

		//get hitbox array
		uint16_t HitboxCache = read<uint16_t>(StudioHdr + 0x34);
		uint64_t HitBoxsArray = StudioHdr + ((uint16_t)(HitboxCache & 0xFFFE) << (4 * (HitboxCache & 1)));

		uint16_t IndexCache = read<uint16_t>(HitBoxsArray + 0x4);
		int HitboxIndex = ((uint16_t)(IndexCache & 0xFFFE) << (4 * (IndexCache & 1)));

		uint16_t Bone = read<uint16_t>(HitBoxsArray + HitboxIndex + (id * 0x20));

		if (Bone < 0 || Bone > 255)
			return Vector3();

		//hitpos
		uint64_t BoneArray = *(uint64_t*)(address + 0x0dd0 + 0x48);

		matrix3x4_t Matrix = read<matrix3x4_t>(BoneArray + Bone * sizeof(matrix3x4_t));

		return Vector3(Matrix.m_flMatVal[0][3] + origin.x, Matrix.m_flMatVal[1][3] + origin.y, Matrix.m_flMatVal[2][3] + origin.z);
	}
	inline Vector3 getCamPos() {
		return read<Vector3>(address + offsets::camera_origin);
	}
	inline Vector2 getAngles() {
		Vector2 angles;
		angles.x = read<float>(address + offsets::viewAngles + sizeof(float));
		angles.y = read<float>(address + offsets::viewAngles);
		return angles;
	}
	inline float GetWeaponBulletSpeeds() {

		uint64_t entitylist = read<uint64_t>(GameAddress + offsets::EntityList);
		uint64_t wephandle = read<uint64_t>(address + offsets::m_latestPrimaryWeapons  /*active weapon*/);

		wephandle &= 0xffff;

		uint64_t wep_entity = read<uint64_t>(entitylist + (wephandle << 5));

		auto projectileSpeed = read<float>(wep_entity + (0x1AA0 + offsets::projectile_inherit_base_velocity_scale));

		return projectileSpeed;
	}
	inline std::string getWeaponName()
	{
		uint64_t entitylist = read<uint64_t>(GameAddress + offsets::EntityList);
		uint64_t wephandle = read<uint64_t>(address + offsets::m_latestPrimaryWeapons  /*active weapon*/);

		wephandle &= 0xffff;

		uint64_t wep_entity = read<uint64_t>(entitylist + (wephandle << 5));
		if (wep_entity == 0)
			return "";
		uintptr_t pMode_Name = read<uintptr_t>(wep_entity + offsets::m_ModelName);
		char* modelName = reinterpret_cast<char*>(pMode_Name);
		std::string s(modelName);
		return s;

	}
	inline int getTeamNumber()
	{
		return read<int>(address + offsets::m_iTeamNum);
	}
	inline int getHealth()
	{
		return read<int>(address + offsets::m_iHealth);
	}
	inline int getMaxHealth()
	{
		return read<int>(address + offsets::m_iMaxHealth);
	}
	inline int getShield()
	{
		return read<int>(address + offsets::m_shieldHealth);
	}
	inline int getMaxShield()
	{
		return read<int>(address + offsets::m_shieldHealthMax);
	}
	inline int getShieldType()
	{
		return read<int>(address + offsets::m_armorType);
	}
	inline std::string getModelName()
	{
		uintptr_t pMode_Name = read<uintptr_t>(address + offsets::m_ModelName);
		char* modelName = reinterpret_cast<char*>(pMode_Name);
		std::string s(modelName);
		return s;
	}
	inline std::string getSignifierName()
	{
		uintptr_t sigAddr = read<uintptr_t>(address + offsets::m_iSignifierName);
		if (sigAddr == 0)
			return "";

		char* sig = reinterpret_cast<char*>(sigAddr);
		std::string s = std::string(sig);

		return s;
	}
	inline std::string getName()
	{
		for (int i = 0; i < 150; i++)
		{
			uintptr_t EntityList = GameAddress + offsets::EntityList;
			uintptr_t BaseEntity = read<DWORD64>(EntityList);
			if (!BaseEntity)
				continue;
			uintptr_t ent = read<uintptr_t>(EntityList + (i << 5));
			if (ent == NULL)
				continue;

			if (address == ent)
			{
				uintptr_t nameptr = read<uintptr_t>(GameAddress + offsets::NameList + (i - 1) * 0x10);
				if (!nameptr) continue;

				char* name = reinterpret_cast<char*>(nameptr);
				std::string s(name);
				return s;
			}
		}
		return "";
	}
	inline void setVa(Vector2 va)
	{
		write<Vector2>((uintptr_t)(address + offsets::viewAngles), va);
	}
	inline void SetSkin(int SkinIndex)
	{
		DWORD64 LastWeapon = read<DWORD64>(address + offsets::m_latestPrimaryWeapons) & 0xFFFF; // current weapon
		DWORD64 Weapon = read<DWORD64>(GameAddress + offsets::EntityList + (LastWeapon << 5));
		write<int>(Weapon + 0x0d88, SkinIndex);
	}
	inline float getLastVisTime()
	{
		return read<float>(this->address + offsets::lastVisableTime);
	}
};


class Loot
{
public:
	uintptr_t address;
	Vector3 position;
	int id;
	inline Loot(uintptr_t address)
	{
		this->address = address;
		this->position = this->getPosition();
		this->id = this->getId();
	}
	inline std::string getSignifierName()
	{
		uintptr_t sigAddr = read<uintptr_t>(address + offsets::m_iSignifierName);
		if (sigAddr == 0)
			return "";

		char* sig = reinterpret_cast<char*>(sigAddr);
		std::string s = std::string(sig);

		return s;
	}
	inline Vector3 getPosition()
	{
		return  read<Vector3>(address + offsets::VecAbs);
	}
	inline int getId()
	{
		return read<int>(address + offsets::m_customScriptInt);
	}
	inline bool isSelected()
	{
		auto item = items::itemList[getId()];
		if (item.m_rarity == items::Rarity::Weapon)
		{
			for (int i = 0; i < IM_ARRAYSIZE(lightOptions); i++)
			{
				if (item.item_name == lightOptions[i])
					if (lightWeapons[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(heavyOptions); i++)
			{
				if (item.item_name == heavyOptions[i])
					if (heavyWeapons[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(sniperOptions); i++)
			{
				if (item.item_name == sniperOptions[i])
					if (sniperWeapons[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(shotgunOptions); i++)
			{
				if (item.item_name == shotgunOptions[i])
					if (shotgunWeapons[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(energyOptions); i++)
			{
				if (item.item_name == energyOptions[i])
					if (energyWeapons[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(specialOptions); i++)
			{
				if (item.item_name == specialOptions[i])
					if (specialWeapons[i])
						return true;
			}
		}


		else if (item.m_rarity == items::Rarity::Attachment)
		{
			for (int i = 0; i < IM_ARRAYSIZE(opticOptions); i++)
			{
				if (item.item_name == opticOptions[i])
					if (opticAttachments[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(magazineOptions); i++)
			{
				if (item.item_name == magazineOptions[i])
					if (magazineAttachments[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(stabilizerOptions); i++)
			{
				if (item.item_name == stabilizerOptions[i])
					if (stabilizerAttachments[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(stockOptions); i++)
			{
				if (item.item_name == stockOptions[i])
					if (stockAttachments[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(hopOptions); i++)
			{
				if (item.item_name == hopOptions[i])
					if (hopAttachments[i])
						return true;
			}
		}


		else if (item.m_rarity == items::Rarity::Armor)
		{
			for (int i = 0; i < IM_ARRAYSIZE(helmetOptions); i++)
			{
				if (item.item_name == helmetOptions[i])
					if (helmetArmor[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(bodyOptions); i++)
			{
				if (item.item_name == bodyOptions[i])
					if (bodyArmor[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(knockdownOptions); i++)
			{
				if (item.item_name == knockdownOptions[i])
					if (knochdownArmor[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(backpackOptions); i++)
			{
				if (item.item_name == backpackOptions[i])
					if (backpackArmor[i])
						return true;
			}
		}


		else if (item.m_rarity == items::Rarity::Grenade || item.m_rarity == items::Rarity::Ammo || items::Rarity::Heals)
		{
			for (int i = 0; i < IM_ARRAYSIZE(medsOptions); i++)
			{
				if (item.item_name == medsOptions[i])
					if (medsOther[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(nadeOptions); i++)
			{
				if (item.item_name == nadeOptions[i])
					if (nadeOther[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(ammoOptions); i++)
			{
				if (item.item_name == ammoOptions[i])
					if (ammoOther[i])
						return true;
			}
			for (int i = 0; i < IM_ARRAYSIZE(miscOptions); i++)
			{
				if (item.item_name == miscOptions[i])
					if (miscOther[i])
						return true;
			}
		}
		return false;
	}
};

struct entityList
{
	std::vector<PlayerEnt> playerList;
	std::vector<Loot> lootList;
};

inline entityList getPlayerList()
{
	entityList lists;

	PlayerEnt localPlayer = PlayerEnt();
	for (int i = 0; i < 15000; i++)
	{
		// Getting current entity
		uintptr_t EntityList = GameAddress + offsets::EntityList;
		uintptr_t BaseEntity = read<DWORD64>(EntityList);
		if (!BaseEntity)
			continue;
		uintptr_t ent = read<uintptr_t>(EntityList + (i << 5));
		if (ent == NULL)
			continue;
		//getting signifier 
		uintptr_t sigAddr = read<uintptr_t>(ent + offsets::m_iSignifierName);
		if (sigAddr == 0)
			continue;

		char* sig = reinterpret_cast<char*>(sigAddr);
		std::string s = std::string(sig);

		// caching entity or loot item
		if (s == "player" || s == "npc_dummie")
		{
			PlayerEnt curEnt(ent);
			if ((localPlayer.address != curEnt.address && calcDist(curEnt.position, localPlayer.position) / 20 < maxDistance))
				lists.playerList.push_back(curEnt);
		}
		else if (s == "prop_survival" || s == "prop_death_box" && calcDist(read<Vector3>(ent + offsets::VecAbs), localPlayer.position) / 20 < maxLootDist)
		{
			lists.lootList.push_back(Loot(ent));
		}
	}

	return lists;
}


inline void draw_text_outline_font(float x, float y, ImColor color, const char* string, ImFont* Font, bool cetered = true) {
	char buf[512];
	va_list arg_list;
	ImGui::PushFont(Font);
	ImVec2 len = cetered ? ImGui::CalcTextSize(string) : ImVec2(0, 0);
	ImGui::PopFont();

	ImGui::GetForegroundDrawList()->PFontText(Font, 12, ImVec2(x - .3 - len.x / 2, y - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);
	ImGui::GetForegroundDrawList()->PFontText(Font, 12, ImVec2(x + .3 - len.x / 2, y - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);
	ImGui::GetForegroundDrawList()->PFontText(Font, 12, ImVec2(x - len.x / 2, y - .3 - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);
	ImGui::GetForegroundDrawList()->PFontText(Font, 12, ImVec2(x - len.x / 2, y + .3 - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);

	ImGui::GetForegroundDrawList()->PFontText(Font, 12, ImVec2(x - len.x / 2, y - len.y / 2), color, string);
	return;
}
inline void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness)
{
	float lineW = (W / 3);
	float lineH = (H / 3);

	////black outlines
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}
inline void AddHexagon(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col, float thickness)
{
	if ((col & IM_COL32_A_MASK) == 0)
		return;

	ImGui::GetBackgroundDrawList()->PathLineTo(p1);
	ImGui::GetBackgroundDrawList()->PathLineTo(p2);
	ImGui::GetBackgroundDrawList()->PathLineTo(p3);
	ImGui::GetBackgroundDrawList()->PathLineTo(p4);
	ImGui::GetBackgroundDrawList()->PathLineTo(p5);
	ImGui::GetBackgroundDrawList()->PathLineTo(p6);

	ImGui::GetBackgroundDrawList()->PathStroke(col, true, thickness);
}
inline void AddHexagonFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col)
{
	if ((col & IM_COL32_A_MASK) == 0)
		return;

	ImGui::GetBackgroundDrawList()->PathLineTo(p1);
	ImGui::GetBackgroundDrawList()->PathLineTo(p2);
	ImGui::GetBackgroundDrawList()->PathLineTo(p3);
	ImGui::GetBackgroundDrawList()->PathLineTo(p4);
	ImGui::GetBackgroundDrawList()->PathLineTo(p5);
	ImGui::GetBackgroundDrawList()->PathLineTo(p6);
	ImGui::GetBackgroundDrawList()->PathFillConvex(col);
}
inline void DrawQuadFilled(ImVec2 p1, ImVec2 p2, ImVec2 p3, ImVec2 p4, ImColor color) {
	ImGui::GetBackgroundDrawList()->AddQuadFilled(p1, p2, p3, p4, color);
}
inline void DrawHexagon(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col, float thickness)
{
	AddHexagon(p1, p2, p3, p4, p5, p6, col, thickness);
}
inline void DrawHexagonFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col)
{
	AddHexagonFilled(p1, p2, p3, p4, p5, p6, col);
}
inline int atest, btest;
inline void SeerHealth(float x, float y, int shield, int max_shield, int armorType, int health) {

	int bg_offset = 3;
	int bar_width = 158;
	// 4steps...2*3=6
	// 38*4=152 152+6 = 158
	// 5steps...2*4=8
	// 30*5=150 150+8 = 158
	float max_health = 100.0f;
	float shield_step = 25.0f;

	int shield_25 = 30;
	int steps = 5;

	ImVec2 bg1(x - bar_width / 2 - bg_offset, y);
	ImVec2 bg2(bg1.x - 10, bg1.y - 16);
	ImVec2 bg3(bg2.x + 5, bg2.y - 7);
	ImVec2 bg4(bg3.x + bar_width + bg_offset, bg3.y);
	ImVec2 bg5(bg4.x + 11, bg4.y + 18);
	ImVec2 bg6(x + bar_width / 2 + bg_offset, y);
	DrawHexagonFilled(bg1, bg2, bg3, bg4, bg5, bg6, ImColor(0, 0, 0, 140));

	ImVec2 h1(bg1.x + 3, bg1.y - 4);
	ImVec2 h2(h1.x - 5, h1.y - 8);
	ImVec2 h3(h2.x + (float)health / max_health * bar_width, h2.y);
	ImVec2 h4(h1.x + (float)health / max_health * bar_width, h1.y);
	ImVec2 h3m(h2.x + bar_width, h2.y);
	ImVec2 h4m(h1.x + bar_width, h1.y);
	DrawQuadFilled(h1, h2, h3m, h4m, ImColor(10, 10, 30, 60));
	DrawQuadFilled(h1, h2, h3, h4, ImColor(255, 255, 255, 255));


	ImColor shieldCracked(97, 97, 97);
	ImColor shieldCrackedDark(67, 67, 67);

	ImColor shieldCol;
	ImColor shieldColDark; //not used, but the real seer q has shadow inside
	if (armorType == 1) { //white
		shieldCol = ImColor(247, 247, 247);
		shieldColDark = ImColor(164, 164, 164);
	}
	else if (armorType == 2) { //blue
		shieldCol = ImColor(39, 178, 255);
		shieldColDark = ImColor(27, 120, 210);
	}
	else if (armorType == 3) { //purple
		shieldCol = ImColor(206, 59, 255);
		shieldColDark = ImColor(136, 36, 220);
	}
	else if (armorType == 4) { //gold
		shieldCol = ImColor(255, 255, 79);
		shieldColDark = ImColor(218, 175, 49);
	}
	else if (armorType == 5) { //red
		shieldCol = ImColor(219, 2, 2);
		shieldColDark = ImColor(219, 2, 2);
	}
	else {
		shieldCol = ImColor(247, 247, 247);
		shieldColDark = ImColor(164, 164, 164);
	}
	int shield_tmp = shield;
	int shield1 = 0;
	int shield2 = 0;
	int shield3 = 0;
	int shield4 = 0;
	int shield5 = 0;
	if (shield_tmp > 25) {
		shield1 = 25;
		shield_tmp -= 25;
		if (shield_tmp > 25) {
			shield2 = 25;
			shield_tmp -= 25;
			if (shield_tmp > 25) {
				shield3 = 25;
				shield_tmp -= 25;
				if (shield_tmp > 25) {
					shield4 = 25;
					shield_tmp -= 25;
					shield5 = shield_tmp;
				}
				else {
					shield4 = shield_tmp;
				}
			}
			else {
				shield3 = shield_tmp;
			}
		}
		else {
			shield2 = shield_tmp;
		}
	}
	else {
		shield1 = shield_tmp;
	}
	ImVec2 s1(h2.x - 1, h2.y - 2);
	ImVec2 s2(s1.x - 3, s1.y - 5);
	ImVec2 s3(s2.x + shield1 / shield_step * shield_25, s2.y);
	ImVec2 s4(s1.x + shield1 / shield_step * shield_25, s1.y);
	ImVec2 s3m(s2.x + shield_25, s2.y);
	ImVec2 s4m(s1.x + shield_25, s1.y);

	ImVec2 ss1(s4m.x + 2, s1.y);
	ImVec2 ss2(s3m.x + 2, s2.y);
	ImVec2 ss3(ss2.x + shield2 / shield_step * shield_25, s2.y);
	ImVec2 ss4(ss1.x + shield2 / shield_step * shield_25, s1.y);
	ImVec2 ss3m(ss2.x + shield_25, s2.y);
	ImVec2 ss4m(ss1.x + shield_25, s1.y);

	ImVec2 sss1(ss4m.x + 2, s1.y);
	ImVec2 sss2(ss3m.x + 2, s2.y);
	ImVec2 sss3(sss2.x + shield3 / shield_step * shield_25, s2.y);
	ImVec2 sss4(sss1.x + shield3 / shield_step * shield_25, s1.y);
	ImVec2 sss3m(sss2.x + shield_25, s2.y);
	ImVec2 sss4m(sss1.x + shield_25, s1.y);

	ImVec2 ssss1(sss4m.x + 2, s1.y);
	ImVec2 ssss2(sss3m.x + 2, s2.y);
	ImVec2 ssss3(ssss2.x + shield4 / shield_step * shield_25, s2.y);
	ImVec2 ssss4(ssss1.x + shield4 / shield_step * shield_25, s1.y);
	ImVec2 ssss3m(ssss2.x + shield_25, s2.y);
	ImVec2 ssss4m(ssss1.x + shield_25, s1.y);

	ImVec2 sssss1(ssss4m.x + 2, s1.y);
	ImVec2 sssss2(ssss3m.x + 2, s2.y);
	ImVec2 sssss3(sssss2.x + shield5 / shield_step * shield_25, s2.y);
	ImVec2 sssss4(sssss1.x + shield5 / shield_step * shield_25, s1.y);
	ImVec2 sssss3m(sssss2.x + shield_25, s2.y);
	ImVec2 sssss4m(sssss1.x + shield_25, s1.y);
	if (max_shield == 50) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield != 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
	}
	else if (max_shield == 75) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
	}
	else if (max_shield == 100) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
		else if (shield <= 100) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			if (shield < 100) {
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
		}
	}
	else if (max_shield == 125) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
		else if (shield <= 100) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			if (shield < 100) {
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
		}
		else if (shield <= 125) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
			if (shield < 125) {
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sssss1, sssss2, sssss3, sssss4, shieldCol);
		}
	}
}
inline bool SkinChange;
inline int skinId;

inline void DrawBox(ImVec2 headPos, ImVec2 pos, const ImU32 color, int thickness) {
	int dist = pos.y - headPos.y;
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(headPos.x - dist / 4, headPos.y), ImVec2(headPos.x + dist / 4, headPos.y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(headPos.x + dist / 4, headPos.y), ImVec2(pos.x + dist / 4, pos.y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pos.x + dist / 4, pos.y), ImVec2(pos.x - dist / 4, pos.y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pos.x - dist / 4, pos.y), ImVec2(headPos.x - dist / 4, headPos.y), color, thickness);
}



inline bool autostraf = false;
//inline void draw_text_outline(float x, float y, ImColor color, const char* string, ...) {
//	char buf[512];
//	va_list arg_list;
//
//	ZeroMemory(buf, sizeof(buf));
//
//	va_start(arg_list, string);
//	vsnprintf(buf, sizeof(buf), string, arg_list);
//	va_end(arg_list);
//
//	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x - 1, y), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
//	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x + 1, y), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
//	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x, y - 1), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
//	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x, y + 1), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
//
//	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x, y), color, buf, 0, 0, 0);
//	return;
//}

inline int bloodhoundBones[] = { 0, 1, 2, 4, -5, 1, 6, 7, 19, -5, 1, 8, 9, 10, -5, 4, 11, 12, 13, 14, -5, 4, 15, 16, 17, 18 };
inline int regualrBones[] = { 0, 1, 3, 4, -5, 1, 6, 7, 8, -5, 1, 9, 10, 11, -5, 4, 12, 13, 14, 15, -5, 4, 16, 17, 18, 19 };
inline void boneEsp(PlayerEnt entity)
{
	for (int i = 1; i < 26; i++)
	{
		//intptr_t pMode_Name = read<uintptr_t>(entity.address + offsets::m_ModelName);
		//char* modelName = reinterpret_cast<char*>(pMode_Name);
		//std::string s(modelName);

		if (entity.modelName.find("bloodhound") != -1)
		{
			if (bloodhoundBones[i] == -5)
			{
				i++;
				continue;
			}

			Vector3 first = entity.getBonePositionByHitbox(bloodhoundBones[i - 1]).ProjectWorldToScreen(); //getBonePositionByHitbox(entity, bloodhoundBones[i - 1]);
			//first = ProjectWorldToScreen(first);
			if (first.Empty()) continue;

			Vector3 last = entity.getBonePositionByHitbox(bloodhoundBones[i]).ProjectWorldToScreen();//getBonePositionByHitbox(entity, bloodhoundBones[i]);
			//last = ProjectWorldToScreen(last);
			if (last.Empty()) continue;

			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x, first.y), ImVec2(last.x, last.y), ImColor(skeletonCol[0], skeletonCol[1], skeletonCol[2]), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x - 1, first.y), ImVec2(last.x - 1, last.y), ImColor(0, 0, 0), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x + 1, first.y), ImVec2(last.x + 1, last.y), ImColor(0, 0, 0), 1);
		}
		else
		{
			if (regualrBones[i] == -5)
			{
				i++;
				continue;
			}
			Vector3 first = entity.getBonePositionByHitbox(regualrBones[i - 1]).ProjectWorldToScreen();
			//first = ProjectWorldToScreen(first);
			if (first.Empty()) continue;

			Vector3 last = entity.getBonePositionByHitbox(regualrBones[i]).ProjectWorldToScreen();
			//last = ProjectWorldToScreen(last);
			if (first.Empty()) continue;
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x, first.y), ImVec2(last.x, last.y), ImColor(skeletonCol[0], skeletonCol[1], skeletonCol[2]), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x - 1, first.y), ImVec2(last.x - 1, last.y), ImColor(0, 0, 0), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x + 1, first.y), ImVec2(last.x + 1, last.y), ImColor(0, 0, 0), 1);
		}
	}

}

inline bool Skeleton = false;
inline PlayerEnt GetBestOp(PlayerEnt local, float fovs, int& index, entityList ents) {
	float closest = INT_MAX;
	PlayerEnt bestEnt = 0;
	for (int i = 0; i < ents.playerList.size(); i++) {
		PlayerEnt curEnt = ents.playerList.at(i);//GetEntityById(i);

		//if (bVisCheck && !isVisable(Entity, i)) continue;
		float distance = calcDist(curEnt.position, local.position);
		if ((distance / 20) > maxDistance) continue;
		Vector3 Head2d = curEnt.getBonePos(BoneList::Head).ProjectWorldToScreen(); //ProjectWorldToScreen(GetBonePos(Entity, BoneList::Head));
		if (Head2d.Empty()) continue;
		float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head2d.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head2d.y, 2));

		if (length < closest && length <= (fovs * 3)) {
			closest = length;
			bestEnt = curEnt;
			index = i;
		}
	}
	return bestEnt;
}
inline PlayerEnt getBestEnt(PlayerEnt local, entityList ents) {
	float closest = INT_MAX;
	PlayerEnt bestEnt = 0;
	for (int i = 0; i < ents.playerList.size(); i++) {
		PlayerEnt curEnt = ents.playerList.at(i);


		if (!curEnt.isVisable() && bVisCheck) continue;
		float distance = calcDist(curEnt.position, local.position);
		if ((distance / 20) > maxDistance) continue;
		if ((distance / 20) > aimbotDist) continue;
		Vector3 Head2d = curEnt.getBonePos(BoneList::Head).ProjectWorldToScreen();//ProjectWorldToScreen(GetBonePos(Entity, BoneList::Head));
		if (Head2d.Empty()) continue;
		float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head2d.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head2d.y, 2));

		if (length < closest && length <= (fov * 3)) {
			closest = length;
			bestEnt = curEnt;
		}
	}
	return bestEnt;
}

inline Vector2 getAngles(PlayerEnt local) {
	Vector2 angles;
	angles.x = read<float>(local.address + offsets::viewAngles + sizeof(float));
	angles.y = read<float>(local.address + offsets::viewAngles);
	return angles;
}

inline int smothing = 1;
inline float previousPitch = 0;
inline float previousYaw = 0;
inline PlayerEnt TriggerEnt(PlayerEnt local, float size, float& bonedistane, entityList ents) {
	float closest = INT_MAX;
	PlayerEnt bestEnt = 0;
	for (int i = 0; i < ents.playerList.size(); i++) {
		PlayerEnt curEnt = ents.playerList.at(i);//GetEntityById(i);

		Vector3 HitBoxTarget;
		float distance = calcDist(curEnt.position, local.position);
		if ((distance / 20) > maxDistance) continue;
		if ((distance / 20) > aimbotDist) continue;
		bonedistane = distance;
		Vector3 w2s;
		int targetBone;
		if (hitbox == 0)
		{
			targetBone = BoneList::Head;
		}
		else if (hitbox == 1) {
			targetBone = BoneList::Neck;
		}
		else {
			targetBone = BoneList::Pelivs;
		}
		Vector3 tPos = curEnt.getBonePos(targetBone).ProjectWorldToScreen();//GetBonePos(Entity, targetBone);
		auto v1 = tPos.ProjectWorldToScreen();
		if (v1.Empty()) continue;
		float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - v1.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - v1.y, 2));

		if (length < closest&& length <= (size)) {
			closest = length;
			ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(v1.x, v1.y), 5, ImColor(255, 0, 0, 255));

			bestEnt = curEnt;
		}
	}
	return bestEnt;
}
inline bool IsInCrossHair(DWORD64 Address) {
	auto tmp_lastCrosshairTargetTime = read<float>(Address + offsets::OFFSET_CROSSHAIR_LAST);
	float LastCrossHair = read<float>(Address + offsets::OFFSET_CROSSHAIR_LAST);
	auto iter = LastCrossHair;
	if (!iter)return false;
	if (iter == -1.f) {
		iter = tmp_lastCrosshairTargetTime;
		return false;
	}
	auto isCrosshair = tmp_lastCrosshairTargetTime > iter;
	iter = tmp_lastCrosshairTargetTime;
	return isCrosshair;
}
inline void triggerbot(entityList ents)
{
	{
		if (bTrigger)
		{
			PlayerEnt localPlayer = PlayerEnt(); //read<uintptr_t>(GameAddress + offsets::LocalPlayer);
			if (GetAsyncKeyState(triggerKey))
			{
				float increments = 10.0f;
				float distance;

				float closest = INT_MAX;
				//PlayerEnt bestEnt = 0;
				for (int i = 0; i < ents.playerList.size(); i++) {
					PlayerEnt curEnt = ents.playerList.at(i);//GetEntityById(i);

					Vector3 HitBoxTarget;
					float distancea = calcDist(curEnt.position, localPlayer.position);
					distance = (distancea / 20);
					if ((distance / 20) > maxDistance) continue;
					if ((distance / 20) > aimbotDist) continue;
					if (distance < 50.0f)
					{
						increments = 22.0f;
					}
					if (distance > 50.0f && distance < 100.0f)
					{
						increments = 18.0f;
					}
					if (distance > 100.0f && distance < 500.0f)
					{
						increments = 12.0f;
					}

					Vector3 w2s;
					int targetBone;
					if (hitbox == 0)
					{
						targetBone = BoneList::Head;
					}
					else if (hitbox == 1) {
						targetBone = BoneList::Neck;
					}
					else {
						targetBone = BoneList::Pelivs;
					}
					Vector3 tPos = curEnt.getBonePos(targetBone);//GetBonePos(Entity, targetBone);
					auto v1 = tPos.ProjectWorldToScreen();
					if (v1.Empty()) return;

					float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - v1.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - v1.y, 2));
					if (length < closest && length <= (increments)) {
						closest = length;
						//ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(v1.x, v1.y), 5, ImColor(255, 0, 0, 255));
						if (!GetAsyncKeyState(0x01))
						{
							//draw_text_outline_font(GetSystemMetrics(0) / 2, (GetSystemMetrics(1) / 2) + 15, ImColor(255, 0, 0, 255), "[ F i r i n g ]", esp_font);
							if (GetAsyncKeyState(triggerKey))
							{
								//draw_text_outline_font(GetSystemMetrics(0) / 2, (GetSystemMetrics(1) / 2) + 15, ImColor(255, 0, 0, 255), "[ F i r i n g ]", esp_font);

								keybd_event(0x01, MapVirtualKey(0x01, 0), 0, 0);
								Sleep(1);
								keybd_event(0x01, MapVirtualKey(0x01, 0), KEYEVENTF_KEYUP, 0);
								Sleep(1);
							}
							else {
								keybd_event(0x01, MapVirtualKey(0x01, 0), KEYEVENTF_KEYUP, 0);
								Sleep(1);
							}
						}
					}
				}
			}
		}
	}

}
inline void noRecoil() {
	uintptr_t localPlayer = read<DWORD64>(GameAddress + offsets::LocalPlayer);
	if (localPlayer != NULL) {
		Vector2 angles;
		angles.y = read<float>(localPlayer + offsets::viewAngles); //works
		angles.x = read<float>(localPlayer + offsets::viewAngles + sizeof(float)); // works
		Vector2 punch = read<Vector2>(localPlayer + offsets::punchAngle);
		if (punch.y < 0 || punch.x < 0) {
			angles.x -= (punch.y - previousYaw) * yawSTR;
			angles.y -= (punch.x - previousPitch) * pitchSTR;
			//NormalizeAngles(angles);
			write<float>(localPlayer + offsets::viewAngles, angles.y);
			write<float>(localPlayer + offsets::viewAngles + sizeof(float), angles.x);
			previousPitch = punch.x;
			previousYaw = punch.y;
		}
	}
}
//inline Vector3 CalcAnglePredictives(Vector3 src, Vector3 dst, uintptr_t targetEntity, uintptr_t local)
//{
//	Vector3 Velocity = read<Vector3>(targetEntity + offsets::m_vecAbsVelocity);
//	float bullet_vel = GetWeaponBulletSpeeds(local);
//	float dist = VAR_deltaDistances(src, dst);
//	if (bullet_vel < 5000 || dist < 700) { // Not using gun or Super closeup
//		return Var_CalcAngless(src, dst);
//	}
//
//	float travel_time = dist / bullet_vel;
//	float bullet_drop = (358.f * travel_time * travel_time);
//
//	Vector3 predictedDst = dst;
//	predictedDst.x += Velocity.x * travel_time;
//	predictedDst.y += Velocity.y * travel_time;
//	predictedDst.z += (Velocity.z * travel_time) + bullet_drop;
//
//	return Var_CalcAngless(src, predictedDst);
//}
//inline Vector3 calculateAnglesForEntss(uintptr_t targetEntity, uintptr_t local, int targetBone) {
//
//	Vector3 CameraPos = read<Vector3>(local + offsets::camera_origin);
//	if (CameraPos.x == 0.0f && CameraPos.y == 0.0f) return { 0,0,0 };
//	int AimBones = 0;
//
//
//
//	Vector3 target_head = GetBonePos(targetEntity, targetBone);
//	if (target_head.x == 0.0f && target_head.y == 0.0f) return { 0,0,0 };
//
//	//Vector3 target_head = D.RPM<Vector3>(targetEntity + OFFSET_ORIGIN);
//
//	Vector3 newAngles = CalcAnglePredictives(CameraPos, target_head, targetEntity, local);
//	if (newAngles.x == 0.0f && newAngles.y == 0.0f) return { 0,0,0 };
//
//
//
//	return newAngles;
//}
//inline int getClosestBone(uintptr_t ent)
//{
//	uintptr_t pMode_Name = read<uintptr_t>(ent + offsets::m_ModelName);
//	char* modelName = reinterpret_cast<char*>(pMode_Name);
//	std::string s(modelName);
//
//	float closest = 9999;
//	int boneId = -1000;
//
//	if (s.find("bloodhound") != -1)
//	{
//		for (int i : bloodhoundBones)
//		{
//			Vector3 pos = getBonePositionByHitbox(ent, i);
//			pos = ProjectWorldToScreen(pos);
//
//			float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - pos.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - pos.y, 2));
//
//			if (length < closest && length <= (fov * 3)) {
//				closest = length;
//				boneId = boneId;
//			}
//		}
//	}
//	else
//	{
//		for (int i : regualrBones)
//		{
//			Vector3 pos = getBonePositionByHitbox(ent, i);
//			pos = ProjectWorldToScreen(pos);
//
//			float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - pos.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - pos.y, 2));
//
//			if (length < closest && length <= (fov * 3)) {
//				closest = length;
//				boneId = boneId;
//			}
//		}
//	}
//
//	return boneId;
//}

inline void aimbot(entityList ents) {
	if (GetAsyncKeyState(aimbotkey) || GetAsyncKeyState(secondaimbotkey))
	{
		PlayerEnt localPlayer = PlayerEnt();//read<DWORD64>(GameAddress + offsets::LocalPlayer);
		if (localPlayer.address != NULL) {
			PlayerEnt ent = getBestEnt(localPlayer, ents);
			if (ent.address != NULL) {
				int targetBone;
				if (hitbox == 0)
				{
					targetBone = 0;
				}
				else if (hitbox == 1) {
					targetBone = 1;
				}
				else if (hitbox == 3)
				{
					//targetBone = getClosestBone(ent);
				}
				else {
					targetBone = 4;
				}

				Vector3 newAngle = CalcAngle(localPlayer.getBonePositionByHitbox(0), ent.getBonePositionByHitbox(targetBone)); //calculateAnglesForEntss(ent, localPlayer, targetBone);
				Vector3 tPos = ent.getBonePositionByHitbox(targetBone).ProjectWorldToScreen();
				//tPos = ProjectWorldToScreen(tPos);
				if (tPos.Empty()) return;

				if (newAngle.x != 0 && newAngle.y != 0)
				{
					Vector3 ViewAngle = read<Vector3>(localPlayer.address + offsets::viewAngles);
					Vector2 punch = read<Vector2>(localPlayer.address + offsets::punchAngle);
					newAngle.x -= (punch.x - previousPitch) * pitchSTR;
					newAngle.y -= (punch.y - previousYaw) * yawSTR;

					Vector3 delta = newAngle - ViewAngle;

					delta.Normalize();
					float newSmoothing = smothing;
					if (smothing == 1)
					{
						newSmoothing = 1.0f;
					}
					else {
						newSmoothing *= 18;
					}

					delta.y /= newSmoothing;
					delta.x /= newSmoothing;
					if (AimbotVis)
						if (vis)
							write<Vector2>(localPlayer.address + offsets::viewAngles, Vector2(ViewAngle.x + delta.x, ViewAngle.y + delta.y));

					if (!AimbotVis)
						write<Vector2>(localPlayer.address + offsets::viewAngles, Vector2(ViewAngle.x + delta.x, ViewAngle.y + delta.y));
				}
			}
		}
	}
}


inline void DoBhop()
{
	while (true) {
		if (bhop)
			if (GetAsyncKeyState(bhopkey)) {
				write<int>(GameAddress + offsets::IN_JUMP + 0x08, 5);
				Sleep(5);
				write<int>(GameAddress + offsets::IN_JUMP + 0x08, 4);
				Sleep(5);
			}
		Sleep(1);
	}

}
inline void doMisc(PlayerEnt LocalPlayer, PlayerEnt Entity)
{

	if (ShowFps) //// works
		write<bool>(GameAddress + offsets::showfps_enabled, true);
	else write<bool>(GameAddress + offsets::showfps_enabled, false);

	if (autograple)
	{
		if (GetAsyncKeyState(autograpleKey))
		{
			write<int>(GameAddress + offsets::IN_JUMP + 0x8, 4);

			auto Gn = read<int>(LocalPlayer.address + offsets::m_grapple + 0x0048);
			if (Gn == 1) {
				write<int>(GameAddress + offsets::IN_JUMP + 0x8, 5);
			}
		}
	}


	if (autostraf)
	{
		uintptr_t m_grapple = offsets::m_grapple;
		uintptr_t timeBase = offsets::TimeBase;
		uintptr_t OFFSET_m_traversalStartTime = offsets::m_traversalStartTime;
		uintptr_t OFFSET_m_traversalProgress = offsets::m_traversalProgress;
		static float startjumpTime = 0;
		static bool startSg = false;

		float	WorldTime = read<float>(LocalPlayer.address + timeBase);
		float m_traversalStartTime = read<float>(LocalPlayer.address + OFFSET_m_traversalStartTime);
		float m_traversalProgress = read<float>(LocalPlayer.address + OFFSET_m_traversalProgress);
		auto HangOnWall = -(m_traversalStartTime - WorldTime);

		if (GetAsyncKeyState(AutoStrafeeKey))
		{
			if (m_traversalProgress > 0.87f && !startSg && HangOnWall > 0.05f && HangOnWall < 1.5f) {
				//start SG
				startjumpTime = WorldTime;
				startSg = true;
			}

			if (startSg) {
				//press button
				write<int>(GameAddress + offsets::IN_JUMP + 0x8, 7);
				if ((WorldTime - startjumpTime) > 0.007) {
					write<int>(GameAddress + offsets::IN_CROUCH + 0x8, 6);
				}
			}

			if ((WorldTime - startjumpTime) > 1.5f && startSg) {
				//need to release button
				write<int>(GameAddress + offsets::IN_JUMP + 0x8, 4);
				write<int>(GameAddress + offsets::IN_CROUCH + 0x8, 4);
				startSg = false;
			}

		}
	}

	if (removeRecoil)
	{
		noRecoil();
	}

	if (Freecam)
	{
		if (GetAsyncKeyState(freecamKey))
		{
			write<int>(LocalPlayer.address + offsets::m_iObserverMode, 7);
			//draw_text_outline(GetSystemMetrics(0) / 2 - (ImGui::CalcTextSize("Free Cam [Enable]").x / 2), GetSystemMetrics(1) / 2 - (ImGui::CalcTextSize("Free Cam [Enable]").y / 2), ImColor(255, 0, 0, 255), "Free Cam [Enable]");
		}
		else {
			write<int>(LocalPlayer.address + offsets::m_iObserverMode, 0);
		}

	}
	if (ForceCrossPlayer)
	{
		write<bool>(GameAddress + offsets::crossPlay_Enabled + 0x68, true);
		write<bool>(GameAddress + offsets::crossPlay_Enabled + 0x8, true);
	}


	if (SkinChange)
	{
		//SetSkin(LocalPlayer, skinId);
		LocalPlayer.SetSkin(skinId);
	}

	/*if (airstuck) {

		if (GetAsyncKeyState(AirStuckKey)) {
			write<float>(GameAddress + offsets::host_timescale + 0x68, 0.00000001);

		}
		else {
			write<float>(GameAddress + offsets::host_timescale + 0x68, 1.0f);
		}

	}*/
}

struct RenderList
{
	std::string text;
	ImColor color;
};
inline bool fullmapradar = false;
inline float TabSize = 10.0f;
inline PlayerEnt selectedPlayerInfo = 0;

inline void playerInfoTab(PlayerEnt localPlayer, entityList ents)
{
	int i;
	PlayerEnt selectedPlayerInfo = GetBestOp(localPlayer, 10, i, ents);//getBestEnt(LocalPlayer); GetBestOp
	PlayerEnt ent = selectedPlayerInfo;
	if (!ent.address)
	{
		ImGui::SetNextWindowSize(ImVec2(175.000f, 145.000f), ImGuiCond_Once);
		ImGui::Begin("PlayerInfo", NULL, 42);
		ImGui::End();
	}
	else
	{
		/*	uintptr_t nameptr = read<uintptr_t>(GameAddress + offsets::NameList + (i - 1) * 0x10);
			char* name = reinterpret_cast<char*>(nameptr);*/
		ImGui::SetNextWindowSize(ImVec2(175.000f, 145.000f), ImGuiCond_Once);
		ImGui::Begin("PlayerInfo", NULL, 42);
		ImVec2 wndPos = ImGui::GetWindowPos();
		wndPos.y += 30;
		//renderInfo(ent, ImGui::GetWindowPos(), name);

		std::string s = "Player Name: " + std::string(ent.name);
		draw_text_outline_font(wndPos.x, wndPos.y, ImColor(255, 255, 255), s.c_str(), esp_font, false);

		s = "Player Level: " + std::to_string(ent.level);
		wndPos.y += 15;
		draw_text_outline_font(wndPos.x, wndPos.y, ImColor(255, 255, 255), s.c_str(), esp_font, false);

		s = "Shield type: ";
		int shieldType = ent.shieldType;
		ImColor color;
		if (shieldType == 5)
		{
			s += "Red";
		}
		else if (shieldType == 4)
		{
			s += "Gold";
		}
		else if (shieldType == 3)
		{
			s += "Purple";
		}
		else if (shieldType == 2)
		{
			s += "Blue";
		}
		else if (shieldType == 1)
		{
			s += "White";
		}
		else
		{
			s += "None";
		}
		wndPos.y += 15;
		draw_text_outline_font(wndPos.x, wndPos.y, ImColor(255, 255, 255), s.c_str(), esp_font, false);

		s = "Shield: " + std::to_string(ent.shield);
		wndPos.y += 15;
		draw_text_outline_font(wndPos.x, wndPos.y, ImColor(255, 255, 255), s.c_str(), esp_font, false);

		s = "Health: " + std::to_string(ent.health);
		wndPos.y += 15;
		draw_text_outline_font(wndPos.x, wndPos.y, ImColor(255, 255, 255), s.c_str(), esp_font, false);

		s = "Distance: " + std::to_string(calcDist(ent.position, localPlayer.position) / 20);
		wndPos.y += 15;
		draw_text_outline_font(wndPos.x, wndPos.y, ImColor(255, 255, 255), s.c_str(), esp_font, false);

		ImGui::End();
	}
}
inline bool got = false;
inline int RenderVisualsTest()
{
	if (!got)
	{
		GameAddress = (uintptr_t)(GetModuleHandle("r5apex.exe"));
		got = true;
	}
	std::cout << "renderVisualTest\n";
	entityList list = getPlayerList();
	PlayerEnt localPlayer = PlayerEnt();
	if (!bItemEsp) goto loop;

	for (int i = 0; i < list.lootList.size(); i++) {
		Loot curEnt = list.lootList.at(i);

		if (curEnt.isSelected())
		{
			float distance = calcDist(curEnt.position, localPlayer.position);
			if ((distance / 20) > maxLootDist) goto loop;
			Vector3 pos = curEnt.position.ProjectWorldToScreen();
			if (pos.Empty()) goto loop;
			std::string s = items::itemList[curEnt.id].item_name;
			ImColor color;

			switch (items::itemList[curEnt.id].m_rarity)
			{
			case items::Rarity::Weapon:
				color = ImColor(weaponColor[0], weaponColor[1], weaponColor[2]);
				break;
			case items::Rarity::Attachment:
				color = ImColor(attachemtColor[0], attachemtColor[1], attachemtColor[2]);
				break;
			case items::Rarity::Armor:
				color = ImColor(armorColor[0], armorColor[1], armorColor[2]);
				break;
			case items::Rarity::Heals:
				color = ImColor(healsColor[0], healsColor[1], healsColor[2]);
				break;
			case items::Rarity::Ammo:
				color = ImColor(ammoColor[0], ammoColor[1], ammoColor[2]);
				break;
			case items::Rarity::Grenade:
				color = ImColor(grenadeColor[0], grenadeColor[1], grenadeColor[2]);
				break;
			default:
				break;
			}

			draw_text_outline_font(pos.x, pos.y + 2, color, s.c_str(), esp_font);
		}
	}

loop:
	for (int i = 0; i < list.playerList.size(); i++)
	{
		std::vector<RenderList> renderedItems;

		PlayerEnt curEnt = list.playerList.at(i);


		doMisc(localPlayer, curEnt);
		Vector3 headPos3D = curEnt.position;
		headPos3D.z += 70;
		float distance = calcDist(headPos3D, localPlayer.position);
		Vector3 headPos2D = headPos3D.ProjectWorldToScreen();
		if (headPos2D.Empty()) continue;
		Vector3 pos2D = curEnt.position.ProjectWorldToScreen();

		int dist = pos2D.y - headPos2D.y;
		if (curEnt.bleedoutSate > 0 && bIgnoreDowned) continue;
		if (curEnt.teamNumber == localPlayer.teamNumber && bTeamCheck) continue;
		if (localPlayer.position.Empty()) continue;
		if (bInfo)
		{
			playerInfoTab(localPlayer, list);
		}
		/*if (bGlow)
			enableGlow();*/

		if (bTeamCol)
		{
			ImGui::GetForegroundDrawList()->AddCircleFilled(ImVec2(headPos2D.x + dist / 4 + 15, headPos2D.y), dist / 10, idColors[curEnt.teamNumber]);
		}
		if (SpectatorCount)
		{
			float targetangle = read<float>(localPlayer.address + offsets::YAW);
			float targetyaw = -targetangle; // yaw is inverted
			if (targetyaw < 0)
				targetyaw += 360;
			targetyaw += 90; // yaw is off by 90
			if (targetyaw > 360)
				targetyaw -= 360;
			float localangle = read<float>(curEnt.address + offsets::YAW);
			float localyaw = -localangle; // yaw is inverted
			if (localyaw < 0)
				localyaw += 360;
			localyaw += 90; // yaw is off by 90
			if (localyaw > 360)
				localyaw -= 360;

			if (targetyaw == localyaw && curEnt.health == 0)
				amountofspectatprs++;

			std::string Textx = "Spectator : " + std::to_string(int(amountofspectatprs));

			if (amountofspectatprs > 0 && curEnt.health > 0)
			{
				draw_text_outline_font(75, 15, ImColor(255, 255, 255, 255), Textx.c_str(), esp_font);

			}
			else
				draw_text_outline_font(75, 15, ImColor(255, 255, 255, 255), Textx.c_str(), esp_font);
		}
		if (bSnaplines)
		{
			ImVec2 start;
			if (snaplineSelection == 0)
				start = ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1));
			else if (snaplineSelection == 1)
				start = ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2);
			else if (snaplineSelection == 2)
				start = ImVec2(GetSystemMetrics(0) / 2, 0);

			if (pos2D.y < 5) continue;

			ImGui::GetForegroundDrawList()->AddLine(start, ImVec2(pos2D.x, pos2D.y), ImColor(snaplineCol[0], snaplineCol[1], snaplineCol[2]));
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(start.x + 1, start.y), ImVec2(pos2D.x + 1, pos2D.y), ImColor(0, 0, 0));
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(start.x - 1, start.y), ImVec2(pos2D.x - 1, pos2D.y), ImColor(0, 0, 0));
		}
		if (Skeleton)
		{
			boneEsp(curEnt);
		}
		if (bTrigger)
		{
			triggerbot(list);
		}
		if (DoAimbot)
		{
			if (renderFov)
				ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2), fov * 3, ImColor(FOVCOLOR[0], FOVCOLOR[1], FOVCOLOR[2], FOVCOLOR[3]));
			if (bDrawTarget)
			{
				PlayerEnt ent = getBestEnt(localPlayer, list);
				if (ent.address != NULL)
				{
					int targetBone;
					if (hitbox == 0)
					{
						targetBone = BoneList::Head;
					}
					else if (hitbox == 1) {
						targetBone = BoneList::Neck;
					}
					else {
						targetBone = BoneList::Pelivs;
					}

					Vector3 tPos = ent.getBonePos(targetBone).ProjectWorldToScreen();
					//tPos = ProjectWorldToScreen(tPos);
					if (tPos.Empty()) return -1;
					ImGui::GetForegroundDrawList()->AddLine(ImVec2(tPos.x, tPos.y), ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2), ImColor(TargetColor[0], TargetColor[1], TargetColor[2], TargetColor[3]));
				}
			}
			aimbot(list);
		}

		if (bbox)
		{
			ImColor col;
			if (curEnt.isVisable())
				col = ImColor(BoxCol[0], BoxCol[1], BoxCol[2]);
			else
				col = ImColor(NBoxCol[0], NBoxCol[1], NBoxCol[2]);

			if (visCheck)
				vis ? DrawBox(ImVec2(headPos2D.x, headPos2D.y), ImVec2(pos2D.x, pos2D.y), col, 0.7f) : DrawBox(ImVec2(headPos2D.x, headPos2D.y), ImVec2(pos2D.x, pos2D.y), ImColor(VisColor[0], VisColor[1], VisColor[2], VisColor[3]), 0.7f);
			else
				DrawBox(ImVec2(headPos2D.x, headPos2D.y), ImVec2(pos2D.x, pos2D.y), col, 0.7f);

		}
		if (bCorner)
		{
			ImColor col;
			if (curEnt.isVisable())
				col = ImColor(BoxCol[0], BoxCol[1], BoxCol[2]);
			else
				col = ImColor(NBoxCol[0], NBoxCol[1], NBoxCol[2]);

			DrawCorneredBox(pos2D.x - (dist / 4), headPos2D.y, dist / 2, dist, col, 0.7f);
		}
		if (bhealth)
		{

			float width = (float(dist) / 2) * (float(curEnt.health) / 100);
			ImColor HealthCol;

			if (curEnt.health > 75)
			{
				HealthCol = { 0,255,0,255 };
			}
			else if (curEnt.health > 45)
			{
				HealthCol = { 255, 99,0,255 };
			}
			else {
				HealthCol = { 255,0,0,255 };

			}
			ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4 - 1, pos2D.y + 3 - 1), ImVec2(pos2D.x + dist / 4 + 1, pos2D.y + 9 + 1), ImColor(0, 0, 0)); // black outline
			ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2(pos2D.x + dist / 4, pos2D.y + 9), ImColor(28, 28, 28)); // grey background
			ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2((pos2D.x - dist / 4) + width, pos2D.y + 9), HealthCol); // green health bar
		}
		if (bSeer)
		{
			int shield = curEnt.shield;

			int shieldType = curEnt.shieldType;
			Vector3 Head = curEnt.getBonePos(BoneList::Head).ProjectWorldToScreen();
			if (Head.Empty()) goto next;
			float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head.y, 2));

			if (length <= (seerFov * 3))
				SeerHealth(Head.x, Head.y - 15, curEnt.shield, 125, shieldType, curEnt.health);
		}
	next:
		if (bshield)
		{
			int shield = curEnt.shield;
			float width = (float(dist) / 2) * (float(shield) / 125);
			bool draw = true;
			int shieldType = curEnt.shieldType;
			ImColor color;
			if (shieldType == 5)
			{
				color = ImColor(200, 15, 50);
			}
			else if (shieldType == 4)
			{
				color = ImColor(205, 195, 50);
			}
			else if (shieldType == 3)
			{
				color = ImColor(150, 65, 245);
			}
			else if (shieldType == 2)
			{
				color = ImColor(25, 115, 175);
			}
			else if (shieldType == 1)
			{
				color = ImColor(215, 215, 215);
			}
			else
			{
				draw = false;
			}

			if (draw)
			{
				if (bhealth)
				{
					ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 12), ImVec2(pos2D.x + dist / 4, pos2D.y + 18), ImColor(28, 28, 28)); // grey background
					ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 12), ImVec2((pos2D.x - dist / 4) + width, pos2D.y + 18), color); // shield bar
					ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos2D.x - dist / 4 - 1, pos2D.y + 12 - 1), ImVec2(pos2D.x + dist / 4 + 1, pos2D.y + 18 + 1), ImColor(0, 0, 0)); // black outline
				}
				else
				{
					ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2(pos2D.x + dist / 4, pos2D.y + 9), ImColor(28, 28, 28)); // grey background
					ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2((pos2D.x - dist / 4) + width, pos2D.y + 9), color); // shield bar
					ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos2D.x - dist / 4 - 1, pos2D.y + 12 - 1), ImVec2(pos2D.x + dist / 4 + 1, pos2D.y + 18 + 1), ImColor(0, 0, 0)); // black outline
				}
			}

		}
		if (bname)
		{
			renderedItems.push_back({ curEnt.name, ImColor(NameCol[0], NameCol[1], NameCol[2]) });
		}
		if (bdistance)
		{
			renderedItems.push_back({ std::to_string(int(distance / 20)) + "m", ImColor(DistCol[0], DistCol[1], DistCol[2]) });
		}
		if (bLevel)
		{
			renderedItems.push_back({ std::to_string(curEnt.level), ImColor(levelCol[0], levelCol[1], levelCol[2]) });
		}

		if (renderedItems.size() > 0)
		{
			Vector3 newPos = curEnt.position;
			newPos.z -= 3;
			Vector3 newpos2d = newPos.ProjectWorldToScreen();
			if (bhealth || bshield)
			{
				newpos2d.y += 16;
				for (int i = 0; i < renderedItems.size(); i++)
				{
					newpos2d.y += 10;
					draw_text_outline_font(newpos2d.x, newpos2d.y, renderedItems.at(i).color, renderedItems.at(i).text.c_str(), esp_font);
				}
			}
			else
			{
				for (int i = 0; i < renderedItems.size(); i++)
				{
					newpos2d.y += 10;
					draw_text_outline_font(newpos2d.x, newpos2d.y, renderedItems.at(i).color, renderedItems.at(i).text.c_str(), esp_font);
				}
			}
		}
	}
}