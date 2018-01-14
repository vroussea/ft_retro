#include "Decor.hpp"

Decor::Decor(void) {
	_type = "Decor";
	_time = 100;
	_friendly = false;

	_random();
}
Decor::Decor(Decor const &d) {
	*this = d;
}
Decor::~Decor(void) {}

Decor	&Decor::operator=(Decor const &d) {
	Entity::operator=(d);
	return *this;
}

Entity	*Decor::run(void) {
	if (_box.getY() >= LINES)
		_time = -1;
	return nullptr;
}

void    Decor::collision(Entity const &e) {
	if (e.getType() == "Player")
		Entity::collision(e);
}

void	Decor::_random(void) {
	int choice = std::rand() % 5;

	_box = _tabBox[choice];
	_sprite = _tabSprite[choice];
	_box.setX(std::rand() % COLS);
	_box.setY(-_box.getH());
}

Box const			Decor::_tabBox[] = {Box(3, 3), Box(1, 1), Box(1, 1), Box(2, 1), Box(6, 3)};
std::string const	Decor::_tabSprite[] = {",o,OOO'o\"", "O", "*", "88", ".OOOO.OooOOO'OOoO'"};

