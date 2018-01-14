#ifndef DECOR_HPP
# define DECOR_HPP

# include <iostream>
# include "Box.hpp"
# include "Entity.hpp"
# include "Windows.hpp"

class Decor : public Entity {

public:
	Decor(void);
	Decor(Decor const &d);
	virtual ~Decor(void);

	Decor	&operator=(Decor const &d);


    virtual Entity	*run(void);
    virtual void    collision(Entity const &e);

private:
	void	_random(void);

	static const Box			_tabBox[];
	static const std::string	_tabSprite[];

};

#endif