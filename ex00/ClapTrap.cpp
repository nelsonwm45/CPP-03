#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap():
	_name("ClapTrap"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << GREEN << "Default constructor called\n" << RESET;
	std::cout << GREEN << _name << " is constructed" << RESET << std::endl;
};

// string name constructor
ClapTrap::ClapTrap(std::string	p_name): 
	_name(p_name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << GREEN << "String construtor called\n" << RESET;
	std::cout << GREEN << _name << " is constructed" << RESET << std::endl;
};

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other):
	_name(other._name), _hit_pts(other._hit_pts), _energy_pts(other._energy_pts), _attack_dmg(other._attack_dmg)
{
	std::cout << YELLOW << "Copy constructor called\n" << RESET;
	std::cout << YELLOW << _name << " is constructed\n" << RESET;
}

// Copy Assignment Operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hit_pts = other.getHitPts();
		this->_energy_pts = other.getEnergyPts();
		this->_attack_dmg = other.getAttackDmg();
	}
	std::cout << YELLOW << "Copy assignment operator called\n" << RESET;
	return (*this);
}

// Default destructor 
ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "Destructor called\n" << RESET;
};

void	ClapTrap::attack(const std::string& target)
{
	if (this->getHitPts() > 0)
	{
		if (this->getEnergyPts() > 0)
		{
			std::cout << RED << "ClapTrap " << this->getName() << " attacks " << target 
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPts() > 0)
	{
		if (amount >= this->getHitPts())
		{
			this->_hit_pts = 0;
			std::cout << MAGENTA << this->getName() << " is now dead (0 HP)"
				<< RESET << std::endl;
		}
		else
		{
			std::cout << BLUE << this->getName() << " is taking " 
				<< amount << " damage" << RESET << std::endl;
			this->_hit_pts -= amount;
		}
	}
	else
	{
		std::cout << MAGENTA << this->getName() << " is already dead (0 HP). He/She can't take damage"
			<< RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPts() > 0)
	{
		if (this->getEnergyPts() > 0)
		{
			std::cout << BLUE << this->getName() << " is spending 1 energy point to repair him/herself"
				<< RESET << std::endl;
			std::cout << BLUE << this->getName() << " is repairing " << amount << " HP"
				<< RESET << std::endl;
			this->_energy_pts--;
			this->_hit_pts += amount;
		}
		else
		{
			std::cout << MAGENTA << this->getName() << " has 0 EP to repair him/herself" 
				<< RESET << std::endl;
		}
	}
	else
	{
		std::cout << MAGENTA << this->getName() << " has 0 HP. He/she can't repair him/herself" 
				<< RESET << std::endl;
	}
}

void	ClapTrap::printStatus(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "----------------START OF PRINITING STATUS------------------" << RESET << std::endl;
	std::cout << GREEN << "NAME : " << this->getName() << RESET << std::endl;
	std::cout << GREEN << "HP : " << this->getHitPts() << RESET << std::endl;
	std::cout << GREEN << "EP : " << this->getEnergyPts() << RESET << std::endl;
	std::cout << GREEN << "DMD DEAL : " << this->getAttackDmg() << RESET << std::endl;
	std::cout << GREEN << "----------------END OF PRINITING STATUS------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

// Setters
void	ClapTrap::setName(std::string p_name)
{
	this->_name = p_name;
}

void	ClapTrap::setHitPts(int p_hit_pts)
{
	unsigned int	hp = 0;

	if (p_hit_pts < 0)
		std::cout << RED << "Setting below 0 hp is not allowed" << RESET << std::endl;
	else if (p_hit_pts >= INT32_MAX)
		std::cout << RED << "INT max or above is not allowed" << RESET << std::endl;
	else
	{
		hp = p_hit_pts;
		this->_hit_pts = hp;
		std::cout << GREEN << this->getName() << " is now have " << this->getHitPts()
			<< RESET << std::endl;
	}
}

void	ClapTrap::setHitPts(unsigned int p_hit_pts)
{
	if (p_hit_pts > UINT32_MAX)
		std::cout << RED << "The number is too big" << RESET << std::endl;
	else
	{
		this->_hit_pts = p_hit_pts;
	}
}

void	ClapTrap::setEnergyPts(int p_energy_pts)
{
	unsigned int	ep = 0;

	if (p_energy_pts < 0)
		std::cout << RED << "Setting below 0 ep is not allowed" << RESET << std::endl;
	else if (p_energy_pts >= INT32_MAX)
		std::cout << RED << "INT max or above is not allowed" << RESET << std::endl;
	else
	{
		ep = p_energy_pts;
		this->_energy_pts = ep;
		std::cout << GREEN << this->getName() << " is now have " << this->getEnergyPts()
			<< RESET << std::endl;
	}
}

void	ClapTrap::setEnergyPts(unsigned int p_energy_pts)
{
	if (p_energy_pts >= UINT32_MAX)
		std::cout << RED << "The number is too big" << RESET << std::endl;
	else
	{
		this->_energy_pts = p_energy_pts;
	}
}

void	ClapTrap::setAttackDmg(int p_attack_dmg)
{
	unsigned int	dmg = 0;

	if (p_attack_dmg < 0)
		std::cout << RED << "Setting below 0 dmg is not allowed" << RESET << std::endl;
	else if (p_attack_dmg >= INT32_MAX)
		std::cout << RED << "INT max or above is not allowed" << RESET << std::endl;
	else
	{
		dmg = p_attack_dmg;
		this->_attack_dmg = dmg;
		std::cout << YELLOW << this->getName() << " is now able to deal " << this->getAttackDmg() << " damage"
			<< RESET << std::endl;
	}
}

void	ClapTrap::setAttackDmg(unsigned int p_attack_dmg)
{
	if (p_attack_dmg >= UINT32_MAX)
		std::cout << RED << "The number is too big" << RESET << std::endl;
	else
	{
		this->_energy_pts = p_attack_dmg;
	}
}

// Getters
std::string	ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPts() const
{
	return (this->_hit_pts);
}

unsigned int	ClapTrap::getEnergyPts() const
{
	return (this->_energy_pts);
}

unsigned int	ClapTrap::getAttackDmg() const
{
	return (this->_attack_dmg);
}
