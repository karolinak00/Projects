#include "Collision.h"

void Collision::initObstacle()
{
	o = std::make_shared<Obstacle>();
}

Collision::Collision()
{
	initObstacle();
	slower = 0;
	faster = 0;
	more = 0;
}

Collision::~Collision()
{
	for (auto i = obstacles.begin(); i != obstacles.end(); )
	{
		delete* i;
		i = obstacles.erase(i);
	}
}

void Collision::spawnObstacles()
{
	int size = o->getMaxObstacles();
	if (obstacles.size() < size)
	{
		Obstacle* ptr = 0;
		int tmp = random.get_random_number(0, 5);
		if (tmp == 0)
			ptr = new Dog();
		else if (tmp == 1)
			ptr = new Bonus();
		else if (tmp == 2)
			ptr = new Cat();
		else if (tmp == 3)
			ptr = new Pedestrian();
		else if (tmp == 4)
			ptr = new Puddle();
		else
			ptr = new Car();
		obstacles.push_back(ptr);
	}
}

void Collision::collision(std::shared_ptr<Player> player)
{
	for (auto i = obstacles.begin(); i != obstacles.end(); )
	{
		if (Bonus* obj = dynamic_cast<Bonus*>(*i))
		{
			if (player->getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds()))
			{
				player->getHp()->substractHp(obj->get_damage());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Car* obj = dynamic_cast<Car*>(*i))
		{
			if (player->getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds()))
			{
				player->getHp()->substractHp(obj->get_damage());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Cat* obj = dynamic_cast<Cat*>(*i))
		{
			if (player->getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds()))
			{
				player->getHp()->substractHp(obj->get_damage());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Dog* obj = dynamic_cast<Dog*>(*i))
		{
			if (player->getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds()))
			{
				player->getHp()->substractHp(obj->get_damage());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Pedestrian* obj = dynamic_cast<Pedestrian*>(*i))
		{
			if (player->getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds()))
			{
				player->getHp()->substractHp(obj->get_damage());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Puddle* obj = dynamic_cast<Puddle*>(*i))
		{
			if (player->getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds()))
			{
				player->getHp()->substractHp(obj->get_damage());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
	}
}

void Collision::delete_from_scene(std::shared_ptr<Player> player)
{
	for (auto i = obstacles.begin(); i != obstacles.end(); )
	{
		if (Car* obj = dynamic_cast<Car*>(*i))
		{
			if (obj->getSprite().getGlobalBounds().top < -100)
			{
				player->getPoints()->addPoints(obj->get_points());
				delete* i;
				i = obstacles.erase(i);
			}

			else
				++i;
		}
		else if (Puddle* obj = dynamic_cast<Puddle*>(*i))
		{
			if (obj->getSprite().getGlobalBounds().top > 1100)
			{
				player->getPoints()->addPoints(obj->get_points());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Pedestrian* obj = dynamic_cast<Pedestrian*>(*i))
		{
			if (obj->getSprite().getGlobalBounds().left > 1150)
			{
				player->getPoints()->addPoints(obj->get_points());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Bonus* obj = dynamic_cast<Bonus*>(*i))
		{
			if (obj->getSprite().getGlobalBounds().left < -100)
			{
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Dog* obj = dynamic_cast<Dog*>(*i))
		{
			if (obj->getSprite().getGlobalBounds().top > 1100)
			{
				player->getPoints()->addPoints(obj->get_points());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
		else if (Cat* obj = dynamic_cast<Cat*>(*i))
		{
			if (obj->getSprite().getGlobalBounds().top > 1100)
			{
				player->getPoints()->addPoints(obj->get_points());
				delete* i;
				i = obstacles.erase(i);
			}
			else
				++i;
		}
	}
}

void Collision::update(std::shared_ptr<Player> player, std::shared_ptr<Background> background, sf::RenderTarget* target)
{
	make_harder(player, background);
	updateObstacles();
	collision(player);
	delete_from_scene(player);
	spawnObstacles();
}

void Collision::make_harder(std::shared_ptr<Player> player, std::shared_ptr<Background> background)
{
	if (player->getPoints()->getPoints() % 200 == 0 && slower == 0 && player->getPoints()->getPoints() != 0)
	{
		player->slowTheCar();
		background->faster_background();
		slower = 1;
	}

	else if (player->getPoints()->getPoints() % 100 == 0 && more == 0 && player->getPoints()->getPoints() != 0)
	{
		o->addObstacles();
		more = 1;
	}

	else if (player->getPoints()->getPoints() % 50 == 0 && faster == 0 && player->getPoints()->getPoints() != 0)
	{
		o->accelerate();
		faster = 1;
	}

	if (player->getPoints()->getPoints() % 200 != 0 && slower == 1)
		slower = 0;
	if (player->getPoints()->getPoints() % 100 != 0 && more == 1)
		more = 0;
	if (player->getPoints()->getPoints() % 50 != 0 && faster == 1)
		faster = 0;
}

void Collision::updateObstacles()
{
	for (auto i : obstacles)
	{
		if (Bonus* obj = dynamic_cast<Bonus*>(i))
			obj->update();
		else if (Car* obj = dynamic_cast<Car*>(i))
			obj->update();
		else if (Cat* obj = dynamic_cast<Cat*>(i))
			obj->update();
		else if (Dog* obj = dynamic_cast<Dog*>(i))
			obj->update();
		else if (Pedestrian* obj = dynamic_cast<Pedestrian*>(i))
			obj->update();
		else if (Puddle* obj = dynamic_cast<Puddle*>(i))
			obj->update();
	}
}

void Collision::render(sf::RenderTarget* target)
{
	for (auto i : obstacles)
	{
		if (Puddle* obj = dynamic_cast<Puddle*>(i))
			obj->render(target);
		else 	if (Bonus* obj = dynamic_cast<Bonus*>(i))
			obj->render(target);

		else if (Cat* obj = dynamic_cast<Cat*>(i))
			obj->render(target);

		else if (Dog* obj = dynamic_cast<Dog*>(i))
			obj->render(target);

		else if (Pedestrian* obj = dynamic_cast<Pedestrian*>(i))
			obj->render(target);

		else if (Car* obj = dynamic_cast<Car*>(i))
			obj->render(target);
	}
}
