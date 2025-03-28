#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie {
public:
    Zombie(); // Constructor
    ~Zombie(); // Destructor


    void announce(void);

    void setName (std::string name);

    std::string getName(void) const;

private:
    // Add member variables here
    std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif // ZOMBIE_HPP
