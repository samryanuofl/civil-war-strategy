#include "SpriteInfo.h"

#include <string>
#include <vector>

class IRenderable
{
    public:
    virtual std::vector<SpriteInfo> GetRenderables() = 0;
};
