/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:57:25 by vroussea          #+#    #+#             */
/*   Updated: 2018/01/13 22:03:25 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

# include "Windows.hpp"
# include "Entity.hpp"
# include "Bullet.hpp"
# include <ncurses.h>

# define LEFT	68
# define RIGHT  67
# define NEUTRAL 0

class Player : public Entity {
public:
    Player(void);

    virtual ~Player(void);

    virtual Entity	*run();
    virtual bool	isDead(void);
    virtual void    collision(Entity const &e);

    void            setDir(Windows &windows);

    void    fire_bullet() const;
private:
    Player(int);
    Player(Player const &src);

    Player &operator=(Player const &);

    int             _dir;
    int             _time;
    bool            _dead;
};

#endif
