#ifndef SFML_GAME_COMPONENT_HPP
#define SFML_GAME_COMPONENT_HPP


#include <System/NonCopyable.hpp>
#include <Graphics/Transformable.hpp>
#include <Graphics/Drawable.hpp>
#include <memory>
#include <Window/Event.hpp>

namespace GUI{
    class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable{
        public:
            typedef std::shared_ptr<Component> Ptr;


            Component();
            virtual ~Component();
            virtual bool isSelectable() const = 0;

            bool isSelected() const;
            virtual void select();
            virtual void deselect();

            virtual bool isActive() const;
            virtual void activate();
            virtual void deactivate();

            virtual void handleEvent(const sf::Event& event) = 0;

        private:
            bool mIsSelected;
            bool mIsActive;
    };
}


#endif //SFML_GAME_COMPONENT_HPP
