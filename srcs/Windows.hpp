#ifndef WINDOWS_HPP
# define WINDOWS_HPP

# include <ncurses.h>
# include <iostream>
# include <sstream>
# include <ctime>
# include "Entity.hpp"

# define QUIT	0x20
# define FPS	25

class Windows {

public:

	Windows(void);
	Windows(Windows const & win);
	~Windows(void);

	Windows &	operator=(Windows const & win);

	void			setColor(int n, int r, int g, int b);
	
	int				getWidth(void) const;
	int 			getHeight(void) const;
	char			getLastKeyPress(void) const;
	
	void			choiceColor(int n);
	char			isKeyPress(int key);
	void			keyPress(void);

	void			drawChar(int x, int y, char c);
	void			drawText(int x, int y, std::string const & text);
	void			drawText(int x, int y, int nb);
	void			drawEntity(Entity const & entity);

	void			debugKey(int x, int y);
	void			initKey(void);

	void			_initKey(void);
private:

	int				_width;
	int				_height;
	bool			_ifcolor;
	char			_lastKeyPress;
	char			_key[0xff];

};

std::ostream &	operator<<(std::ostream & o, Windows const & win);

#endif
