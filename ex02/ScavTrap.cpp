#include "ScavTrap.hpp"

/*
	The ClapTrap base class already has _hit_pts, _energy_pts, _attack_dmg
	If so, then you should not re-declare them in ScavTrap, 
	and you also cannot initialize them directly like that in ScavTrap.

	ScavTrap::ScavTrap(void): 
	ClapTrap("ScavTrap"), _hit_pts(100), _energy_pts(50), _attack_dmg(20)
	[Above is wrong because you re-declare again.]

	You must use ClapTrap's constructor to do it.
*/

// default construtor
ScavTrap::ScavTrap(void): 
	ClapTrap("ScavTrap")
{
	std::cout << GREEN << "[ScavTrap] Default constructor called\n" << RESET;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	std::cout << GREEN << "[ScavTrap] " << _name << " is constructed" << RESET << std::endl;
}

// string name constructor
ScavTrap::ScavTrap(std::string p_name):
	ClapTrap(p_name)
{
	std::cout << GREEN << "[ScavTrap] String constructor called\n" << RESET;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	std::cout << GREEN << "[ScavTrap] " << _name << " is constructed" << RESET << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &other):
	ClapTrap(other.getName())
{
	std::cout << YELLOW << "[ScavTrap] Copy constructor called\n" << RESET;
	this->_hit_pts = other.getHitPts();
	this->_energy_pts = other.getEnergyPts();
	this->_attack_dmg = other.getAttackDmg();
	std::cout << YELLOW << "[ScavTrap] " << _name << " is constructed\n" << RESET;
}

// copy assignment operator
ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hit_pts = other.getHitPts();
		this->_energy_pts = other.getEnergyPts();
		this->_attack_dmg = other.getAttackDmg();
	}
	std::cout << YELLOW << "[ScavTrap] Copy assignment operator called\n" << RESET;
	return (*this);
}

// Default destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "[ScavTrap] Destructor called\n" << RESET;
}


void	ScavTrap::guardGate(void)
{
	std::cout << BLUE << "[ScavTrap] ScavTrap is now in Gate Keeper Mode" 
		<< RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPts() > 0)
	{
		if (this->getEnergyPts() > 0)
		{
			std::cout << RED << "ScavTrap " << this->getName() << " attacks " << target 
				<< ", causing " << this->getAttackDmg() << " points of damage!"
				<< RESET << std::endl;
			std::cout << BLUE << this->getName() << " is spending 1 energy point to attack"
				<< RESET << std::endl;
			std::cout << BLUE << this->getName() << " will cause " << this->getAttackDmg() 
				<< " damage to " << target << RESET << std::endl;
			this->_energy_pts--;
		}
		else
		{
			std::cout << MAGENTA << this->getName() << " has 0 EP to attack" 
				<< RESET << std::endl;
		}
	}
	else
	{
		std::cout << MAGENTA << this->getName() << " is dead (0 HP). He/She can't attack"
			<< RESET << std::endl;
	}
}
