#include "CookieJarRenderer.h"

void CookieJarRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);
	
	tess->forcedUV = tile->getTextureUVCoordinateSet("wool", 15); //wool
    tess->setRenderBounds(0.25,0.85,0.25,0.75,1,0.75);
    tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->forcedUV = tile->getTextureUVCoordinateSet("glass", 0); //wool
    tess->setRenderBounds(0.15,0,0.15,0.85,0.85,0.85);
    tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}
