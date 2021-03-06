#include "Background.h"

namespace TT
{
	Background::Background()
	{
		_object = nullptr;
	}
	Background::Background(float speed, const std::string path)
	{
		_object = World::CreateSprite(path);
		_object->setOrigin(0.5f*World::GetInstance()->GetView()->getSize().x, _object->getLocalBounds().height*0.5f);
		_speed = speed;
	}

	Background::~Background()
	{
		delete _object;
	}

	void Background::Draw(sf::RenderWindow *window)
	{
		if(!_object)
		{
			return;
		}

		sf::Vector2f center;
		center = window->getView().getCenter();
		_object->setPosition(center.x * GetSpeed(), 0.0f);
		window->draw(*_object);
	}

	void Background::Update(float timeStep)
	{

	}
}