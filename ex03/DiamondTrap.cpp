#include "DiamondTrap.hpp"

/*
	- hiding/shadowing the base class if they have same member name
		- using this->_name or _name will access only DiamondTrap's _name member
		- to access ClapTrap's name, use ClapTrap::_name

	- applying virtual inheritance to ScavTrap and FragTrap will only allow the DiamondTrap
		to create instance of ClapTrap(base class)
	- even though I called "ClapTrap constructor" in both ScavTrap() and FragTrap(),
		they will be ignored.
	- so reassigning ClapTrap::_name is not necessary
*/
// default construtor
DiamondTrap::DiamondTrap(void): 
	ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap() , _name("DiamondTrap")
{
	std::cout << GREEN << "[DiamondTrap] Default constructor called\n" << RESET;
	this->_hit_pts = 100; // FragTrap
	this->_energy_pts = 50; // ScavTrap
	this->_attack_dmg = 30; // FragTrap
	// ClapTrap::_name = "DiamondTrap_clap_name"; // this line is not necessary (refer point 2-5 above)
	std::cout << YELLOW << "[DiamondTrap->ClapTrap] " << ClapTrap::_name << " is constructed" << RESET << std::endl;
	std::cout << YELLOW << "[DiamondTrap] " << _name << " is constructed" << RESET << std::endl;
}

// string name constructor
// - is able to remove the parameter inside the ScavTrap and FragTrap
DiamondTrap::DiamondTrap(std::string p_name):
	ClapTrap(p_name + "_clap_name"), ScavTrap(p_name + "_clap_name"),
	FragTrap(p_name + "_clap_name"), _name(p_name)
{
	std::cout << GREEN << "[DiamondTrap] String constructor called\n" << RESET;
	this->_hit_pts = 100; // FragTrap
	this->_energy_pts = 50; // ScavTrap
	this->_attack_dmg = 30; // FragTrap
	std::cout << YELLOW << "[DiamondTrap->ClapTrap] " << ClapTrap::_name << " is constructed" << RESET << std::endl;
	std::cout << YELLOW << "[DiamondTrap] " << _name << " is constructed" << RESET << std::endl;
}

// copy constructor
// - is able to remove the parameter inside the ScavTrap and FragTrap
DiamondTrap::DiamondTrap(const DiamondTrap &other):
	ClapTrap(other._name + "_clap_name"), ScavTrap(other._name + "_clap_name"),
	FragTrap(other._name + "_clap_name"), _name(other._name)
{
	std::cout << YELLOW << "[DiamondTrap] Copy constructor called\n" << RESET;
	this->_hit_pts = other.getHitPts();
	this->_energy_pts = other.getEnergyPts();
	this->_attack_dmg = other.getAttackDmg();
	std::cout << YELLOW << "[DiamondTrap->ClapTrap] " << ClapTrap::_name << " is constructed" << RESET << std::endl;
	std::cout << YELLOW << "[DiamondTrap] " << _name << " is constructed\n" << RESET;
}

// copy assignment operator
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		ClapTrap::_name = other._name + "_clap_name";
		this->_hit_pts = other.getHitPts();
		this->_energy_pts = other.getEnergyPts();
		this->_attack_dmg = other.getAttackDmg();
	}
	std::cout << YELLOW << "[DiamondTrap] Copy assignment operator called\n" << RESET;
	std::cout << YELLOW << "[DiamondTrap->ClapTrap] " << ClapTrap::_name << " is constructed" << RESET << std::endl;
	std::cout << YELLOW << "[DiamondTrap] " << _name << " is constructed\n" << RESET;
	return (*this);
}

// Default destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "[DiamondTrap] Destructor called\n" << RESET;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << BLUE << "[DiamondTrap] Executing whoAmI\n" << RESET;
	std::cout << BLUE << "[DiamondTrap->ClapTrap] " << ClapTrap::_name << " is constructed" << RESET << std::endl;
	std::cout << BLUE << "[DiamondTrap] " << _name << " is constructed\n" << RESET;
}
