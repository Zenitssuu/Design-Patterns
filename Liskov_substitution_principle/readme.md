# LSP (Liskov Substitution principle)

## It is one of the pillar of design pattern

### It states that:

    Sub-classes should be able to substitue for their base classes.

## Explaination

    Inheritance says that a child/sub class should always try to expand the domain of parent class but never narrow it.

    Eg:
        class Parent{
            method m1();
            method m2();
            method m3();
        }

        class Child: public Parent{

            //these are all A's method
            method m1();
            method m2();
            method m3();

            //B's method
            method m4();
            method m5();
        }

    here B can replace A because it has all the features of A.


    Problem (where it gets violated):
        class Acc{
            deposti();
            withdraw();
        }

        class savingAcc() : public Acc{
            deposit();
            withdraw();
        }

        class currentAcc() : public Acc{
            deposit();
            withdraw();
        }

        class fixedDepAcc() : public Acc{
            deposit();
            withdraw(); //withdrawl is not possible in fixed deposit acccount for a certain period of time

            //now this violated the LSP because it is narrowing the functionality of the parent class and this class can't replace the base class
        }

    To solve this we use:

    Method 1(wrong way):
        Make changes in client, but this will make the system tightly coupled which is not a good thing.


    Method 2(correct way):
        We have to change the structre of the system that we are building.

        class nonWithDrawAcc{
            deposit();
        }

        class withDrawAcc: public nonWithDrawAcc{
            withdraw();
        }

        class saving : public withDrawAcc{
            deposit();
            withdraw();
        }
        class current : public withDrawAcc{
            deposit();
            withdraw();
        }
        class fixedDep : public nonWithDrawAcc{
            deposit();
        }

    now this has solved the LSP violation, where child class is behaving like a parent class.

## Guidelines for LSP

    1. Signature rule
    2. Property rule
    3. Method rule

## Signature rule

    Method argument, return type are collectively known as signature of a class.

    It has 3 conditions:

#### Method argument rule:

    To override a method of a parent class argument domain should be atleast same as parent class or broader.

    for e.g:
        class Parent{
            void solve(string s){}
        }

        class Child: public Parent{
            void solve(argument_type s) override {
                //the argument_type should be atleast string or something which has larger domain
            }
        }

#### Return Type rule:

    To override a method of a parent class return type domain should not be broader than the parent class's method return type.

    class Organism{

    }
    class Animal: public Organism{

    }
    class Dog: public Animal{

    }

    class Parent{
        Animal method(){}
    }

    class Child : public Parent{
        return_type method()override{
            the return type can be at max Animal, it can't be Organism or something higher
        }
    }

#### Exception rule:

    To override a method of a parent class, if parent method is throwing some execetion then child class should not throw exception which has broader domain than that.


## Property Rule
    It has 2 condition:

#### Class Invariant
    It means rules decided in parent class should be followed as it is or it can be strengthen but not weaken.

    These are rules written in comments, not some strict rule

    eg:
        class Account{
            amount; //always >=0
        }

        class Child : public Account{
            amount = -1; //this is violating the class invariant rule
        }

#### History constraint
    It means state declared in parent class should not be changed.

    eg:
        class Account{
            deposit();
            withdraw();
        }

        class fixedDeposit : public Account{
            //we can't change the state/def of withdraw in fixedDep
        }




## Method Rule
    It has 2 conditons:

#### Pre-condition:
    If we have some pre condition for a method then the condition should be statisfied first.
    And child classes should follow this conditions but not strengthen it.

#### Post-condition:
    If we have some post condition for a method then the condition should be statisfied first.
    And child classes should follow this conditions but not weaken it.

