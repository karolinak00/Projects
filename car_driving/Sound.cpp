#include "Sound.h"

void Sound::initBuffer(std::string file)
{
	try
	{
		if (!buffer.loadFromFile(file))
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
}

void Sound::initSound()
{
	sound.setBuffer(buffer);
}

Sound::Sound(std::string file)
{
	initBuffer(file);
	initSound();
}

Sound::~Sound()
{

}

void Sound::playSound()
{
	sound.play();
}
