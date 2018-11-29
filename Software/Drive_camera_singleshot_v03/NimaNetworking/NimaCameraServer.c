/*
 * NimaServer.c
 *
 *  Created on: Mar 26, 2017
 *      Author: Nima
 */

#include <socket.h>
#include <stdint.h>
#include <stdbool.h>
#include "../GlobalInformation.h"

// driverlib includes
#include "hw_ints.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "rom.h"
#include "rom_map.h"
#include "interrupt.h"
#include "prcm.h"
#include "uart.h"
#include "utils.h"
#include "gpio.h"

// drivers
#include <gpio_if.h>

// camera app interface
#include <camera/camera_app.h>
void InitCameraComponents(int width, int height);
unsigned short StartCamera(char **WriteBuffer);

uint32_t test = 0;

#define MAX_MESSAGE_SIZE	16

struct DataPackets
{
    uint16_t uLength;
    uint8_t* pData;
};
struct DataPackets Write;

uint16_t sent = 0;

int CameraTcpServer(unsigned short usPort)
{
    SlSockAddrIn_t  sAddr;
    SlSockAddrIn_t  sLocalAddr;
    int             iAddrSize;
    int             iSockID;
    int             iStatus;
    int             iNewSockID;
    long            lNonBlocking = 1;
    uint8_t			response[MAX_MESSAGE_SIZE];
    int16_t        responseSize;

    //filling the TCP server socket address
    sLocalAddr.sin_family = SL_AF_INET;
    sLocalAddr.sin_port = sl_Htons((unsigned short)usPort);
    sLocalAddr.sin_addr.s_addr = 0;

    // creating a TCP socket
    iSockID = sl_Socket(SL_AF_INET,SL_SOCK_STREAM, 0);
    if( iSockID < 0 )
    {
        // error
    	return 1;
    }

    iAddrSize = sizeof(SlSockAddrIn_t);

    // binding the TCP socket to the TCP server address
    iStatus = sl_Bind(iSockID, (SlSockAddr_t *)&sLocalAddr, iAddrSize);
    if( iStatus < 0 )
    {
        // error
        sl_Close(iSockID);
        return 1;
    }

    // putting the socket for listening to the incoming TCP connection
    iStatus = sl_Listen(iSockID, 0);
    if( iStatus < 0 )
    {
    	//error
        sl_Close(iSockID);
        return 1;
    }

    // setting socket option to make the socket as non blocking
    iStatus = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, SL_SO_NONBLOCKING,
                            &lNonBlocking, sizeof(lNonBlocking));
    if( iStatus < 0 )
    {
        sl_Close(iSockID);
        return 1;
    }

    InitCameraComponents(640, 480);

    GPIOPinWrite(GPIOA1_BASE, 2, 2);
    while(1)
    {
		iNewSockID = SL_EAGAIN;
		// waiting for an incoming TCP connection
		while( iNewSockID < 0 )
		{
			// accepts a connection form a TCP client, if there is any
			// otherwise returns SL_EAGAIN
			iNewSockID = sl_Accept(iSockID, ( struct SlSockAddr_t *)&sAddr,
									(SlSocklen_t*)&iAddrSize);
			if( iNewSockID == SL_EAGAIN )
			{
			   MAP_UtilsDelay(10000);
			}
			else if( iNewSockID < 0 )
			{
				// error
				sl_Close(iNewSockID);
				sl_Close(iSockID);
				return 1;
			}
		}
		responseSize = 0;
		while (responseSize == 0 || responseSize == SL_EAGAIN)
		{
		    responseSize = sl_Recv(iNewSockID, response, 1, 0);
		}
		if (responseSize > 0)
		{

            if (response[0] == 0)
            {
                Write.uLength = StartCamera((char **)&Write.pData);
                uint8_t sizeBytes[4] = {0};
                sizeBytes[3] = (uint8_t)(Write.uLength & 0x000000FF);
                sizeBytes[2] = (uint8_t)((Write.uLength >> 8) & 0x000000FF);
                sizeBytes[1] = (uint8_t)((Write.uLength >> 16) & 0x000000FF);
                sizeBytes[0] = (uint8_t)((Write.uLength >> 24) & 0x000000FF);

                //MAP_UtilsDelay(2000000);


                iStatus = sl_Send(iNewSockID, sizeBytes, 4, 0 );
                sent = (uint16_t)(0x0000FFFF & iStatus);
                if( sent != 4 && iStatus < 0 )
                {
                    // error
                    sl_Close(iNewSockID);
                }
                else
                {
                    iStatus = sl_Send(iNewSockID, Write.pData, Write.uLength, 0 );
                    sent = (uint16_t)(0x0000FFFF & iStatus);
                    if( sent != Write.uLength && iStatus < 0 )
                    {
                        // error
                        sl_Close(iNewSockID);
                    }
                    else
                    {
                        sl_Close(iNewSockID);
                    }
                }
            }
            else if (response[0] == 1)
            {
                int8_t totalRead = 0;
                uint8_t messageSizeToRead = 6;
                while (totalRead != messageSizeToRead)
                {
                    responseSize = sl_Recv(iNewSockID, response + totalRead, messageSizeToRead-totalRead, 0);
                    if (responseSize < 0 && responseSize != SL_EAGAIN)
                    {
                        totalRead = responseSize;
                        break;
                    }
                    if (responseSize >= 0)
                    {
                        totalRead += responseSize;
                    }
                }
                if (totalRead == messageSizeToRead)
                {
                    uint8_t sendi = 0;
                    for (sendi = 0; sendi < messageSizeToRead; sendi++)
                    {
                        MAP_UARTCharPut(UARTA1_BASE, response[sendi]);
                    }
                    sl_Close(iNewSockID);
                }
                else
                {
                    sl_Close(iNewSockID);
                }
            }
            else
            {
                sl_Close(iNewSockID);
            }
		}
		else
		{
            sl_Close(iNewSockID);
		}
    }

}


