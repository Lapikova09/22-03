#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	static std::string textureFileNames[];
	float speedx, speedy;

public:
	void spawn() {
		float meteorWidth = sprite.getLocalBounds().width;
		float x = rand() % (int)(WINDOW_WIDTH - meteorWidth);
		float y = rand() % (int)(WINDOW_HEIGHT / 2) -
			WINDOW_HEIGHT / 2;
		sprite.setPosition(x, y);
		speedx = rand() % 5 - 2;
		speedy = rand() % 6 + 3;
	}
	Meteor() {
		int index = rand() % 10;
		texture.loadFromFile(textureFileNames[index]);
		sprite.setTexture(texture);
		spawn();
	}

	void update() {
		sprite.move(speedx, speedy);
		sf::Vector2f pos = sprite.getPosition();
		float meteorWidth = sprite.getLocalBounds().width;
		if (pos.x < -meteorWidth || pos.y > WINDOW_HEIGHT ||
			pos.x > WINDOW_WIDTH)
		{
			spawn();
		}
	}

	sf::Sprite& getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	
};
std::string Meteor::textureFileNames[] =
{
	"meteorBrown_big1.png","meteorBrown_big2.png",
	"meteorBrown_big3.png", "meteorBrown_big4.png",
	"meteorBrown_med1.png", "meteorBrown_med3.png",
	"meteorBrown_small1.png", "meteorBrown_small2.png",
	"meteorBrown_tiny1.png","meteorBrown_tiny2.png"
};