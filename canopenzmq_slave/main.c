/*
 * CANopen main program file.
 *
 * Main file for zmq communication of CANopen application
 *
 * @file        main.c
 * @author      Timothy Mukhooli
 * @copyright   2026 TimothytheHolis
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

 #include "canopen_app.h"

int main(void)
{
    CANopenNode* canopennode = NULL;

    /* Create and initialize CANopen object */
    CANopenNode node = {
        .desiredNodeID = 1,
        .baudrate = 125,
        .activeNodeID = 0,
        .canOpenStack = NULL
    };

    canopennode = &node;
    canopen_app_init(canopennode);
    return 0;

    CO_CANrecv(canopennode->canOpenStack->CANmodule);
}