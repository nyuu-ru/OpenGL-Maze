/*
 * main.cc
 *
 *  Created on: 3 мар. 2021 г.
 *      Author: unyuu
 */

#include <iostream>

#include "MainWindow.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

/*
	Список библиотек для Windows + MinGW:
		mingw32
		SDL2main
		SDL2
		SDL2_image
		opengl32
		glu32
		glew32

	Список библиотек для остальных настольных ОС общего назначения:
 	 	SDL2
 	 	SDL2_image
 	 	GL
 	 	GLU
 	 	GLEW
 */


// Это наша функция main(). С неё начинается выполнение нашего кода
// Первый аргумент - количество аргументов командной строки.
//		Аргумент номер 0 - имя самой программы
// Второй аргумент - массив значений всех аргументов командной строки.
int main(int argc, char ** argv)
{
	// Выводим в консоль список аргументов командной строки,
	// с которыми программа была запущена.
	for (int i = 0; i < argc; ++i) {
		std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
	}

	std::cout << "Program started!" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	MainWindow w;

	w.main_loop();


	std::cout << "Program ended!" << std::endl;
	return 0; // Возвращаем код завершения программы. 0 - ок.
}

