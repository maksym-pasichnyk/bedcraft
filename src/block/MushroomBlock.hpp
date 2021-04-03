#pragma once

#include "BushBlock.hpp"

struct MushroomBlock : BushBlock {
    using BushBlock::BushBlock;

    bool isValidGround(const BlockData& data, WorldReader &reader, const glm::ivec3 &pos) override;
    bool isValidPosition(const BlockData& data, WorldReader &reader, const glm::ivec3 &pos) override;
};