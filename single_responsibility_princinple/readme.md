# SRP (single responsibility principle)

## It is one of the pillar of design pattern

### It states that:
    1. A class should have only one reason to change.

    2. A class should do only one thing or should have only one responsibility.

## Explaination
    Let say we have a product class and cart class. Each client will have its own cart which can have multiple products.

    Now lets say in cart we want user to give 3 features,
    1. Calculate total price
    2. Print invoice
    3. Save to DB

    Now later on if want to change any specific feature then we have to change the structre of class which violates the SRP and it can lead to bugs.

    We will use Composition to solve this issue, using composition we will implement SRP.
    
    SRP where we create separate classes for each feature.