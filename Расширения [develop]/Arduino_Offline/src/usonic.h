/*
  usonic.h - библиотека для работы с ультразвуковым датчиком
*/

#ifndef usonic_h
#define usonic_h

#include <Arduino.h>

///Объявляем класс
class USonicClass
{
	public:
		USonicClass(); ///Описание класса
		long getDistance(int TrigPin, int EchoPin, int distance_units); ///Описание функции считывания расстояния с УЗ датчика, последний параметр - единицы измерения, в которых выдавать результат
	private:
		long  duration,distacne_cm,distance_inc;	///Переменные для внутренних расчетов результата
};

#endif