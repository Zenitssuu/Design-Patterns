# OCP (Open-Close principle)

## It is one of the pillar of design pattern

### It states that:
    1. A class should be open for extension but not for modification.

## Explaination
    Now that we have implemented SRP, we have 3 different features, which are:
    1. Calculate total price
    2. Print Invoice
    3. Save to DB

    Now if want to save the cart into multiple DBs, SQL DB, NOSQL DB, and file.
    We will not implement every storing functionality to same class which is saveToDB because it will violate OCP.

    To solve this we will use Polymorphism, Inheritance and Abstraction.

    We will create a abstract class(cpp)/interface(java) which will help to implement virtaul methods(cpp)/abstract methods(java), methods in which we can declare methods in parent/base class and define it in sub/child classes, using this we will declare a save method in base class and inherited classes will define it as per their requirements.

    Now each operation will have its own classes where they can perform operation without getting affected by others.

    It is not strictly followed in industry but better to follow.