#include "EntityGroup.hpp"

EntityGroup::EntityGroup(void) : _nb(0), _count(0) {}
EntityGroup::EntityGroup(EntityGroup const *e) {
	*this = e;
}
EntityGroup::~EntityGroup(void) {
}

EntityGroup	&EntityGroup::operator=(EntityGroup const &e) {
	_nb = e.length();
	for (size_t i = 0; i < _nb; i++)
		_group[i] = e.getElem(i);
	return *this;
}

Entity		*EntityGroup::getElem(int i) const {
	return _group[i];
}

int			EntityGroup::length(void) const {
	return _nb;
}

int			EntityGroup::nb_type(std::string type) const {
    size_t  i = 0;
    int     nb_type = 0;
    while (i < _nb) {
        if (_group[i]->getType() == type)
            nb_type++;
        i++;
    }

    return nb_type;
}

void		EntityGroup::collision(void) {
	Entity	*tmp;

	for (size_t i = 0; i < _nb; i++) {
		tmp = _group[i];

		for (size_t j = 0; j < _nb; j++)
			if (i != j)
				tmp->collision(*_group[j]);
	}
}

void		EntityGroup::run(void) {
	if (!(_count % 2))
		scrolling();
	collision();
	for (size_t i = 0; i < _nb;)
		if (!_group[i]->isDead()) {
            _group[i]->setTime(_group[i]->getTime() + 1);
			append(_group[i]->run());
			i++;
		}
		else
			remove(i);
	if (!(_count % 30))
		append(new Decor);
	if (!(_count % 300))
		waveEnemy(10, 2, 3);
	_count++;
}

void		EntityGroup::scrolling(void) {
	for (size_t i = 0; i < _nb; ++i)
		if (_group[i]->getType() == "Decor")
			_group[i]->move(0, 1);
}

void		EntityGroup::append(Entity *e) {
	if (e) {
		if (_nb < SIZE_GROUP) {
			_group[_nb] = e;
			_nb++;
		}
	}
}

void		EntityGroup::waveEnemy(int nbX, int nbY, int space) {
	int pos = std::rand() % (COLS - (nbX * space) / 2);

	for (int j = 0; j < nbY; j++)
		for (int i = 0; i < nbX; i++)
			append(new Enemy(pos + space * i, -(j + 1)));
}

void		EntityGroup::remove(size_t i) {
	if (i < _nb) {
		if (_group[i]->getType() != "Player")
			delete _group[i];
		for (size_t j = i + 1; j < _nb; j++)
			if (j < SIZE_GROUP)
				_group[j - 1] = _group[j];
		_nb--;
		_group[_nb] = NULL;
	}	
}