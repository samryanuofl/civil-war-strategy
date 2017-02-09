#include "SpriteInfo.h"

#include <string>

class IRenderable
{
    public:
    virtual std::vector<SpriteInfo> GetRenderables() = 0;
};
