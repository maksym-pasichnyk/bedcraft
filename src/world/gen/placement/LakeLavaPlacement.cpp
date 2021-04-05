#include "LakeLavaPlacement.hpp"
#include "../../WorldGenRegion.hpp"

void LakeLavaPlacement::forEach(WorldGenRegion &region, Random &random, const PlacementConfig &config, glm::ivec3 pos, const std::function<void(glm::ivec3)> &fn) {
    const auto& cfg = std::get<ChanceConfig>(config);
    
    if (random.nextInt(cfg.chance / 10) == 0) {
        const int x = random.nextInt(16) + pos.x;
        const int z = random.nextInt(16) + pos.z;
        const int y = random.nextInt(random.nextInt(region.getMaxBuildHeight() - 8) + 8);
        if (y < region.getSeaLevel() || random.nextInt(cfg.chance / 8) == 0) {
            fn(glm::ivec3(x, y, z));
        }
    }
}
