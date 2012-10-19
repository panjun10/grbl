/*
  protocol.h - the serial protocol master control unit
  Part of Grbl

  Copyright (c) 2009-2011 Simen Svale Skogsrud
  Copyright (c) 2011-2012 Sungeun K. Jeon

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef protocol_h
#define protocol_h

#define STATUS_OK 0
#define STATUS_BAD_NUMBER_FORMAT 1
#define STATUS_EXPECTED_COMMAND_LETTER 2
#define STATUS_UNSUPPORTED_STATEMENT 3
#define STATUS_FLOATING_POINT_ERROR 4
#define STATUS_MODAL_GROUP_VIOLATION 5
#define STATUS_INVALID_COMMAND 6
#define STATUS_SETTING_DISABLED 7
#define STATUS_HARD_LIMIT 8

#define LINE_BUFFER_SIZE 50

// Initialize the serial protocol
void protocol_init();

// Read command lines from the serial port and execute them as they
// come in. Blocks until the serial buffer is emptied. 
void protocol_process();

// Executes one line of input according to protocol
uint8_t protocol_execute_line(char *line);

// Checks and executes a runtime command at various stop points in main program
void protocol_execute_runtime();

// Prints g-code parser status message.
void protocol_status_message(int8_t status_code);

#endif
