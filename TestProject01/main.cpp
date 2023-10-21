#include <iostream>
#include <string>
#include <list>
#include "Entity.hpp"

int main()
{
    std::list<Entity*> entities;
    entities = std::list<Entity*>();

    Vector2 testVector;
    testVector = Vector2(10.0f, 10.0f);
    testVector += Vector2(35.0f, 56.0f);

    if (testVector == Vector2(45.0f, 66.0f)) std::cout << "Vector2 operator overloading test: positive\n";
    else std::cout << "Vector2 operator overloading test: negative\n";

    Entity entity;
    entity = Entity(150, "An Entity", testVector);
    entities.push_back(&entity);

    Monster monster;
    monster = Monster(250, "A Monster", testVector, 15.0f);
    entities.push_back(&monster);

    Robot robot;
    robot = Robot(95, "A Robot", testVector, 10, 30.0f);
    entities.push_back(&robot);

    Cyborg cyborg;
    cyborg = Cyborg(400, "A Cyborg", testVector, 55.0f, 100, 50.0f, "iCyborg 6000A");
    entities.push_back(&cyborg);

    monster.MeleeAttack(entity);
    robot.RangedAttack(monster);
    cyborg.DoubleAttack(robot);

    for (std::list<Entity*>::iterator it=entities.begin(); it!=entities.end(); it++)
    {
        (*it)->ShowInformation();
    }
}