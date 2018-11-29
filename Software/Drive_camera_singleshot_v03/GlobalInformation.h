/*
 * GlobalInformation.h
 *
 *  Created on: Mar 26, 2017
 *      Author: Nima
 */

#ifndef GLOBALINFORMATION_H_
#define GLOBALINFORMATION_H_
#include <stdint.h>

#define NETWORK_NAME    "Nima"
#define NETWORK_PASS    "Ne08041373nima?"
//#define NETWORK_NAME	"Nima\'s iPhone"
//#define NETWORK_PASS	"8064709377"
#define NETWORK_TYPE    SL_SEC_TYPE_WPA_WPA2

extern uint8_t MyIPAddress[4];
extern uint32_t test;

typedef enum{
    SOCKET_CREATE_ERROR = -0x7D0,
    BIND_ERROR = SOCKET_CREATE_ERROR - 1,
    LISTEN_ERROR = BIND_ERROR -1,
    SOCKET_OPT_ERROR = LISTEN_ERROR -1,
    CONNECT_ERROR = SOCKET_OPT_ERROR -1,
    ACCEPT_ERROR = CONNECT_ERROR - 1,
    SEND_ERROR = ACCEPT_ERROR -1,
    RECV_ERROR = SEND_ERROR -1,
    SOCKET_CLOSE_ERROR = RECV_ERROR -1,
    DEVICE_NOT_IN_STATION_MODE = SOCKET_CLOSE_ERROR - 1,
    STATUS_CODE_MAX = -0xBB8
}e_AppStatusCodes;

#endif /* GLOBALINFORMATION_H_ */
