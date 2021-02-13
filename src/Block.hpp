#pragma once

#include <glm/vec4.hpp>

#include <map>
#include <vector>
#include <string>

#include "BlockTable.hpp"

struct TextureAtlasTextureItem;

struct BlockGraphics {
	TextureAtlasTextureItem* topTexture;
	TextureAtlasTextureItem* bottomTexture;
	TextureAtlasTextureItem* southTexture;
	TextureAtlasTextureItem* northTexture;
	TextureAtlasTextureItem* eastTexture;
	TextureAtlasTextureItem* westTexture;
};

enum class Tint {
	None,
	Grass,
	Foliage
};

enum class RenderType {
	Air,
	Liquid,
	Block,
	Leaves,
	Cross,
	Pane
};

enum class RenderLayer {
	Opaque,
	Cutout,
	Transparent
};

extern std::map<std::string, BlockGraphics> tile_datas;

struct LiquidBlock;
struct Block {
    static std::vector<Block*> id_to_block;
    static std::vector<Block*> block_to_id;

	[[maybe_unused]] static Block* acacia_button;
	[[maybe_unused]] static Block* acacia_door;
	[[maybe_unused]] static Block* acacia_fence_gate;
	[[maybe_unused]] static Block* acacia_pressure_plate;
	[[maybe_unused]] static Block* acacia_stairs;
	[[maybe_unused]] static Block* acacia_standing_sign;
	[[maybe_unused]] static Block* acacia_trapdoor;
	[[maybe_unused]] static Block* acacia_wall_sign;
	[[maybe_unused]] static Block* activator_rail;
	[[maybe_unused]] static Block* air;
	[[maybe_unused]] static Block* allow;
	[[maybe_unused]] static Block* andesite_stairs;
	[[maybe_unused]] static Block* anvil;
	[[maybe_unused]] static Block* bamboo;
	[[maybe_unused]] static Block* bamboo_sapling;
	[[maybe_unused]] static Block* barrel;
	[[maybe_unused]] static Block* barrier;
	[[maybe_unused]] static Block* beacon;
	[[maybe_unused]] static Block* bed;
	[[maybe_unused]] static Block* bedrock;
	[[maybe_unused]] static Block* beetroot;
	[[maybe_unused]] static Block* bell;
	[[maybe_unused]] static Block* birch_button;
	[[maybe_unused]] static Block* birch_door;
	[[maybe_unused]] static Block* birch_fence_gate;
	[[maybe_unused]] static Block* birch_pressure_plate;
	[[maybe_unused]] static Block* birch_stairs;
	[[maybe_unused]] static Block* birch_standing_sign;
	[[maybe_unused]] static Block* birch_trapdoor;
	[[maybe_unused]] static Block* birch_wall_sign;
	[[maybe_unused]] static Block* black_glazed_terracotta;
	[[maybe_unused]] static Block* blast_furnace;
	[[maybe_unused]] static Block* blue_glazed_terracotta;
	[[maybe_unused]] static Block* blue_ice;
	[[maybe_unused]] static Block* bone_block;
	[[maybe_unused]] static Block* bookshelf;
	[[maybe_unused]] static Block* border_block;
	[[maybe_unused]] static Block* brewing_stand;
	[[maybe_unused]] static Block* brick_block;
	[[maybe_unused]] static Block* brick_stairs;
	[[maybe_unused]] static Block* brown_glazed_terracotta;
	[[maybe_unused]] static Block* brown_mushroom;
	[[maybe_unused]] static Block* brown_mushroom_block;
	[[maybe_unused]] static Block* bubble_column;
	[[maybe_unused]] static Block* cactus;
	[[maybe_unused]] static Block* cake;
	[[maybe_unused]] static Block* camera;
	[[maybe_unused]] static Block* campfire;
	[[maybe_unused]] static Block* carpet;
	[[maybe_unused]] static Block* carrots;
	[[maybe_unused]] static Block* cartography_table;
	[[maybe_unused]] static Block* carved_pumpkin;
	[[maybe_unused]] static Block* cauldron;
	[[maybe_unused]] static Block* chain_command_block;
	[[maybe_unused]] static Block* chest;
	[[maybe_unused]] static Block* chorus_flower;
	[[maybe_unused]] static Block* chorus_plant;
	[[maybe_unused]] static Block* clay;
	[[maybe_unused]] static Block* coal_block;
	[[maybe_unused]] static Block* coal_ore;
	[[maybe_unused]] static Block* cobblestone;
	[[maybe_unused]] static Block* cobblestone_wall;
	[[maybe_unused]] static Block* cocoa;
	[[maybe_unused]] static Block* command_block;
	[[maybe_unused]] static Block* composter;
	[[maybe_unused]] static Block* concrete;
	[[maybe_unused]] static Block* concretePowder;
	[[maybe_unused]] static Block* conduit;
	[[maybe_unused]] static Block* coral;
	[[maybe_unused]] static Block* coral_block;
	[[maybe_unused]] static Block* coral_fan;
	[[maybe_unused]] static Block* coral_fan_dead;
	[[maybe_unused]] static Block* coral_fan_hang;
	[[maybe_unused]] static Block* coral_fan_hang2;
	[[maybe_unused]] static Block* coral_fan_hang3;
	[[maybe_unused]] static Block* crafting_table;
	[[maybe_unused]] static Block* cyan_glazed_terracotta;
	[[maybe_unused]] static Block* dark_oak_button;
	[[maybe_unused]] static Block* dark_oak_door;
	[[maybe_unused]] static Block* dark_oak_fence_gate;
	[[maybe_unused]] static Block* dark_oak_pressure_plate;
	[[maybe_unused]] static Block* dark_oak_stairs;
	[[maybe_unused]] static Block* dark_oak_trapdoor;
	[[maybe_unused]] static Block* dark_prismarine_stairs;
	[[maybe_unused]] static Block* darkoak_standing_sign;
	[[maybe_unused]] static Block* darkoak_wall_sign;
	[[maybe_unused]] static Block* daylight_detector;
	[[maybe_unused]] static Block* daylight_detector_inverted;
	[[maybe_unused]] static Block* deadbush;
	[[maybe_unused]] static Block* deny;
	[[maybe_unused]] static Block* detector_rail;
	[[maybe_unused]] static Block* diamond_block;
	[[maybe_unused]] static Block* diamond_ore;
	[[maybe_unused]] static Block* diorite_stairs;
	[[maybe_unused]] static Block* dirt;
	[[maybe_unused]] static Block* dispenser;
	[[maybe_unused]] static Block* double_plant;
	[[maybe_unused]] static Block* double_stone_slab;
	[[maybe_unused]] static Block* double_stone_slab2;
	[[maybe_unused]] static Block* double_stone_slab3;
	[[maybe_unused]] static Block* double_stone_slab4;
	[[maybe_unused]] static Block* double_wooden_slab;
	[[maybe_unused]] static Block* dragon_egg;
	[[maybe_unused]] static Block* dried_kelp_block;
	[[maybe_unused]] static Block* dropper;
	[[maybe_unused]] static Block* emerald_block;
	[[maybe_unused]] static Block* emerald_ore;
	[[maybe_unused]] static Block* enchanting_table;
	[[maybe_unused]] static Block* end_brick_stairs;
	[[maybe_unused]] static Block* end_bricks;
	[[maybe_unused]] static Block* end_gateway;
	[[maybe_unused]] static Block* end_portal;
	[[maybe_unused]] static Block* end_portal_frame;
	[[maybe_unused]] static Block* end_rod;
	[[maybe_unused]] static Block* end_stone;
	[[maybe_unused]] static Block* ender_chest;
	[[maybe_unused]] static Block* farmland;
	[[maybe_unused]] static Block* fence;
	[[maybe_unused]] static Block* fence_gate;
	[[maybe_unused]] static Block* fire;
	[[maybe_unused]] static Block* fletching_table;
	[[maybe_unused]] static Block* flower_pot;
	[[maybe_unused]] static LiquidBlock* flowing_lava;
	[[maybe_unused]] static LiquidBlock* flowing_water;
	[[maybe_unused]] static Block* frame;
	[[maybe_unused]] static Block* frosted_ice;
	[[maybe_unused]] static Block* furnace;
	[[maybe_unused]] static Block* glass;
	[[maybe_unused]] static Block* glass_pane;
	[[maybe_unused]] static Block* glowingobsidian;
	[[maybe_unused]] static Block* glowstone;
	[[maybe_unused]] static Block* gold_block;
	[[maybe_unused]] static Block* gold_ore;
	[[maybe_unused]] static Block* golden_rail;
	[[maybe_unused]] static Block* granite_stairs;
	[[maybe_unused]] static Block* grass;
	[[maybe_unused]] static Block* grass_path;
	[[maybe_unused]] static Block* gravel;
	[[maybe_unused]] static Block* gray_glazed_terracotta;
	[[maybe_unused]] static Block* green_glazed_terracotta;
	[[maybe_unused]] static Block* grindstone;
	[[maybe_unused]] static Block* hardened_clay;
	[[maybe_unused]] static Block* hay_block;
	[[maybe_unused]] static Block* heavy_weighted_pressure_plate;
	[[maybe_unused]] static Block* hopper;
	[[maybe_unused]] static Block* ice;
	[[maybe_unused]] static Block* info_update;
	[[maybe_unused]] static Block* info_update2;
	[[maybe_unused]] static Block* invisibleBedrock;
	[[maybe_unused]] static Block* iron_bars;
	[[maybe_unused]] static Block* iron_block;
	[[maybe_unused]] static Block* iron_door;
	[[maybe_unused]] static Block* iron_ore;
	[[maybe_unused]] static Block* iron_trapdoor;
	[[maybe_unused]] static Block* jigsaw;
	[[maybe_unused]] static Block* jukebox;
	[[maybe_unused]] static Block* jungle_button;
	[[maybe_unused]] static Block* jungle_door;
	[[maybe_unused]] static Block* jungle_fence_gate;
	[[maybe_unused]] static Block* jungle_pressure_plate;
	[[maybe_unused]] static Block* jungle_stairs;
	[[maybe_unused]] static Block* jungle_standing_sign;
	[[maybe_unused]] static Block* jungle_trapdoor;
	[[maybe_unused]] static Block* jungle_wall_sign;
	[[maybe_unused]] static Block* kelp;
	[[maybe_unused]] static Block* ladder;
	[[maybe_unused]] static Block* lantern;
	[[maybe_unused]] static Block* lapis_block;
	[[maybe_unused]] static Block* lapis_ore;
	[[maybe_unused]] static LiquidBlock* lava;
	[[maybe_unused]] static Block* lava_cauldron;
	[[maybe_unused]] static Block* leaves;
	[[maybe_unused]] static Block* leaves2;
	[[maybe_unused]] static Block* lectern;
	[[maybe_unused]] static Block* lever;
	[[maybe_unused]] static Block* light_block;
	[[maybe_unused]] static Block* light_blue_glazed_terracotta;
	[[maybe_unused]] static Block* light_weighted_pressure_plate;
	[[maybe_unused]] static Block* lime_glazed_terracotta;
	[[maybe_unused]] static Block* lit_blast_furnace;
	[[maybe_unused]] static Block* lit_furnace;
	[[maybe_unused]] static Block* lit_pumpkin;
	[[maybe_unused]] static Block* lit_redstone_lamp;
	[[maybe_unused]] static Block* lit_redstone_ore;
	[[maybe_unused]] static Block* lit_smoker;
	[[maybe_unused]] static Block* log;
	[[maybe_unused]] static Block* log2;
	[[maybe_unused]] static Block* loom;
	[[maybe_unused]] static Block* magenta_glazed_terracotta;
	[[maybe_unused]] static Block* magma;
	[[maybe_unused]] static Block* melon_block;
	[[maybe_unused]] static Block* melon_stem;
	[[maybe_unused]] static Block* mob_spawner;
	[[maybe_unused]] static Block* monster_egg;
	[[maybe_unused]] static Block* mossy_cobblestone;
	[[maybe_unused]] static Block* mossy_cobblestone_stairs;
	[[maybe_unused]] static Block* mossy_stone_brick_stairs;
	[[maybe_unused]] static Block* movingBlock;
	[[maybe_unused]] static Block* mycelium;
	[[maybe_unused]] static Block* nether_brick;
	[[maybe_unused]] static Block* nether_brick_fence;
	[[maybe_unused]] static Block* nether_brick_stairs;
	[[maybe_unused]] static Block* nether_wart;
	[[maybe_unused]] static Block* nether_wart_block;
	[[maybe_unused]] static Block* netherrack;
	[[maybe_unused]] static Block* netherreactor;
	[[maybe_unused]] static Block* normal_stone_stairs;
	[[maybe_unused]] static Block* noteblock;
	[[maybe_unused]] static Block* oak_stairs;
	[[maybe_unused]] static Block* observer;
	[[maybe_unused]] static Block* obsidian;
	[[maybe_unused]] static Block* orange_glazed_terracotta;
	[[maybe_unused]] static Block* packed_ice;
	[[maybe_unused]] static Block* pink_glazed_terracotta;
	[[maybe_unused]] static Block* piston;
	[[maybe_unused]] static Block* pistonArmCollision;
	[[maybe_unused]] static Block* planks;
	[[maybe_unused]] static Block* podzol;
	[[maybe_unused]] static Block* polished_andesite_stairs;
	[[maybe_unused]] static Block* polished_diorite_stairs;
	[[maybe_unused]] static Block* polished_granite_stairs;
	[[maybe_unused]] static Block* portal;
	[[maybe_unused]] static Block* potatoes;
	[[maybe_unused]] static Block* powered_comparator;
	[[maybe_unused]] static Block* powered_repeater;
	[[maybe_unused]] static Block* prismarine;
	[[maybe_unused]] static Block* prismarine_bricks_stairs;
	[[maybe_unused]] static Block* prismarine_stairs;
	[[maybe_unused]] static Block* pumpkin;
	[[maybe_unused]] static Block* pumpkin_stem;
	[[maybe_unused]] static Block* purple_glazed_terracotta;
	[[maybe_unused]] static Block* purpur_block;
	[[maybe_unused]] static Block* purpur_stairs;
	[[maybe_unused]] static Block* quartz_block;
	[[maybe_unused]] static Block* quartz_ore;
	[[maybe_unused]] static Block* quartz_stairs;
	[[maybe_unused]] static Block* rail;
	[[maybe_unused]] static Block* red_flower;
	[[maybe_unused]] static Block* red_glazed_terracotta;
	[[maybe_unused]] static Block* red_mushroom;
	[[maybe_unused]] static Block* red_mushroom_block;
	[[maybe_unused]] static Block* red_nether_brick;
	[[maybe_unused]] static Block* red_nether_brick_stairs;
	[[maybe_unused]] static Block* red_sandstone;
	[[maybe_unused]] static Block* red_sandstone_stairs;
	[[maybe_unused]] static Block* redstone_block;
	[[maybe_unused]] static Block* redstone_lamp;
	[[maybe_unused]] static Block* redstone_ore;
	[[maybe_unused]] static Block* redstone_torch;
	[[maybe_unused]] static Block* redstone_wire;
	[[maybe_unused]] static Block* reeds;
	[[maybe_unused]] static Block* repeating_command_block;
	[[maybe_unused]] static Block* reserved6;
	[[maybe_unused]] static Block* sand;
	[[maybe_unused]] static Block* sandstone;
	[[maybe_unused]] static Block* sandstone_stairs;
	[[maybe_unused]] static Block* sapling;
	[[maybe_unused]] static Block* scaffolding;
	[[maybe_unused]] static Block* seaLantern;
	[[maybe_unused]] static Block* sea_pickle;
	[[maybe_unused]] static Block* seagrass;
	[[maybe_unused]] static Block* shulker_box;
	[[maybe_unused]] static Block* silver_glazed_terracotta;
	[[maybe_unused]] static Block* skull;
	[[maybe_unused]] static Block* slime;
	[[maybe_unused]] static Block* smithing_table;
	[[maybe_unused]] static Block* smoker;
	[[maybe_unused]] static Block* smooth_quartz_stairs;
	[[maybe_unused]] static Block* smooth_red_sandstone_stairs;
	[[maybe_unused]] static Block* smooth_sandstone_stairs;
	[[maybe_unused]] static Block* smooth_stone;
	[[maybe_unused]] static Block* snow;
	[[maybe_unused]] static Block* snow_layer;
	[[maybe_unused]] static Block* soul_sand;
	[[maybe_unused]] static Block* sponge;
	[[maybe_unused]] static Block* spruce_button;
	[[maybe_unused]] static Block* spruce_door;
	[[maybe_unused]] static Block* spruce_fence_gate;
	[[maybe_unused]] static Block* spruce_pressure_plate;
	[[maybe_unused]] static Block* spruce_stairs;
	[[maybe_unused]] static Block* spruce_standing_sign;
	[[maybe_unused]] static Block* spruce_trapdoor;
	[[maybe_unused]] static Block* spruce_wall_sign;
	[[maybe_unused]] static Block* stained_glass;
	[[maybe_unused]] static Block* stained_glass_pane;
	[[maybe_unused]] static Block* stained_hardened_clay;
	[[maybe_unused]] static Block* standing_banner;
	[[maybe_unused]] static Block* standing_sign;
	[[maybe_unused]] static Block* stickyPistonArmCollision;
	[[maybe_unused]] static Block* sticky_piston;
	[[maybe_unused]] static Block* stone;
	[[maybe_unused]] static Block* stone_brick_stairs;
	[[maybe_unused]] static Block* stone_button;
	[[maybe_unused]] static Block* stone_pressure_plate;
	[[maybe_unused]] static Block* stone_slab;
	[[maybe_unused]] static Block* stone_slab2;
	[[maybe_unused]] static Block* stone_slab3;
	[[maybe_unused]] static Block* stone_slab4;
	[[maybe_unused]] static Block* stone_stairs;
	[[maybe_unused]] static Block* stonebrick;
	[[maybe_unused]] static Block* stonecutter;
	[[maybe_unused]] static Block* stonecutter_block;
	[[maybe_unused]] static Block* stripped_acacia_log;
	[[maybe_unused]] static Block* stripped_birch_log;
	[[maybe_unused]] static Block* stripped_dark_oak_log;
	[[maybe_unused]] static Block* stripped_jungle_log;
	[[maybe_unused]] static Block* stripped_oak_log;
	[[maybe_unused]] static Block* stripped_spruce_log;
	[[maybe_unused]] static Block* structure_block;
	[[maybe_unused]] static Block* structure_void;
	[[maybe_unused]] static Block* sweet_berry_bush;
	[[maybe_unused]] static Block* tallgrass;
	[[maybe_unused]] static Block* tnt;
	[[maybe_unused]] static Block* torch;
	[[maybe_unused]] static Block* trapdoor;
	[[maybe_unused]] static Block* trapped_chest;
	[[maybe_unused]] static Block* tripWire;
	[[maybe_unused]] static Block* tripwire_hook;
	[[maybe_unused]] static Block* turtle_egg;
	[[maybe_unused]] static Block* undyed_shulker_box;
	[[maybe_unused]] static Block* unlit_redstone_torch;
	[[maybe_unused]] static Block* unpowered_comparator;
	[[maybe_unused]] static Block* unpowered_repeater;
	[[maybe_unused]] static Block* vine;
	[[maybe_unused]] static Block* wall_banner;
	[[maybe_unused]] static Block* wall_sign;
	[[maybe_unused]] static LiquidBlock* water;
	[[maybe_unused]] static Block* waterlily;
	[[maybe_unused]] static Block* web;
	[[maybe_unused]] static Block* wheat;
	[[maybe_unused]] static Block* white_glazed_terracotta;
	[[maybe_unused]] static Block* wither_rose;
	[[maybe_unused]] static Block* wood;
	[[maybe_unused]] static Block* wooden_button;
	[[maybe_unused]] static Block* wooden_door;
	[[maybe_unused]] static Block* wooden_pressure_plate;
	[[maybe_unused]] static Block* wooden_slab;
	[[maybe_unused]] static Block* wool;
	[[maybe_unused]] static Block* yellow_flower;
	[[maybe_unused]] static Block* yellow_glazed_terracotta;

	explicit Block(const std::string& name) {
        graphics = &tile_datas.at(name);
	}

	auto setRenderType(RenderType renderTypeIn) -> Block* {
		renderType = renderTypeIn;
		return this;
	}

	auto setRenderLayer(RenderLayer renderLayerIn) -> Block* {
		renderLayer = renderLayerIn;
		return this;
	}

	auto setTint(Tint tintIn) -> Block* {
		tint = tintIn;
		return this;
	}

	static void initBlocks();
	static void registerBlock(BlockTable& pallete, const std::string& name, Block* block);
	static void registerBlocks(BlockTable& pallete);

	Tint tint = Tint::None;
	RenderType renderType = RenderType::Block;
	RenderLayer renderLayer = RenderLayer::Opaque;
    BlockGraphics* graphics{nullptr};
};

//struct BlockState {
//    Block* block = Block::air;
//    int data = 0;
//};

struct LiquidBlock : Block {
    using Block::Block;

    auto setRenderType(RenderType renderTypeIn) -> LiquidBlock* {
        Block::setRenderType(renderTypeIn);
        return this;
    }

    auto setRenderLayer(RenderLayer renderLayerIn) -> LiquidBlock* {
        Block::setRenderLayer(renderLayerIn);
        return this;
    }

    auto setTint(Tint tintIn) -> LiquidBlock* {
        Block::setTint(tintIn);
        return this;
    }
};