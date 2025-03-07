#ifndef SFML_GAME_SCENENODE_HPP
#define SFML_GAME_SCENENODE_HPP


#include <memory>
#include <vector>
#include "SFML/Graphics.hpp"
class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    SceneNode();
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);
private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif //SFML_GAME_SCENENODE_HPP
