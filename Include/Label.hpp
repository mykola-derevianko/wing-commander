
#ifndef SFML_GAME_LABEL_HPP
#define SFML_GAME_LABEL_HPP


#include <Graphics/Text.hpp>
#include "Component.hpp"
#include "ResourceIdentifiers.hpp"

namespace GUI{

    class Label : public Component{
    public:
        typedef std::shared_ptr<Label> Ptr;
        Label(const std::string& text, const FontHolder& fonts);
        virtual bool isSelectable() const;
        void setText(const std::string& text);
        virtual void handleEvent(const sf::Event& event);


    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::Text mText;
    };

}


#endif //SFML_GAME_LABEL_HPP
