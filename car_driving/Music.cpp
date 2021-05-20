#include "Music.h"

Music::Music(std::string file)
{
	try
	{
		if(!music.openFromFile(file))
			throw 1;
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (int)
	{
		exit(0);
	}
	music.setLoop(true);
}

Music::~Music() {}

void Music::playMusic()
{
	music.play();
}
