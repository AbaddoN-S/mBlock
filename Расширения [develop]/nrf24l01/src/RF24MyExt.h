/*/*
								заголовочный файл (с расширением .h)
							-----------информация о библиотеке----------------
  RF24MyExt.h - библиотека с вспомогательными константами обеспечивающими работоспособность расширения NRF24L01 для mBlock
*/


//проверка, что библиотека еще не подключена
#ifndef RF24MyExt_h		// если библиотека не подключена
#define RF24MyExt_h		// тогда подключаем её

#include <Arduino.h>		// в библиотеках нужно явно подключить Arduino.h

#define myDataRate0 RF24_250KBPS
#define myDataRate1 RF24_1MBPS
#define myDataRate2 RF24_2MBPS

#define myPALevel0 RF24_PA_MIN
#define myPALevel1 RF24_PA_LOW
#define myPALevel2 RF24_PA_HIGH
#define myPALevel3 RF24_PA_MAX

#define myIDAdress0 0x7878787878LL
#define myIDAdress1 0xAABBCCDD11LL
#define myIDAdress2 0xAABBCCDD22LL
#define myIDAdress3 0xAABBCCDD33LL
#define myIDAdress4 0xAABBCCDD44LL
#define myIDAdress5 0xAABBCCDD55LL
#define myIDAdress6 0xAABBCCDD66LL
#define myIDAdress7 0xAABBCCDD77LL
#define myIDAdress8 0xAABBCCDD88LL
#define myIDAdress9 0xAABBCCDD99LL



#endif