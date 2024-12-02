/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 11:17:59 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

/*Prints out error message, in case argument amout given to program
  is not 3 or if s1 or s2 are empty strings.*/
int	printInvalidArguments()
{
	std::cout << "Error. Insufficient arguments." << std::endl;
	std::cout << "Allowed argument amount is '3' in the following order:"<< std::endl;
	std::cout << "Filename, string1, string2." << std::endl;
	std::cout << "String1 and string2 cannot be empty." << std::endl;
	return (1);
}

/*Converts c-strings into string objects and checks if
  any of them is empty. If this is the case, returns 1.*/
int	checkForEmptyString(char **av)
{
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	
	if (s1.empty() || s2.empty())
		return (1);
	return (0);
}

/*Opens file or returns an empty string in case it cannot be opened
  or file is empty. If file can be opened, reads its content and stores
  it in a string and returns this string to main function.*/
std::string	getFileContent(char **av)
{
	std::ifstream	myFile;
	std::string		fileContent;

	myFile.open(av[1]);
	if (!myFile.is_open())
	{
		std::cout << "Error. File 1 could not be opened." << std::endl;
		return ("");
	}
	if (!std::getline(myFile, fileContent))
	{
		std::cout << "Error. File 1 is empty." << std::endl;
		myFile.close();
		return ("");
	}
	else
		myFile.close();
	return (fileContent);
}

/*Creates and opens 'file1.replace' via std::ofstream (output file stream to
  open a file -or create if it does not exist- for writing). In case s1 and s2
  are the same, copies content of fileContent into file and returns. Otherwise
  iterates through fileContent string(passed from main) with .find() for checking
  identical sequence of av[2] within itself. In case an identical sequence
  is found, '.find()' returns index of start of sequence otherwise 'npos' if
  no identical sequence could be found. .erase() and .insert() used respectively
  in order to erase identical sequence in file content and insert the content of
  s2(av[3]). While loop to account for all occurences of sequences in the file.
  Final modified string is then inserted into 'file1.replace' via '<<' operator.*/
int	createSecondFile(char **av, std::string fileContent)
{
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ofstream	myFileReplace("file1.replace");
	bool			foundString = false;

	if (s1 == s2)
	{
		myFileReplace << fileContent;
		myFileReplace.close();
		return (0);
	}
	int 			j = fileContent.find(av[2], 0);
	while ((const size_t)j != std::string::npos)
	{
		fileContent.erase(j, s1.length());
		fileContent.insert(j, s2);
		foundString = true;
		j = fileContent.find(av[2], 0);
	}
	if (foundString == true)
	{
		myFileReplace << fileContent;
		myFileReplace.close();
	}
	else
	{
		std::cout << "String '" << av[2] << "' was not found in file1.replace." << std::endl;
		myFileReplace.close();
		return (1);
	}
	return (0);
}

/*First validates arguments, then retrieves content of first file and
  passes this to createSecondFile function for further modification.*/
int	main(int ac, char **av)
{
	std::string	fileContent;

	if (ac != 4 || checkForEmptyString(av))
		return (printInvalidArguments());
	else
	{
		fileContent = getFileContent(av);
		if (fileContent.empty())
			return (1);
		if (createSecondFile(av, fileContent))
			return (1);
	}
	return (0);
}
