/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:51 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 14:48:41 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), mTarget(target)
{
	drawTrees(target);
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	mTarget = other.mTarget;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	mTarget = other.mTarget;
	return (*this);
}

ShrubberyCreationForm:: ~ShrubberyCreationForm() {}

/*Draws ASCII trees and writes them into a newly created file*/
void ShrubberyCreationForm::drawTrees(const std::string target) {
	std::ofstream	targetFile(target + "_shrubbery");
	std::string		trees;
	trees += drawSingleTree();
	trees += drawSingleTree();
	trees += drawSingleTree();
	targetFile << trees;
	targetFile.close();
}

/*Helper function of drawTrees, draws single ASCII tree*/
std::string ShrubberyCreationForm::drawSingleTree() {
	std::string	tree;
	int			j = 8;
	int			k = 1;
	
	for (int m = 0; m < 6; m++) {
		for (int i = 0; i < j; i++)
			tree += ' ';
		for (int i = 0; i < k; i++)
			tree += '$';
		for (int i = 0; i < j; i++)
			tree += ' ';
		tree += '\n';
		j -= 1;
		k += 2;
	}
	j = 8;
	k = 1;
	for (int m = 0; m < 2; m++){
		for (int i = 0; i < j; i++)
			tree += ' ';
		for (int i = 0; i < k; i++)
			tree += 'I';
		for (int i = 0; i < j; i++)
			tree += ' ';
		tree += '\n';
	}
	return (tree);
}
