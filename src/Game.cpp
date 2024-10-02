
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	//init text
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "Font failed to load \n";
	}

	//------------------------------------------------------------------------------------
	//init title text
	title_text.setString("Whack-A-Mole");
	title_text.setFont(font);
	title_text.setCharacterSize(100);

	title_text.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2);

	//------------------------------------------------------------------------------------
	//init play text
	play_text.setString("> PLAY <");
	play_text.setFont(font);
	play_text.setCharacterSize(100);
	
	play_text.setPosition(
		(window.getSize().x / 2 - play_text.getGlobalBounds().width / 2) - 100,
		(window.getSize().y / 2 - play_text.getGlobalBounds().height / 2) + 100 );

	//------------------------------------------------------------------------------------
	//init quit text
	quit_text.setString("Quit");
	quit_text.setFont(font);
	quit_text.setCharacterSize(100);

	quit_text.setPosition(
		(window.getSize().x / 2 - quit_text.getGlobalBounds().width / 2) + 100,
		(window.getSize().y / 2 - quit_text.getGlobalBounds().height / 2) + 100);

	//------------------------------------------------------------------------------------
	//init background
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	//if(!background_texture.loadFromFile("D:/Educational/Uni/Year 2/MGiC++/Worksheets/whack-a-mole-year-2/Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "Background texture failed to load \n";
	}
	background.setTexture(background_texture);
	
	//------------------------------------------------------------------------------------
	//init bird
	if (!bird_texture.loadFromFile("../Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "Bird texture failed to load \n";
	}
	bird.setTexture(bird_texture);
	bird.setPosition(500, 100);
	bird.setScale(0.5, 0.5);

  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
	if (in_menu)
	{
		window.draw(title_text);
		window.draw(play_text);
		window.draw(quit_text);
	}
	if(!in_menu)
	{
		window.draw(background);
		window.draw(bird);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Left)
	{
		if (in_menu) 
		{
			if (!play_selected) 
			{
				play_selected = true;
				play_text.setString("> PLAY <");
				quit_text.setString("Quit");

			}
		}
	}
	if (event.key.code == sf::Keyboard::Right)
	{
		if(in_menu) 
			{
			if (play_selected) 
			{
				play_selected = false;
				play_text.setString("Play");
				quit_text.setString("> QUIT <");
			}
			}
	}
	if (event.key.code == sf::Keyboard::Enter)
	{
		if (in_menu)
		{
			if(play_selected)
			{
				in_menu = false;
			}
			if(!play_selected){
				quick_exit;
			}
		}
	}
}


