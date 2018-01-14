#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <iostream>
# include "Box.hpp"

class Entity {

public:

	Entity(Entity const &e);
	Entity(int x, int y, int w, int h, std::string sprite);
	virtual ~Entity(void);

	Entity	&operator=(Entity const &e);

	std::string const	&getSprite(void) const;
	Box const			&getBox(void) const;
	int					getTime(void) const;
    void                setTime(int);
	bool				isCollide(Entity const &e) const;
	void				move(int x, int y);

	virtual Entity		*run() = 0;
	std::string			getType(void) const;
	virtual	void		collision(Entity const &e);
	virtual bool		isDead(void);
    bool			    isFriendly() const;


protected:
	Entity(void);

	int			_time;
	Box			_box;
	std::string	_sprite;
	std::string	_type;
    bool	_friendly;
};

#endif