//abstract strategy 1
interface Walk{
    String walk();
}

//abstract strategy 2
interface Talk{
    String talk();
}

//abstract strategy 3
interface Run{
    String run();
}

// concrete strategy
class Walkable implements Walk{
    @Override
    public String walk() {
        return "Walking...";
    }
}

// concrete strategy
class NotWalkable implements Walk{
    @Override
    public String walk() {
        return "Can't walk...";
    }
}

// concrete strategy
class Talkable implements Talk{
    @Override
    public String talk() {
        return "Talking...";
    }
}

// concrete strategy
class NotTalkable implements Talk{
    @Override
    public String talk() {
        return "Can't talk...";
    }
}

// concrete strategy
class Runnable implements Run{
    @Override
    public String run() {
        return "Runing...";
    }
}

// concrete strategy
class NotRunnable implements Run{
    @Override
    public String run() {
        return "Can't Run...";
    }
}

class Robot{
    String robotType;
    Walk walk;
    Talk talk;
    Run run;

    Robot(Walk walk,Talk talk,Run run, String robotType) {
        this.robotType = robotType;
        this.walk = walk;
        this.talk = talk;
        this.run = run;
    }

    public void walk(){
        System.out.println(
            walk.walk()
        );
    }
    public void talk(){
        System.out.println(
                talk.talk()
        );
    }
    public void run() {
        System.out.println(
                run.run()
        );
    }
}

class Client {
    private Robot[] robots;
    Client(Robot[] robots){
        this.robots = robots;
    }

    public void performOperations(){
        for(Robot robot : robots) {
            System.out.println(robot.robotType + "Robot Operations: ");
            robot.walk();
            robot.talk();
            robot.run();
        }
    }
}

class StrategyPattern {
    public static void main(String[] args) {
        Robot companion = new Robot(
                new Walkable(),
                new Talkable(),
                new NotRunnable(),
                "Companion"
        );

        Robot worker = new Robot(
                new Walkable(),
                new Talkable(),
                new Runnable(),
                "Worker"
        );

        Robot[] robots = {companion, worker};

        Client newClient = new Client(robots);
        newClient.performOperations();
    }
}