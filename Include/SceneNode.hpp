#ifndef SFML_GAME_SCENENODE_HPP
#define SFML_GAME_SCENENODE_HPP


#include <memory>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Command.hpp"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);
    void update(sf::Time dt);
    sf::Vector2f getWorldPosition() const;
    sf::Transform getWorldTransform() const;
    virtual unsigned int getCategory() const;
    void onCommand(const Command& command, sf::Time dt);

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);
};

#endif //SFML_GAME_SCENENODE_HPP
