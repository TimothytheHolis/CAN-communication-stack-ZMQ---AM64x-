/*
 * Definitions for the CANopen application layer
 *
 * @file        canopen_app.h
 * @author      Timothy Mukhooli
 * @copyright   2026 TimothytheHolis
 *
 * This file is part of <https://github.com/CANopenNode/CANopenNode>, a CANopen Stack.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and limitations under the License.
 */

#ifndef CANOPEN_APP_H_
#define CANOPEN_APP_H_

#include "CANopen.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t  desiredNodeID; /* ID that you assign, not always the final NodeID */
    uint8_t  activeNodeID; /* Assigned Node ID */
    uint16_t baudrate;     /* Assigned baudrate */
    uint8_t  outStatusLEDGreen; /* For green LED management (status LED)*/
    uint8_t  outStatusLEDRed; /* For red LED management (error LED)*/
    CO_t*    canOpenStack;
} CANopenNode;

/**
 * @brief Initialize the CANopen application and allocate memory
 * 
 * @param canopenNode structure containing the CANopen node configuration and state
 * @return int 0 in case of success
 */
int canopen_app_init(CANopenNode* canopenNode);

/**
 * @brief Reset the CANopen communication
 * 
 * @return int 0 in case of success
 */
int canopen_app_resetCommunication();

/**
 * @brief Process the CANopen application logic
 * 
 * @param timeDifference_us Time since function was last called in microseconds
 * @return void
 */
void canopen_app_process(uint32_t timeDifference_us);

/**
 * @brief process real time functions like PDOs and sync
 * 
 * @param timeDifference_us Time since function was last called in microseconds
 * @return void
 */
void canopen_process_rt(uint32_t timeDifference_us);

/**
 * Receive CAN message.
 *
 * @param CANmodule This object.
 */
void CO_CANrecv(CO_CANmodule_t* CANmodule);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CANOPEN_APP_H_ */