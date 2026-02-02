# DIP (Dependency Inversion principle)

## It is one of the pillar of design pattern

### It states that:
    1. High level module should not depend on low level module directly instead both should depend on abstraction.

## Explaination
    Lets say we want a system where it can save data to DB,

#### Method 1(violating DIP):
    Application is directly connected to DB. Now if we want to change in structre, we want to use multiple DB and different type of DB(sql + nosql), it will violated OCP if we try to modify the applicaition.

#### Method 2(satisyfing DIP):
    To solve this above problem we will inrtodcue interface which will act as abstraction for both.

    class Persistance{
        save();
    }

    class nosql : public persistance{
        save();
    }

    class sql : public persistance{
        save();
    }

    now high level modules will connect with interface and rest of the workings will be abstract for the high level module.

    If we want to achieve OCP then DIP is the procedure, we must have not violated DIP for OCP to follow.