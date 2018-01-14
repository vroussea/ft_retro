
#include "Windows.hpp"

Windows::Windows(void) {
	initscr();
	refresh();
	if ((_ifcolor = has_colors())) {
		start_color();
		setColor(0, 255, 255, 255);
		setColor(1, 61, 214, 14);
		setColor(2, 120, 120, 120);
		setColor(3, 132, 15, 15);
	}
	_width = COLS;
	_height = LINES;
	initKey();
	cbreak();
    raw();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	std::srand(std::time(nullptr));
};

Windows::Windows(Windows const & win) {
	*this = win;
};

Windows::~Windows(void) {
	endwin();
};

Windows &		Windows::operator=(Windows const & win) {
	_width = win.getWidth();
	_height = win.getHeight();
	return *this;
};

void			Windows::setColor(int n, int r, int g, int b) {
	int _r = r * 1000 / 0xff;
	int _g = g * 1000 / 0xff;
	int _b = b * 1000 / 0xff;

	if (_ifcolor) {
		n = 1 + n % 7;
		init_color(n, _r, _g, _b);
		init_pair(n, n, COLOR_BLACK);
	}
};

void	Windows::debugKey(int x, int y) {
	int j;

	j = 0;
	choiceColor(6);
	for (int i = 0; i < 0xff; i++)
		if (isKeyPress(i))
			drawText(x, y++, i);
};

void			Windows::choiceColor(int n) {
	attron(COLOR_PAIR(1 + n % 7));
};

char			Windows::getLastKeyPress(void) const {
	return _lastKeyPress;
};

char			Windows::isKeyPress(int key) {
	if (key >= 0 && key < 0xff)
		return _key[key];
	return (0);
};

void			Windows::keyPress(void) {
	char tmp;
    tmp = getch();
	if (tmp >= 0 && (int) tmp < 0xff) {
		_key[(int) tmp] = 1;
		_lastKeyPress = tmp;
	}
};

int				Windows::getWidth(void) const {
	return _width;
};

int				Windows::getHeight(void) const {
	return _height;
};

void			Windows::drawChar(int x, int y, char c) {
	if ((x >= 0 && x < _width) && (y >= 0 && y < _height)) {
		move(y % _height, x % _width);
		addch(c);
	}
};

void			Windows::drawText(int x, int y, std::string const & text) {
	int i;

	i = -1;
	while ((size_t)(++i) < text.length())
		if (x + i >= 0 && x + i < _width)
			drawChar(i + x, y, text[i]);
};

void			Windows::drawText(int x, int y, int nb) {
	std::ostringstream o;

	o << nb;
	drawText(x, y, o.str());
};

void			Windows::drawEntity(Entity const & entity) {
	std::string	color[] = {"", "Player", "Decor", "Enemy"};
	Box const	&box = entity.getBox();
	std::string	sprite = entity.getSprite();
	int			x = box.getX();
	int			y = box.getY();
	size_t		width = box.getW();
	size_t		height = box.getH();

	choiceColor(0);
	for (int c = 0; c < 4; c++)
		if (entity.getType() == color[c])
			choiceColor(c);
	for (size_t j = 0; j < height; j++) {
		for (size_t i = 0; i < width; i++) {
			if (width * j + i < sprite.length())
				drawChar(x + i, y + j, sprite[width * j + i]);
		}
	}
};

void			Windows::initKey(void) {
	_lastKeyPress = ' ';
	for (int i = 0; i < 0xff; i++)
		_key[i] = 0;
};

std::ostream &	operator<<(std::ostream & o, Windows const & win) {
	o << "windows -> width : " << win.getWidth() << "\theight : " << win.getHeight() << std::endl;
	return (o);
};
