#include "Enemy.hpp"

Enemy::Enemy(void) {}
Enemy::Enemy(Enemy const &b) {
	*this = b;
}
Enemy::Enemy(int x, int y) : Entity(x, y, 1, 1, "W"), _index(0), _speed(10), _counterAction(0) {
	char const	path[] = {10, '>', 5, 'v', 10, '<', 5, 'v'};

	_path = creaPath(path, 4);
	_time = 0;
	_type = "Enemy";
    _friendly = false;
    _nextShoot = rand() % 10 + 20;
}
Enemy::~Enemy(void) {}

Enemy	&Enemy::operator=(Enemy const &b) {
	Entity::operator=(b);
	_time = b.getTime();
	return *this;
}

Entity	*Enemy::run() {
	void		(Enemy::*f[])(void) = {&Enemy::left, &Enemy::down, &Enemy::right};
	char const	actions[] = {'<', 'v', '>'};

	if (!(_counterAction % _speed)) {
        for (int i = 0; i < 3; i++)
            if (actions[i] == _path[_index])
                (this->*f[i])();
        if (_box.getY() >= LINES)
            _time = -1;

        _index = (_index + 1) % _path.length();
    }
    if (this->_time >= _nextShoot && _box.getY() > 0) {
        this->_time = 0;
        _nextShoot = std::rand() % 10 + 40;
        _counterAction++;
        return new Bullet(this->_box.getX(), this->_box.getY(), false);
    }
	_counterAction++;
	return nullptr;
}

std::string	Enemy::creaPath(char const *path, size_t len) {
	std::string tmp = "";

	for (size_t i = 0; i < len * 2; i+= 2) {
		for (int j = 0; j < path[i]; j++)
			tmp += path[i + 1];
	}
	return tmp;
}

void		Enemy::collision(Entity const &e) {
	if (e.getType() != "Enemy" && e.getType() != "Decor" && (e.getType() == "Bullet" && e.isFriendly()))
        Entity::collision(e);
}

void	Enemy::down(void) {
	_box.setY(_box.getY() + 1);
}
void	Enemy::left(void) {
	if (_box.getX() > 0)
		_box.setX(_box.getX() - 1);
}
void	Enemy::right(void) {
	if (_box.getX() < COLS)
		_box.setX(_box.getX() + 1);
}
