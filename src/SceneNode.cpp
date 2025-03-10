#include <algorithm>
#include <cassert>
#include <iostream>
#include "../Include/SceneNode.hpp"
#include "../Include/Category.hpp"

SceneNode::SceneNode() : mChildren(), mParent(nullptr){}

void SceneNode::attachChild(SceneNode::Ptr child) {
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr &p) { return p.get() == &node; });
    assert(found != mChildren.end());

    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const Ptr& child : mChildren){
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

}

void SceneNode::updateCurrent(sf::Time dt) {

}

void SceneNode::updateChildren(sf::Time dt) {
    for(const Ptr& child: mChildren){
        child->update(dt);
    }
}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;

    for(auto node = this; node != nullptr; node=node->mParent)
        transform *= node->getTransform();

    return transform;
}

unsigned int SceneNode::getCategory() const {
    return Category::Scene;
}

void SceneNode::onCommand(const Command &command, sf::Time dt) {
    if(command.category & getCategory())
        command.action(*this,dt);
    for (Ptr& child : mChildren)
        child->onCommand(command,dt);
}

