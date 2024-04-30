
#include "Arduino.h" ///Разрешаем доступ к стандартным функциям Arduino
#include "usonic.h" /// и к характеристикам в головном файле библиотеки


USonicClass::USonicClass()  /// конструктор для создания экземпляра создаваемого класса
{
}


long USonicClass::getDistance(int TrigPin, int EchoPin, int distance_units) /// конструктор функции getDistance (функция вызывается с параметром, если этот параметр включить в конструкотр класса - то значение этого параметра установится при объявлении класса и далее не будет изменяться)
{
	digitalWrite(TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(TrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(TrigPin, LOW);
	duration = pulseIn(EchoPin,HIGH);
	distacne_cm = duration /29 / 2 ;
	distance_inc = duration / 74 / 2;
	switch (distance_units) {
		case 1:
			return distacne_cm;		///если функция вызывается с параметром 1 - выдаем результат в сантиметрах
			break;
		case 2:
			return distance_inc;	///если функция вызывается с параметром 2 - выдаем результат в дюймах
			break;
		default: 					///если функция вызывается с неописанным параметром - выдаем по умолчанию результат в сантиметрах
			return distacne_cm;
	}
}