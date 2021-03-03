/*
 * MazeMap.h
 *
 *  Created on: 3 мар. 2021 г.
 *      Author: unyuu
 */

#ifndef MAZEMAP_H_
#define MAZEMAP_H_

#include <vector>

/*
 * Храним:
 * 1. Вершины точек на карте
 * 2. Описание сегментов:
 * 2.1. Перечисление (по порядку по часовой стрелке) точек, ограничивающих сегмент
 * 2.2. Смежность сегмента с другими сегментами
 * 2.3. PVS
 * 2.4. Высота пола
 * 2.5. Высота потолка
 * 2.6. Текстура пола
 * 2.6.1. Текстурные координаты для пола
 * 2.7. Текстура потолка
 * 2.7.1. Текстурные координаты для потолка
 * 2.8. Текстура стен
 * 2.8.1. Текстурные координаты для стен
 * 3. Начальный сегмент
 * 4. Начальные координаты
 *
 */

struct MapVertex
{
	double x, y;
};

struct TexCoords // TODO: возможно, отсюда оно уйдёт в другое место программы
{
	double s, t;
};

struct MapSegment
{
	std::vector<int> vertices;
	std::vector<int> portals;
	std::vector<int> pvs;
	double floor_level;
	double ceil_level;
	int floor_tex_id;
	int ceil_tex_id;
	int wall_tex_id;
	std::vector<TexCoords> floor_tex_coords;
	std::vector<TexCoords> ceil_tex_coords;
	double wall_tex_floor_t;
	double wall_tex_ceil_t;
	std::vector<double> wall_tex_s;
};

class MazeMap final
{
protected:
	std::vector<MapVertex> _vertices;
	std::vector<MapSegment> _segments;
	int _start_seg;
	MapVertex _start_point;


};

#endif /* MAZEMAP_H_ */
