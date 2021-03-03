/*
 * Window.h
 *
 *  Created on: 3 мар. 2021 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

/* Для работы с "умными" указателями */
#include <memory>
/* Для управления расширениями OpenGL */
#include <GL/glew.h>
/* Для работы с окнами */
#include <SDL2/SDL.h>
/* Для работы с контекстом OpenGL */
#include <GL/gl.h>

/*
 * Класс окна
 */
class Window
{
public:
	// static - данная константа находится в _классе_, а не в экземпляре / объекте
	// const - константа времени выполнения. Фактически - переменная,
	//         значение которой нельзя изменить.
	// constexpr - константа времени компиляции.
	static constexpr int DEFAULT_WIDTH = 1920; // Ширина окна по умолчанию
	static constexpr int DEFAULT_HEIGHT = 1080; // Высота окна по умолчанию

protected:
	int _width, _height; // Ширина и высота окна.

	std::shared_ptr<SDL_Window> _window; // Указатель на окно
	std::shared_ptr<void> _gl_context; // Указатель на контекст OpenGL

	virtual void setup() {} // Метод начальной настройки окна
	virtual void render() {} // Метод отрисовки содержимого окна
	virtual void logic() {} // Метод выполнения каких-то действий
	virtual void handle_event(const SDL_Event & event) {} // Метод обработки событий
	virtual void handle_keys(const Uint8 * keys) {} // Метод обработки клавиш

public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	int height() const { return _height; }
	int width() const  { return _width;  }

	void main_loop();
};

// const после заголовка метода - обещание, что метод не имеет
//     побочных эффектов (в частности, не меняет состояние объекта
//     и не вызывает не-const функции)
/*

	{
		SDL_Window * w;

		w = SDL_CreateWindow(...);


		// По-хорошему
		// SDL_DestroyWindow(w);

		// Забыли уничтожить
	}

	SDL_DestroyWindow( ???? а тут мы уже ничего написать не можем... );


 */

#endif /* WINDOW_H_ */
