#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Bullet.hpp"
# include "Windows.hpp"
# include "Entity.hpp"
# include <cstdlib>

class Enemy : public Entity {

public:

	Enemy(Enemy const &e);
	Enemy(int x, int y);
	~Enemy(void);

	Enemy	&operator=(Enemy const &e);

	virtual Entity	*run();
	virtual	void	collision(Entity const &e);

	std::string		creaPath(char const *path, size_t len);

	void			left(void);
	void			down(void);
	void			right(void);

private:
	Enemy(void);
	std::string	_path;
	int			_index;
	int			_speed;
	int			_counterAction;
    int         _nextShoot;

};

#endif