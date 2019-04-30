//
// Created by sando on 2019. 04. 29..
//

#ifndef WANDERER_CHARACTER_H
#define WANDERER_CHARACTER_H


class Character {
public:
    int getMaxHealthPoint() const;
    int getCurrentHealthPoint() const;
    int getDefendPoint() const;
    int getStrikePoint() const;
    int getLevel() const;
    int getXOfCharacter() const;
    int getYOfCharacter() const;

    void setMaxHealthPoint(int maxHealthPoint);
    void setCurrentHealthPoint(int currentHealthPoint);
    void setDefendPoint(int defendPoint);
    void setStrikePoint(int strikePoint);
    void setLevel(int level);
    void setXOfCharacter(int xOfCharacter);
    void setYOfCharacter(int yOfCharacter);

protected:
    int _maxHealthPoint;
    int _currentHealthPoint;
    int _defendPoint;
    int _strikePoint;
    int _level;
    int _xOfCharacter;
    int _yOfCharacter;
    int _screenSize = 800;

};


#endif //WANDERER_CHARACTER_H
