//
// Created by Eliam on 28/04/2025.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string.h>
#include <iostream>

class Intern {
public:
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	Intern();

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	AForm *makeForm(std::string form_name, std::string form_target);
};


#endif //INTERN_HPP
