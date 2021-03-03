/*
 * Window.cc
 *
 *  Created on: 3 мар. 2021 г.
 *      Author: unyuu
 */

#include <stdexcept>
#include "Window.h"

// Реализация конструктора класса Window
Window::Window(int width, int height)
: _width(width), _height(height) // вызов по цепочке конструкторов полей
{
	using namespace std::literals;

	// Вариант 1: для экземпляров классов
	// переменная = std::make_shared<Класс>(параметры конструктора);

	// Вариант 2: для хранения сырых указателей
	// переменная = std::shared_ptr<Тип>(значение сырого указателя);

	// Вариант 2.5: для хранения сырых указателей на структуры,
	//              требующие особого порядка удаления
	// переменная = std::shared_ptr<Тип>(значение сырого указателя,
	//                                   адрес отвечающей за удаление
	//                                   объекта функции);

	// Пытаемся создать окно
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"OpenGL Window",
					150, 150,
					width, height,
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
	if (_window == nullptr) // Если не получилось, то ругаемся
		throw std::runtime_error(
				"Can't create a window: "s + SDL_GetError());

	// Говорим SDL, что необходимо создать контекст OpenGL версии 2.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	// Создаём контекст OpenGL
	_gl_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_DeleteContext);
	if (_gl_context == nullptr)
		throw std::runtime_error(
				"Can't create an OpenGL context: "s + SDL_GetError());

}

void Window::main_loop()
{
	SDL_Event event;
	const Uint8 * keys = SDL_GetKeyboardState(nullptr);

	setup();

	for (;;) {
		while (SDL_PollEvent(&event)) { // Обрабатываем события, пока они не кончатся
			if (event.type == SDL_QUIT) // Если это выход - то выходим
				return;
			handle_event(event); 		// Делегируем обработку остальных событий методу
		}
		handle_keys(keys);				// Обрабатываем состояние клавиш

		logic();						// Выполняем какие-то дополнительные действия

		render();						// Рисуем содержимое окна
		SDL_GL_SwapWindow(_window.get());	// Отображаем результат
		// Двойная буферизация:
		// Есть 2 буфера - передний (видимый) и задний (в котором происходят все построения)
		// Пользователю показываем только _результаты_ построений, иначе на экране будет
		// всё мелькать, и большую часть времени видимое изображение будет оставаться
		// недостроенным.
	}
}
