#ifndef BULLET_HPP
# define BULLET_HPP

# include "Windows.hpp"
# include "Entity.hpp"

class Bullet: public Entity {

public:
	Bullet(Bullet const &b);
	Bullet(int x, int y, bool);
	virtual ~Bullet(void);

	Bullet	&operator=(Bullet const &b);

	virtual Entity	*run();
	virtual	void	collision(Entity const &e);

private:
	Bullet(void);
};

#endif