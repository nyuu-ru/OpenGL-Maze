/*
 * MainWindow.cc
 *
 *  Created on: 3 мар. 2021 г.
 *      Author: unyuu
 */

#include "MainWindow.h"

MainWindow::MainWindow(int width, int height)
: Window(width, height)
{

}

void MainWindow::handle_keys(const Uint8 *keys)
{
}

void MainWindow::handle_event(const SDL_Event &event)
{
}

void MainWindow::setup()
{
	glClearColor(0.f, 0.2f, 0.4f, 1.f);		// Задаём цвет очистки окна
}

void MainWindow::logic()
{
}

void MainWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);			// Очищаем окно

	glBegin(GL_TRIANGLES);					// Рисуем треугольник
	glVertex2f(0.f, 0.8f);
	glVertex2f(0.8f, -0.8f);
	glVertex2f(-0.8f, -0.8f);
	glEnd();
}
