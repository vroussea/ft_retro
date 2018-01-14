#include "Box.hpp"

Box::Box(void) : _x(0), _y(0), _w(0), _h(0) {}
Box::Box(int w, int h) : _x(0), _y(0), _w(w), _h(h) {}
Box::Box(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {}
Box::Box(Box const &b) {
	*this = b;
}
Box::~Box(void) {}


Box		&Box::operator=(Box const &b) {
	if (this != &b) {
		this->_x = b.getX();
		this->_y = b.getY();
		this->_w = b.getW();
		this->_h = b.getH();
	}
	return *this;
}

bool	Box::operator==(Box const &b) const {
	Box const &box1 = *this;
	Box	const &box2 = b;

	if ((box2.getX() >= box1._x + box1._w)			// trop à droite
		|| (box2.getX() + box2.getW() <= box1._x)	// trop à gauche
		|| (box2.getY() >= box1._y + box1._h)		// trop en bas
		|| (box2.getY() + box2.getH() <= box1._y))	// trop en haut
		return false; 
	else
		return true; 
}

bool	Box::operator!=(Box const &b) const {
	return !operator==(b);
}

int		Box::getX(void) const {
	return _x;
}
int		Box::getY(void) const {
	return _y;
}
int		Box::getW(void) const {
	return _w;
}
int		Box::getH(void) const {
	return _h;
}

void	Box::setX(int x) {
	_x = x;
}
void	Box::setY(int y) {
	_y = y;
}
void	Box::setW(int w) {
	_w = w;
}
void	Box::setH(int h) {
	_h = h;
}