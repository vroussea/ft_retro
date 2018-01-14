#include "Entity.hpp"

Entity::Entity(void) {}
Entity::Entity(Entity const &e) {
	*this = e;
}
Entity::Entity(int x, int y, int w, int h, std::string sprite) : _box(x, y, w, h), _sprite(sprite), _type("Entity") {}
Entity::~Entity(void) {}

Entity		&Entity::operator=(Entity const &e) {
	_box	= e.getBox();
	_sprite	= e.getSprite();
	_time	= e.getTime();
	return *this;
}

Box			const	&Entity::getBox(void) const {
	return _box;
}

std::string const	&Entity::getSprite(void) const {
	return _sprite;
}

int					Entity::getTime(void) const {
	return _time;
}

void				Entity::setTime(int time) {
    _time = time;
}

bool				Entity::isCollide(Entity const &e) const {
	return _box == e.getBox();
}

void				Entity::collision(Entity const &e) {
	if (isCollide(e))
		_time = -1;
}

bool				Entity::isDead(void) {
	return (_time < 0);
}

void				Entity::move(int x, int y) {
	_box.setX(_box.getX() + x);
	_box.setY(_box.getY() + y);
}

std::string			Entity::getType(void) const {
	return _type;
}

bool                Entity::isFriendly() const {
    return _friendly;
}