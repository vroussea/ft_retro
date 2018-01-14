#ifndef ENTITYGROUP_HPP
# define ENTITYGROUP_HPP

# include "Bullet.hpp"
# include "Player.hpp"
# include "Decor.hpp"
# include "Enemy.hpp"

# define SIZE_GROUP 512

class EntityGroup {

public:
	EntityGroup(void);
	EntityGroup(EntityGroup const *e);
	~EntityGroup(void);

	EntityGroup	&operator=(EntityGroup const &e);

	Entity		*getElem(int i) const;
	int			length(void) const;
    int			nb_type(std::string type) const;

	void		collision(void);
	void		run(void);
	void		destroy(void);
	void		down(void);
	void		scrolling(void);
	void		append(Entity *e);
	void		remove(size_t i);
	void		waveEnemy(int nbX, int nbY, int space);

private:
	Entity			*_group[SIZE_GROUP];
	size_t			_nb;
	unsigned int	_count;

};

#endif