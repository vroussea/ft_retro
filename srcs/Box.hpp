#ifndef BOX_HPP
# define BOX_HPP

class Box {

public:
	Box(void);
	Box(Box const &b);
	Box(int w, int h);
	Box(int x, int y, int w, int h);
	~Box(void);

	Box		&operator=(Box const &b);
	bool	operator==(Box const &b) const;
	bool	operator!=(Box const &b) const;

	int		getX(void) const;
	int		getY(void) const;
	int		getW(void) const;
	int		getH(void) const;

	void	setX(int x);
	void	setY(int y);
	void	setW(int w);
	void	setH(int h);

private:
	int _x;
	int	_y;
	int	_w;
	int	_h;
};

#endif