/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:57:38 by vroussea          #+#    #+#             */
/*   Updated: 2018/01/13 16:57:38 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) : Entity(COLS / 2, LINES - 2, 1, 1, "A"), _dead(false) {
    this->_type = "Player";
    _friendly = true;
    this->_dir = NEUTRAL;
    this->_time = 0;
}

Player::Player(int) {
    _type = "Player";
}

Player::Player(Player const &src) {
    *this = src;
}

Player::~Player(void) {

}

Entity	*Player::run() {
    if (this->_dir == LEFT) {
        if (_box.getX() > 0)
            _box.setX(_box.getX() - 1);
    } else if (this->_dir == RIGHT) {
        if (_box.getX() < COLS - 1)
            _box.setX(_box.getX() + 1);
    }
    if (this->_time >= 8) {
        this->_time = 0;
        return new Bullet(this->_box.getX(), this->_box.getY(), true);
    }
    else
        this->_time++;
    return nullptr;
}

void    Player::setDir(Windows &windows) {
    if (windows.isKeyPress(LEFT)) {
        this->_dir = LEFT;
    }
    else if(windows.isKeyPress(RIGHT)) {
        this->_dir = RIGHT;
    }
    else
        this->_dir = NEUTRAL;
}

bool	Player::isDead(void) {
    return _dead;
}

void    Player::collision(Entity const &e) {
    if (isCollide(e))
        _dead = true;
}


Player &Player::operator=(Player const &) {
    return *this;
}