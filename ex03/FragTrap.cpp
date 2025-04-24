#include "FragTrap.hpp"

// default construtor
FragTrap::FragTrap(void): 
	ClapTrap("FragTrap")
{
	std::cout << GREEN << "[FragTrap] Default constructor called\n" << RESET;
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << GREEN << "[FragTrap] " << _name << " is constructed" << RESET << std::endl;
}

// string name constructor
FragTrap::FragTrap(std::string p_name):
	ClapTrap(p_name)
{
	std::cout << GREEN << "[FragTrap] String constructor called\n" << RESET;
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << GREEN << "[FragTrap] " << _name << " is constructed" << RESET << std::endl;
}

// copy constructor
FragTrap::FragTrap(const FragTrap &other):
	ClapTrap(other.getName())
{
	std::cout << YELLOW << "[FragTrap] Copy constructor called\n" << RESET;
	this->_hit_pts = other.getHitPts();
	this->_energy_pts = other.getEnergyPts();
	this->_attack_dmg = other.getAttackDmg();
	std::cout << YELLOW << "[FragTrap] " << _name << " is constructed\n" << RESET;
}

// copy assignment operator
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hit_pts = other.getHitPts();
		this->_energy_pts = other.getEnergyPts();
		this->_attack_dmg = other.getAttackDmg();
	}
	std::cout << YELLOW << "[FragTrap] Copy assignment operator called\n" << RESET;
	return (*this);
}

// Default destructor
FragTrap::~FragTrap(void)
{
	std::cout << RED << "[FragTrap] Destructor called\n" << RESET;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "[FragTrap] " << this->getName() << " is high fives guys\n" 
		<< RESET << std::endl;
}
