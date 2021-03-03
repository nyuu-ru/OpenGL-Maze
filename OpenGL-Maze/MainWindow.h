/*
 * MainWindow.h
 *
 *  Created on: 3 мар. 2021 г.
 *      Author: unyuu
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "Window.h"

class MainWindow final : public Window
{
protected:
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void handle_event(const SDL_Event &event) override;
	virtual void setup() override;
	virtual void logic() override;
	virtual void render() override;

public:
	MainWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~MainWindow() = default;
};

#endif /* MAINWINDOW_H_ */
