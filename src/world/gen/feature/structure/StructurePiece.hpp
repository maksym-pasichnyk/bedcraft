#pragma once

#include "config/StructureConfig.hpp"
#include "../../../../util/Random.hpp"
#include "../../../../util/Mirror.hpp"
#include "../../../../util/Rotation.hpp"
#include "../../../../util/Direction.hpp"
#include "../../../../util/math/BlockPos.hpp"
#include "../../../../util/math/ChunkPos.hpp"
#include "../../../../util/math/BoundingBox.hpp"

#include <vector>
#include <memory>
#include <optional>
#include <range/v3/algorithm.hpp>

struct BlockData;
struct WorldReader;
struct BlockSelector;
struct WorldGenRegion;
struct ChunkGenerator;
struct StructureManager;


struct BlockSelector {
    virtual ~BlockSelector() = default;
    virtual auto select(Random& random, int x, int y, int z, bool wall) -> BlockData = 0;
};

struct StructurePiece {
    static auto findIntersecting(std::span<StructurePiece*> pieces, const BoundingBox& bb) -> StructurePiece* {
        for (auto piece : pieces) {
            if (piece->getBoundingBox().intersectsWith(bb)) {
                return piece;
            }
        }
        return nullptr;
    }

    static auto hasIntersecting(std::span<StructurePiece*> pieces, const BoundingBox& bb) -> bool {
        return ranges::any_of(pieces, [&bb](auto piece) {
            return piece->getBoundingBox().intersectsWith(bb);
        });
    }

    BoundingBox bounds{};
    std::optional<Direction> coordBaseMode = std::nullopt;
    Mirror mirror = Mirror::NONE;
    Rotation rotation = Rotation::NONE;
    int componentIndex;

    explicit StructurePiece(int componentIndex) : componentIndex(componentIndex) {}
    virtual ~StructurePiece() = default;

    auto getComponentType() const -> int {
        return componentIndex;
    }

    void setCoordBaseMode(std::optional<Direction> facing) {
        coordBaseMode = facing;
        if (facing.has_value()) {
            mirror = MirrorUtil::from(*facing);
            rotation = RotationUtil::from(*facing);
        } else {
            mirror = Mirror::NONE;
            rotation = Rotation::NONE;
        }
    }

    auto getXWithOffset(int x, int z) const -> int {
        if (!coordBaseMode.has_value()) {
            return x;
        }
        switch (*coordBaseMode) {
            case Direction::NORTH:
            case Direction::SOUTH:
                return bounds.minX + x;
            case Direction::WEST:
                return bounds.maxX - z;
            case Direction::EAST:
                return bounds.minX + z;
            default:
                return x;
        }
    }

    auto getYWithOffset(int y) const -> int {
        return coordBaseMode.has_value() ? y + bounds.minY : y;
    }

    auto getZWithOffset(int x, int z) const -> int {
        if (!coordBaseMode.has_value()) {
            return z;
        }
        switch (*coordBaseMode) {
            case Direction::NORTH:
                return bounds.maxZ - z;
            case Direction::SOUTH:
                return bounds.minZ + z;
            case Direction::WEST:
            case Direction::EAST:
                return bounds.minZ + x;
            default:
                return z;
        }
    }

    auto getRelativePosition(int x, int y, int z) const -> BlockPos {
        return BlockPos::from(getXWithOffset(x, z), getYWithOffset(y), getZWithOffset(x, z));
    }

    auto getBoundingBox() const -> BoundingBox {
        return bounds;
    }

    BlockData getBlockStateFromPos(WorldReader& reader, int x, int y, int z, const BoundingBox& bb) const;
    bool isLiquidInStructureBoundingBox(WorldReader& reader, const BoundingBox& bb) const;
    bool isUnderOceanFloor(WorldGenRegion &region, int x, int y, int z, const BoundingBox& bb) const;
    void fillWithAir(WorldGenRegion& region, const BoundingBox& bb, int minX, int minY, int minZ, int maxX, int maxY, int maxZ) const;
    void fillWithBlocks(WorldGenRegion &region, const BoundingBox& bb, int xMin, int yMin, int zMin, int xMax, int yMax, int zMax, BlockData boundaryBlockState, BlockData insideBlockState, bool existingOnly) const;
    void fillWithRandomizedBlocks(WorldGenRegion &region, const BoundingBox& bb, int minX, int minY, int minZ, int maxX, int maxY, int maxZ, bool alwaysReplace, Random& random, BlockSelector& selector) const;
    void generateMaybeBox(WorldGenRegion &region, const BoundingBox& bb, Random& random, float chance, int x1, int y1, int z1, int x2, int y2, int z2, BlockData edgeState, BlockData state, bool requireNonAir, bool requiredSkylight) const;
    void setBlockState(WorldGenRegion& region, BlockData state, int x, int y, int z, const BoundingBox& bb) const;
    void replaceAirAndLiquidDownwards(WorldGenRegion& region, BlockData state, int x, int y, int z, const BoundingBox& bb) const;
    void randomlyRareFillWithBlocks(WorldGenRegion& region, const BoundingBox& bb, int minX, int minY, int minZ, int maxX, int maxY, int maxZ, BlockData state, bool excludeAir) const;
    void randomlyPlaceBlock(WorldGenRegion& region, const BoundingBox& bb, Random& random, float chance, int x, int y, int z, BlockData state) const;

    virtual void buildComponent(StructurePiece* start, std::vector<StructurePiece *> &pieces, Random& random) {}
    virtual bool addComponentParts(WorldGenRegion& region, StructureManager& structureManager, ChunkGenerator& generator, Random& random, const BoundingBox& bb, const ChunkPos& chunkPos, const BlockPos& blockPos) = 0;
    virtual void offset(int x, int y, int z) {
        bounds.offset(x, y, z);
    }
};