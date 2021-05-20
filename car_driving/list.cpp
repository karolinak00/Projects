#include "list.h"

void list::initFont()
{
	try
	{
		if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
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

void list::initText()
{
	text.setPosition(sf::Vector2f(80, 120));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setFont(font);
}

list::list() : pHead(0)
{
	initFont();
	initText();
}

list::~list() {}

list::list(Stats* p) : pHead(p) {}

list::list(const list& s)
{
	pHead = s.pHead;
}

list::list(list&& s) noexcept
{
	if (this != &s)
		pHead = s.pHead;
}

list& list::operator=(const list& s)
{
	pHead = s.pHead;
	return *this;
}

list& list::operator=(list&& s) noexcept
{
	pHead = s.pHead;
	return *this;
}

void list::load(Stats*& pHead)
{
	std::ifstream file;
	try
	{
		file.open("statistics.txt");
		if (!file.is_open())
			throw 1;
	}
	catch (int)
	{
		exit(0);
	}
	catch (std::fstream::failure& error)
	{
		std::cout << error.what() << std::endl;
	}
	std::string line, name;
	int score;
	int counter = 0;

	while (std::getline(file, line))
	{
		if (counter == 0)
		{
			name = line;
			counter++;
		}
		else
		{
			score = std::stoi(line);
			add(pHead, name, score);
			counter = 0;
		}
	}

	file.close();
}

void list::try_to_add(Stats*& pHead, const std::string& name, const int& score)
{
	if (score > 0)
	{
		auto ptr = find(pHead, name);
		if (!ptr)
			add(pHead, name, score);
		else
		{
			if (ptr->getScore() < score)
			{
				delete_record(pHead, ptr);
				add(pHead, name, score);
			}
		}
	}
}

void list::add(Stats*& pHead, const std::string& name, const int& score)
{
	if (!pHead || (pHead->getScore() < score))
	{
		auto p = pHead;
		pHead = new Stats;
		pHead->setVariables(name, score);
		pHead->pNext = p;
	}
	else
		add(pHead->pNext, name, score);
}

Stats* list::find(Stats* pHead, const std::string& name)
{
	if (pHead)
	{
		if (pHead->getName() == name)
			return pHead;

		else
			find(pHead->pNext, name);
	}
	else
		return 0;
}

void list::delete_stats(Stats*& pHead)
{
	if (pHead)
	{
		auto p = pHead;
		pHead = pHead->pNext;
		delete p;
		p = 0;
		delete_stats(pHead);
	}
}

void list::prepare_to_print(Stats*& pHead, std::string& s, int counter)
{
	if (pHead && counter <= 20)
	{
		s = s + pHead->getName() + " score: " + std::to_string(pHead->getScore()) + "\n";
		prepare_to_print(pHead->pNext, s, ++counter);
	}
}

void list::print(sf::RenderTarget* target)
{
	std::string s = "";
	prepare_to_print(pHead, s, 0);
	text.setString(s);
	target->draw(text);

}

void list::save(Stats*& pHead)
{
	open_close_file(pHead);
}

void list::open_close_file(Stats*& pHead)
{
	std::fstream file;
	try
	{
		file.open("statistics.txt", std::ios::trunc | std::ios::out);
		if (!file.is_open())
			throw 1;
	}
	catch (std::fstream::failure& error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (int)
	{
		exit(0);
	}
	actual_save(pHead, file, 0);
	file.close();
}

void list::delete_record(Stats*& pHead, Stats*& s)
{
	if (pHead)
	{
		if (pHead == s)
		{
			auto p = pHead;
			pHead = pHead->pNext;
			delete p;
			p = 0;
		}
		else
			delete_record(pHead->pNext, s);
	}
}

void list::actual_save(Stats*& pHead, std::fstream& file, int counter)
{
	if (pHead && counter <= 20)
	{
		file << pHead->getName() << std::endl << pHead->getScore() << std::endl;
		actual_save(pHead->pNext, file, ++counter);
	}
}