#ifndef SFML_GAME_SCENENODE_HPP
#define SFML_GAME_SCENENODE_HPP


#include <memory>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Command.hpp"
#include "set"
#include "Category.hpp"
#include "CommandQueue.hpp"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    typedef std::pair<SceneNode*, SceneNode*> Pair;

public:
    explicit SceneNode(Category::Type category = Category::None);
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);
    void update(sf::Time dt, CommandQueue& commands);
    sf::Vector2f getWorldPosition() const;
    sf::Transform getWorldTransform() const;
    void onCommand(const Command& command, sf::Time dt);
    void checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
    void checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
    void removeWrecks();
    virtual sf::FloatRect getBoundingRect() const;
    virtual unsigned int getCategory() const;
    virtual bool isMarkedForRemoval() const;
    virtual bool isDestroyed() const;

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
    Category::Type mDefaultCategory;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
    void updateChildren(sf::Time dt, CommandQueue& commands);
    void drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //SFML_GAME_SCENENODE_HPP
