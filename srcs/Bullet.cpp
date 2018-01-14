#include "Bullet.hpp"

Bullet::Bullet(void) {}
Bullet::Bullet(Bullet const &b) {
	*this = b;
}
Bullet::Bullet(int x, int y, bool friendly) : Entity(x, y, 1, 1, "|") {
	_time = 1000;
	_friendly = friendly;
    _type = "Bullet";
    _time = 0;
}
Bullet::~Bullet(void) {}

Bullet	&Bullet::operator=(Bullet const &b) {
	Entity::operator=(b);
	_time = b.getTime();
	return *this;
}

Entity	*Bullet::run() {
	if (_friendly) {
		_box.setY(_box.getY() - 1);
		if (this->_box.getY() <= 0)
			_time = -1;
	}
	else {
		_box.setY(_box.getY() + 1);
		if (this->_box.getY() >= LINES)
			_time = -1;
	}
	return nullptr;
}

void		Bullet::collision(Entity const &e) {
    if (_friendly) {
        if (e.getType() != "Player")
            Entity::collision(e);
    }
    else {
        if (e.getType() != "Enemy")
            Entity::collision(e);
    }
}