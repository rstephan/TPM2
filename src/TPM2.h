#ifndef TPM2_H
#define TPM2_H
/*
TPM2 protocol for LED comunications (TPM2.serial)
Copyright (C) 2019  Stephan Ruloff

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; in version 2 only
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <Arduino.h>
#include <stdint.h>

#define TPM2_START      0xC9
#define TPM2_TYPE_DATA  0xDA
#define TPM2_TYPE_CMD   0xC0
#define TPM2_TYPE_RESP  0xAA
#define TPM2_END        0x36
#define TPM2_ACK        0xAC


typedef void (*TpmCallback)(uint8_t* data, uint16_t len);

typedef enum {WAIT_SYNC, HEADER1, HEADER2, HEADER3, DATA, END} States;
typedef enum {TYPE_DATA, TYPE_COMMAND, TYPE_RESPONSE} Types;


class TPM2
{
public:
  TPM2(Stream* s, uint8_t* data, uint16_t len);

  void sendData(uint8_t* data, uint16_t len);
  void sendCommand(uint8_t* data, uint16_t len);
  void sendAck(void);
  void registerRxData(TpmCallback cb);
  void update(void);

private:
  void sendIntern(uint8_t type, uint8_t* data, uint16_t len);

  Stream* mSer;
  TpmCallback mCbRxData;
  uint8_t* mBuffer;
  uint16_t mBufferLen;
  uint16_t mPosRx;
  uint8_t mLastByte;
  States mState;
  Types mType;
  uint16_t mLen;
  uint16_t mPosCounter;
};


#endif
