
#include "../Include/DataTables.hpp"
#include "../Include/Pickup.hpp"
#include "../Include/Utility.hpp"
#include "../Include/Category.hpp"

namespace {
    const std::vector<PickupData> Table = initializePickupData();
}

Pickup::Pickup(Type type, const TextureHolder& textures): Entity(1), mType(type), mSprite(textures.get(Table[type].texture)){
    centerOrigin(mSprite);
}

unsigned int Pickup::getCategory() const{
    return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const{
    return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Pickup::apply(Aircraft& player) const{
    Table[mType].action(player);
}

void Pickup::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(mSprite, states);
}


#include "../Include/Pickup.hpp"
