#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
    std::string username;
    std::string charClass;
    int health;
    int attack;
    int speed;

public:
    std::string getUsername()
    {
        return this->username;
    }
    std::string getClass()
    {
        return this->charClass;
    }
    void setHealth(int newHealth)
    {
        this->health = newHealth;
    }
    int getHealth()
    {
        return this->health;
    }
    int getAttack()
    {
        return this->attack;
    }
    int getSpeed()
    {
        return this->speed;
    }

    Player(std::string username, std::string charClass)
    {
        this->username = username;
        this->charClass = charClass;

        if (this->charClass == "Fighter")
        {
            this->health = 100; // Low health
            this->attack = 80;  // High attack
            this->speed = 25;   // Medium dodge
        }
        else if (this->charClass == "Guardian")
        {
            this->health = 200; // High health
            this->attack = 60;  // Medium attack
            this->speed = 10;   // Low dodge
        }
        else if (this->charClass == "Wizard")
        {
            this->health = 150; // Medium health
            this->attack = 40;  // Low attack
            this->speed = 30;   // High-ish dodge
        }
    }
};

class Enemy
{
private:
    std::string enemyClass;
    int health;
    int attack;
    int speed;

public:
    std::string getClass()
    {
        return this->enemyClass;
    }
    int getHealth()
    {
        return this->health;
    }
    void setHealth(int newHealth)
    {
        this->health = newHealth;
    }
    int getAttack()
    {
        return this->attack;
    }
    int getSpeed()
    {
        return this->speed;
    }

    Enemy(std::string enemyClass)
    {
        this->enemyClass = enemyClass;

        if (this->enemyClass == "Zombie")
        {
            this->health = 150; // Medium health
            this->attack = 60;  // Medium attack
            this->speed = 25;   // Medium dodge
        }
        else if (this->enemyClass == "Dragon")
        {
            this->health = 100; // Low health
            this->attack = 60;  // Medium attack
            this->speed = 35;   // High dodge
        }
        else if (this->enemyClass == "Golem")
        {
            this->health = 200; // High health
            this->attack = 60;  // Medium attack
            this->speed = 10;   // Low dodge
        }
    }
};

void newGame();
std::string getUsername();
std::string getCharClass();
void beginBattle(Player player, Enemy enemy);
void beginBattle(Player player, std::vector<Enemy> &enemies);
void quitGame();

int main()
{
    srand(time(0));

    std::cout << "Welcome to this RPG Game!" << '\n';

    while (true)
    {
        std::cout << "Would you like to: " << '\n';
        std::cout << "1. New Game" << '\n';
        std::cout << "2. Quit" << '\n';

        int option;
        std::cin >> option;
        std::cout << '\n';

        switch (option)
        {
        case 1:
            newGame();
            break;
        case 2:
            quitGame();
            break;
        default:
            std::cout << "That is not an option." << '\n'
                      << '\n';
            continue;
        }
        break;
    }

    return 0;
}

void newGame()
{
    std::string username = getUsername();
    std::cout << "Your username is: " << username << '\n'
              << '\n';
    std::cout << "You are ready for an adventure!" << '\n'
              << '\n';

    std::string charClass = getCharClass();
    std::cout << "Your character class is " << charClass << '\n'
              << '\n';

    Player player(username, charClass);

    while (true)
    {
        std::cout << "Would you like to: " << '\n';
        std::cout << "1. Battle" << '\n';
        std::cout << "2. Quit" << '\n';

        int option;
        std::cin >> option;
        std::cout << '\n';

        if (option == 1)
        {
            std::vector<std::string> enemies = {"Zombie", "Dragon", "Golem"};
            if (((rand() % 100) + 1) <= 90)
            {
                std::string enemyClass = enemies.at(rand() % 3);
                Enemy enemy(enemyClass);
                beginBattle(player, enemy);
            }
            else
            {
                std::vector<std::string> enemyClasses = {enemies.at(rand() % 3), enemies.at(rand() % 3)};
                std::vector<Enemy> enemyObjs;
                for (std::string enemyClass : enemyClasses)
                {
                    Enemy enemy(enemyClass);
                    enemyObjs.push_back(enemy);
                }
                beginBattle(player, enemyObjs);
            }
        }
        else if (option == 2)
        {
            quitGame();
            break;
        }
    }
}

std::string getUsername()
{
    std::string username;
    while (true)
    {
        std::cout << "Enter a username: ";
        std::cin >> username;
        std::cout << '\n';

        std::cout << "Your username is " << username << '\n';
        std::cout << "Would you like to: " << '\n';
        std::cout << "1. Change username" << '\n';
        std::cout << "2. Continue" << '\n';

        int option;
        std::cin >> option;
        std::cout << '\n';

        switch (option)
        {
        case 1:
            continue;
        case 2:
            break;
        default:
            break;
        }
        break;
    }

    return username;
}

std::string getCharClass()
{
    std::string charClass;
    while (true)
    {
        std::cout << "Which character class would you like to choose?" << '\n';
        std::cout << "1. Fighter" << '\n';
        std::cout << "2. Guardian" << '\n';
        std::cout << "3. Wizard" << '\n';
        std::cout << "4. Learn about each of these classes" << '\n';

        int option;
        std::cin >> option;
        std::cout << '\n';

        switch (option)
        {
        case 1:
            charClass = "Fighter";
            break;
        case 2:
            charClass = "Guardian";
            break;
        case 3:
            charClass = "Wizard";
            break;
        case 4:
            std::cout << "1. Fighter" << '\n';
            std::cout << '\t' << "Health: Low" << '\n';
            std::cout << '\t' << "Attack: High" << '\n';
            std::cout << '\t' << "Speed: Medium" << '\n';

            std::cout << "2. Guardian" << '\n';
            std::cout << '\t' << "Health: High" << '\n';
            std::cout << '\t' << "Attack: Medium" << '\n';
            std::cout << '\t' << "Speed: Low" << '\n';

            std::cout << "3. Wizard" << '\n';
            std::cout << '\t' << "Health: Medium" << '\n';
            std::cout << '\t' << "Attack: Low" << '\n';
            std::cout << '\t' << "Speed: High" << '\n';

            continue;
        default:
            std::cout << "That is not an option." << '\n'
                      << '\n';
            continue;
        }

        std::cout << "Your character class is: " << charClass << '\n';
        std::cout << "Would you like to: " << '\n';
        std::cout << "1. Change class" << '\n';
        std::cout << "2. Continue" << '\n';

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            continue;
        case 2:
            break;
        default:
            break;
        }
        break;
    }

    return charClass;
}

void beginBattle(Player player, Enemy enemy)
{
    int playerOgHealth = player.getHealth();
    int enemyOgHealth = enemy.getHealth();

    std::cout << "You are up against a " << enemy.getClass() << "!" << '\n';

    std::cout << "Player health: " << player.getHealth() << '\n';
    std::cout << "Enemy health: " << enemy.getHealth() << '\n';

    while (true)
    {
        std::cout << "It's your turn to attack!" << '\n';
        std::cout << "Would you like to: " << '\n';
        std::cout << "1. Attack" << '\n';
        std::cout << "2. Heal" << '\n';

        int option;
        std::cin >> option;

        std::cout << '\n';

        switch (option)
        {
        case 1:
            if ((rand() % 100) + 1 <= 5)
            {
                std::cout << "It's a critical hit!" << '\n';
                std::cout << "You attacked the " << enemy.getClass() << ", dealing " << player.getAttack() * 2 << " damage!" << '\n';
                enemy.setHealth(enemy.getHealth() - (player.getAttack() * 2));
            }
            else if ((rand() % 100) + 1 <= enemy.getSpeed())
            {
                std::cout << "You missed!" << '\n';
            }
            else
            {
                std::cout << "You attacked the " << enemy.getClass() << ", dealing " << player.getAttack() << " damage!" << '\n';
                enemy.setHealth(enemy.getHealth() - player.getAttack());
            }
            break;
        case 2:
            std::cout << "You heal for a quarter of your health." << '\n';
            player.setHealth(player.getHealth() + 0.25 * playerOgHealth);
            if (player.getHealth() > playerOgHealth)
                player.setHealth(playerOgHealth);
            break;
        default:
            std::cout << "Not an option.";
            continue;
        }

        if (enemy.getHealth() <= 0)
        {
            std::cout << "You win!" << '\n';
            break;
        }

        std::cout << '\n';

        std::cout << "Player health: " << player.getHealth() << '\n';
        std::cout << "Enemy health: " << enemy.getHealth() << '\n';

        int enemyOption = (rand() % 4) + 1;

        std::cout << '\n';

        switch (enemyOption)
        {
        case 1:
            std::cout << "The enemy heals for a quarter of its health." << '\n';
            enemy.setHealth(enemy.getHealth() + 0.25 * enemyOgHealth);
            if (enemy.getHealth() > enemyOgHealth)
                enemy.setHealth(enemyOgHealth);
            break;
        default:
            if ((rand() % 100) + 1 <= 5)
            {
                std::cout << "It's a critical hit!" << '\n';
                std::cout << "The enemy attacks you, dealing " << enemy.getAttack() * 2 << " damage!" << '\n';
                player.setHealth(player.getHealth() - enemy.getAttack() * 2);
                break;
            }
            else if ((rand() % 100) + 1 <= player.getSpeed())
            {
                std::cout << "The enemy missed!" << '\n';
            }
            else
            {
                std::cout << "The enemy attacks you, dealing " << enemy.getAttack() << " damage!" << '\n';
                player.setHealth(player.getHealth() - enemy.getAttack());
                break;
            }
        }

        if (player.getHealth() <= 0)
        {
            std::cout << "You lose!" << '\n';
            break;
        }

        std::cout << "Player health: " << player.getHealth() << '\n';
        std::cout << "Enemy health: " << enemy.getHealth() << '\n';
    }
}

void beginBattle(Player player, std::vector<Enemy> &enemies)
{
    enemies.at(0).setHealth(enemies.at(0).getHealth() / 2);
    enemies.at(1).setHealth(enemies.at(1).getHealth() / 2);
    int playerOgHealth = player.getHealth();
    int enemy1OgHealth = enemies.at(0).getHealth();
    int enemy2OgHealth = enemies.at(1).getHealth();
    bool enemy1Dead = false;
    bool enemy2Dead = false;

    std::cout << "You are up against a " << enemies.at(0).getClass() << " and a " << enemies.at(1).getClass() << "!" << '\n';

    std::cout << "Player health: " << player.getHealth() << '\n';
    std::cout << enemies.at(0).getClass() << " health: " << enemies.at(0).getHealth() << '\n';
    std::cout << enemies.at(1).getClass() << " health: " << enemies.at(1).getHealth() << '\n';

    while (true)
    {
        std::cout << "It's your turn to attack!" << '\n';
        std::cout << "Would you like to: " << '\n';
        std::cout << "1. Target attack" << '\n';
        std::cout << "2. Splash attack" << '\n';
        std::cout << "3. Heal" << '\n';

        int option;
        std::cin >> option;

        std::cout << '\n';

        switch (option)
        {
        case 1:
            if (!enemy1Dead && !enemy2Dead)
            {
                std::cout << "Would you like to attack: " << '\n';
                std::cout << "1. " << enemies.at(0).getClass() << '\n';
                std::cout << "2. " << enemies.at(1).getClass() << '\n';

                int enemyChoice;
                std::cin >> enemyChoice;

                if (enemyChoice == 1)
                {
                    if ((rand() % 100) + 1 <= 5)
                    {
                        std::cout << "It's a critical hit!" << '\n';
                        std::cout << "You attack the " << enemies.at(0).getClass() << ", dealing " << player.getAttack() * 2 << " damage!" << '\n';
                        enemies.at(0).setHealth(enemies.at(0).getHealth() - player.getAttack() * 2);
                    }
                    else if ((rand() % 100) + 1 <= enemies.at(0).getSpeed())
                    {
                        std::cout << "You missed!" << '\n';
                    }
                    else
                    {
                        std::cout << "You attack the " << enemies.at(0).getClass() << ", dealing " << player.getAttack() << " damage!" << '\n';
                        enemies.at(0).setHealth(enemies.at(0).getHealth() - player.getAttack());
                    }
                }
                else if (enemyChoice == 2)
                {
                    if ((rand() % 100) + 1 <= 5)
                    {
                        std::cout << "It's a critical hit!" << '\n';
                        std::cout << "You attack the " << enemies.at(1).getClass() << ", dealing " << player.getAttack() * 2 << " damage!" << '\n';
                        enemies.at(1).setHealth(enemies.at(1).getHealth() - player.getAttack() * 2);
                    }
                    else if ((rand() % 100) + 1 <= enemies.at(1).getSpeed())
                    {
                        std::cout << "You missed!" << '\n';
                    }
                    else
                    {
                        std::cout << "You attack the " << enemies.at(1).getClass() << ", dealing " << player.getAttack() << " damage!" << '\n';
                        enemies.at(1).setHealth(enemies.at(1).getHealth() - player.getAttack());
                    }
                }
                else
                {
                    std::cout << "That is not an option." << '\n';
                    continue;
                }
                break;
            }
            else if (enemy2Dead && !enemy1Dead)
            {
                if ((rand() % 100) + 1 <= 5)
                {
                    std::cout << "It's a critical hit!" << '\n';
                    std::cout << "You attacked the " << enemies.at(0).getClass() << ", dealing " << player.getAttack() * 2 << " damage!" << '\n';
                    enemies.at(0).setHealth(enemies.at(0).getHealth() - (player.getAttack() * 2));
                }
                else if ((rand() % 100) + 1 <= enemies.at(0).getSpeed())
                {
                    std::cout << "You missed!" << '\n';
                }
                else
                {
                    std::cout << "You attacked the " << enemies.at(0).getClass() << ", dealing " << player.getAttack() << " damage!" << '\n';
                    enemies.at(0).setHealth(enemies.at(0).getHealth() - player.getAttack());
                }
                break;
            }
            else if (enemy1Dead && !enemy2Dead)
            {
                if ((rand() % 100) + 1 <= 5)
                {
                    std::cout << "It's a critical hit!" << '\n';
                    std::cout << "You attacked the " << enemies.at(1).getClass() << ", dealing " << player.getAttack() * 2 << " damage!" << '\n';
                    enemies.at(1).setHealth(enemies.at(1).getHealth() - (player.getAttack() * 2));
                }
                else if ((rand() % 100) + 1 <= enemies.at(1).getSpeed())
                {
                    std::cout << "You missed!" << '\n';
                }
                else
                {
                    std::cout << "You attacked the " << enemies.at(1).getClass() << ", dealing " << player.getAttack() << " damage!" << '\n';
                    enemies.at(1).setHealth(enemies.at(1).getHealth() - player.getAttack());
                }
                break;
            }
        case 2:
            if (enemy1Dead || enemy2Dead)
            {
                std::cout << "There's only one enemy left!" << '\n';
                continue;
            }
            if ((rand() % 100) + 1 <= 5)
            {
                std::cout << "It's a critical hit!" << '\n';
                std::cout << "You attack both the " << enemies.at(0).getClass() << " and the " << enemies.at(1).getClass() << ", dealing " << player.getAttack() << " damage to each of them." << '\n';
                enemies.at(0).setHealth(enemies.at(0).getHealth() - player.getAttack());
                enemies.at(1).setHealth(enemies.at(1).getHealth() - player.getAttack());
            }
            else if ((rand() % 100) + 1 <= (enemies.at(0).getSpeed() + enemies.at(1).getSpeed()) / 2)
            {
                std::cout << "You missed!" << '\n';
            }
            else
            {
                std::cout << "You attack both the " << enemies.at(0).getClass() << " and the " << enemies.at(1).getClass() << ", dealing " << player.getAttack() / 2 << " damage to each of them." << '\n';
                enemies.at(0).setHealth(enemies.at(0).getHealth() - player.getAttack() / 2);
                enemies.at(1).setHealth(enemies.at(1).getHealth() - player.getAttack() / 2);
            }
            break;
        case 3:
            std::cout << "You heal for a quarter of your health." << '\n';
            player.setHealth(player.getHealth() + 0.25 * playerOgHealth);
            if (player.getHealth() > playerOgHealth)
                player.setHealth(playerOgHealth);
            break;
        default:
            std::cout << "Not an option.";
            continue;
        }

        // Check and update enemy death states
        if (enemies.at(0).getHealth() <= 0 && !enemy1Dead)
        {
            enemy1Dead = true;
            std::cout << "The " << enemies.at(0).getClass() << " died!" << '\n';
        }
        if (enemies.at(1).getHealth() <= 0 && !enemy2Dead)
        {
            enemy2Dead = true;
            std::cout << "The " << enemies.at(1).getClass() << " died!" << '\n';
        }

        if (enemy1Dead && enemy2Dead)
        {
            std::cout << "You win!" << '\n';
            break;
        }

        std::cout << '\n';

        std::cout << "Player health: " << player.getHealth() << '\n';
        if (!enemy1Dead)
            std::cout << enemies.at(0).getClass() << " health: " << enemies.at(0).getHealth() << '\n';
        if (!enemy2Dead)
            std::cout << enemies.at(1).getClass() << " health: " << enemies.at(1).getHealth() << '\n';

        if (!enemy1Dead)
        {
            int enemy1Option = (rand() % 4) + 1;

            std::cout << '\n';

            switch (enemy1Option)
            {
            case 1:
                std::cout << "The " << enemies.at(0).getClass() << " heals for a quarter of its health." << '\n';
                enemies.at(0).setHealth(enemies.at(0).getHealth() + 0.25 * enemy1OgHealth);
                if (enemies.at(0).getHealth() > enemy1OgHealth)
                    enemies.at(0).setHealth(enemy1OgHealth);
                break;
            default:
                if ((rand() % 100) + 1 <= 5)
                {
                    std::cout << "It's a critical hit!" << '\n';
                    std::cout << "The " << enemies.at(0).getClass() << " attacks you, dealing " << enemies.at(0).getAttack() * 2 << " damage!" << '\n';
                    player.setHealth(player.getHealth() - enemies.at(0).getAttack() * 2);
                    break;
                }
                else if ((rand() % 100) <= player.getSpeed())
                {
                    std::cout << "The enemy missed!" << '\n';
                }
                else
                {
                    std::cout << "The " << enemies.at(0).getClass() << " attacks you, dealing " << enemies.at(0).getAttack() << " damage!" << '\n';
                    player.setHealth(player.getHealth() - enemies.at(0).getAttack());
                    break;
                }
            }
        }

        if (!enemy2Dead)
        {
            int enemy2Option = (rand() % 4) + 1;

            std::cout << '\n';

            switch (enemy2Option)
            {
            case 1:
                std::cout << "The " << enemies.at(1).getClass() << " heals for a quarter of its health." << '\n';
                enemies.at(1).setHealth(enemies.at(1).getHealth() + 0.25 * enemy2OgHealth);
                if (enemies.at(1).getHealth() > enemy2OgHealth)
                    enemies.at(1).setHealth(enemy2OgHealth);
                break;
            default:
                if ((rand() % 100) + 1 <= 5)
                {
                    std::cout << "It's a critical hit!" << '\n';
                    std::cout << "The " << enemies.at(1).getClass() << " attacks you, dealing " << enemies.at(1).getAttack() * 2 << " damage!" << '\n';
                    player.setHealth(player.getHealth() - enemies.at(1).getAttack() * 2);
                    break;
                }
                else if ((rand() % 100) <= player.getSpeed())
                {
                    std::cout << "The enemy missed!" << '\n';
                }
                else
                {
                    std::cout << "The " << enemies.at(1).getClass() << " attacks you, dealing " << enemies.at(1).getAttack() << " damage!" << '\n';
                    player.setHealth(player.getHealth() - enemies.at(1).getAttack());
                    break;
                }
            }
        }

        if (player.getHealth() <= 0)
        {
            std::cout << "You lose!" << '\n';
            break;
        }

        std::cout << "Player health: " << player.getHealth() << '\n';
        if (!enemy1Dead)
            std::cout << enemies.at(0).getClass() << " health: " << enemies.at(0).getHealth() << '\n';
        if (!enemy2Dead)
            std::cout << enemies.at(1).getClass() << " health: " << enemies.at(1).getHealth() << '\n';
    }
}

void quitGame()
{
    std::cout << "Thanks for playing!" << '\n'
              << '\n';
}
