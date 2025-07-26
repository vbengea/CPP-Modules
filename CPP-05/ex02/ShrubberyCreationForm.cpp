#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// ShrubberyCreationForm::ShrubberyCreationForm() {
	
// }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShruberryCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	: AForm(rhs), target(rhs.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return this->target;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs) {
	os << "ShrubberyCreationForm: " << rhs.getName() << ", "
		<< "isSigned: " << (rhs.getSigned() ? "true" : "false") << ", "
		<< "gradeSign: " << rhs.getGradeSign() << ", "
		<< "gradeExec: " << rhs.getGradeExec() << ", "
		<< "target: " << rhs.getTarget();
	return os;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->getSigned())
		throw AForm::GradeTooLowExeption();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowExeption();

	std::ofstream ofs((this->target + "_shrubbery").c_str());
	if (!ofs)
		throw std::ios_base::failure("Failed to open file");

	// First magnificent tree
	ofs << "                                                    v\n";
	ofs << "                                                   >X<\n";
	ofs << "                                                    A\n";
	ofs << "                                                   d$b\n";
	ofs << "                                                 .d\\$$b.\n";
	ofs << "                                               .d$i$$\\$$b.\n";
	ofs << "                                                  d$$@b\n";
	ofs << "                                                 d\\$$$ib\n";
	ofs << "                                               .d$$$\\$$$b\n";
	ofs << "                                             .d$$@$$$$\\$$ib.\n";
	ofs << "                                                 d$$i$$b\n";
	ofs << "                                                d\\$$$$@$b\n";
	ofs << "                                             .d$@$$\\$$$$$@b.\n";
	ofs << "                                           .d$$$$i$$$\\$$$$$$b.\n";
	ofs << "                                                  ###\n";
	ofs << "                                                  ###\n";
	ofs << "                                                  ###\n";
	ofs << "\n\n";

	// Second magnificent tree with surrounding scene
	ofs << "                                     *\n";
	ofs << "                                    /|\\\n";
	ofs << "                                   /*|O\\\n";
	ofs << "                                  /*/|\\*\\\n";
	ofs << "                                 /X/O|*\\X\\\n";
	ofs << "                                /*/X/|\\X\\*\\\n";
	ofs << "                               /O/*/X|*\\O\\X\\\n";
	ofs << "                              /*/O/X/|\\X\\O\\*\\\n";
	ofs << "                             /X/O/*/X|X\\*\\O\\X\\\n";
	ofs << "                            /O/X/*/O/|\\X\\*\\X\\O\\\n";
	ofs << "                                   ||\n";
	ofs << "                                   ||\n";
	ofs << "                                   ||\n";
	ofs << "                  ~~~~~~~~~~~~~~~~~||~~~~~~~~~~~~~~~~\n";
	ofs << "                     {               }      {      }\n";
	ofs << "                            {                    }\n";
	ofs << "\n\n";

	// Third, a mystical forest scene
	ofs << "                        ,@@@@@@@,\n";
	ofs << "              ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	ofs << "           ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	ofs << "          ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	ofs << "          %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	ofs << "          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	ofs << "          `&%\\ ` /%&'    |.|        \\ '|8'\n";
	ofs << "              |o|        | |         | |\n";
	ofs << "              |.|        | |         | |\n";
	ofs << "           \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	ofs << "\n\n";

	// Fourth, a detailed Japanese-style bonsai
	ofs << "                           .\n";
	ofs << "                          /|\\             .      ;  \n";
	ofs << "                         / | \\           .  .  ;   \n";
	ofs << "                        /__|__\\          .   ;  .  \n";
	ofs << "                       /  | |  \\     .    ; .   ;  \n";
	ofs << "                      / \\ | | / \\   ; ;  ;     ;   \n";
	ofs << "                     #   \\|/    #  ;; ;  ; ;  ;\n";
	ofs << "                    ##    |     ##  ;  ;  ; ; ;\n";
	ofs << "                    ###___|____###_;_;__;_;__\n";
	ofs << "                        |_|_|\n";
	ofs << "                        |_|_|\n";
	ofs << "                    ____|_|_|____\n";
	ofs << "                   /    |_|_|    \\\n";
	ofs << "                  /________________\\\n";
	ofs << "                 (__________________)           \n";

	ofs.close();
}