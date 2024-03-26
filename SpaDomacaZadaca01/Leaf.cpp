#include "Leaf.h"

const float Leaf::MAX_PIXELS_MOVED = 7;

Leaf::Leaf(
	const sf::Vector2f& position,
	const sf::Vector2f& velocity,
    int facesDirection
) : AnimatedElement(position, velocity), facesDirection(facesDirection) {
    leaf.setPointCount(4);
    leaf.setFillColor(sf::Color(0, 128, 0));
    leaf.setPoint(0, sf::Vector2f(0, 0));
    leaf.setPoint(1, sf::Vector2f(39 * facesDirection, -30));
    leaf.setPoint(2, sf::Vector2f(81 * facesDirection, -30));
    leaf.setPoint(3, sf::Vector2f(54 * facesDirection, -6));
    leaf.setPosition(position.x, position.y + facesDirection * 5);
    animationDirection = velocity.y * facesDirection;
    pixelsMoved = 0;
}

void Leaf::draw(sf::RenderWindow& window) {
    window.draw(leaf);
}

void Leaf::update(const sf::Time& deltaTime) {
    if (pixelsMoved >= MAX_PIXELS_MOVED) {
        animationDirection *= -1;
        pixelsMoved = -MAX_PIXELS_MOVED;
    }

    leaf.setPoint(1, sf::Vector2f(leaf.getPoint(1).x, leaf.getPoint(1).y + animationDirection));
    leaf.setPoint(2, sf::Vector2f(leaf.getPoint(2).x, leaf.getPoint(2).y + animationDirection));
    leaf.setPoint(3, sf::Vector2f(leaf.getPoint(3).x, leaf.getPoint(3).y + animationDirection));

    pixelsMoved += velocity.y;
}
