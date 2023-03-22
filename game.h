#pragma once
#include "settings.h"
#include "meteor.h"
#include <vector>
#include "Player.h"

class Game {
public:

	Game() {
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(METEORS_QTY);
		for (int i = 0; i < METEORS_QTY; i++) {
			meteorSprites.push_back(new Meteor());
		}
		
	}

	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}

private:

	sf::RenderWindow window;
	std::vector<Meteor*> meteorSprites;
	Player player;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update() {
		for (auto meteor : meteorSprites) {
			meteor->update();
		}
		player.update();
	}

	void checkCollisions() {
		sf::FloatRect playerBounds = player.getHitBox();
		for (auto& meteor : meteorSprites) {
			sf::FloatRect meteorBounds = meteor->getHitBox();
			if (meteorBounds.intersects(playerBounds)) {
				meteor->spawn();
				if(meteorBounds.width>90 && meteorBounds.width<130){ player.hpChange1(); }
				if(meteorBounds.width > 40 && meteorBounds.width < 50) { player.hpChange2(); }
				if (meteorBounds.width > 15 && meteorBounds.width < 30) { player.hpChange3(); }
			}
		}

	}

	void draw() {
		window.clear();
		for (auto meteor : meteorSprites) {
			window.draw(meteor->getSprite());
		}
		player.draw(window);
		window.display();
	}
};