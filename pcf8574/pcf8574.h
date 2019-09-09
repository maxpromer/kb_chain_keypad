#ifndef __PCF8574_H__
#define __PCF8574_H__

#include "driver.h"
#include "device.h"
#include "i2c-dev.h"
#include "kidbright32.h"

typedef void(*KeypadEventCallback)(void);

class PCF8574 : public Device {
	private:		
		enum {
			s_detect,
			s_read,
			s_wait,
			s_error
		} state;
		TickType_t tickcnt, polling_tickcnt;
		
		char last_key = 0;
		char str_key[2] = { 0x0, 0x0 };

		KeypadEventCallback onPessCallback = NULL, onReleaseCallback = NULL;

		char keypad[4][4] = {
								{'1', '2', '3', 'A'},
								{'4', '5', '6', 'B'},
								{'7', '8', '9', 'C'},
								{'*', '0', '#', 'D'}
							};

	public:
		// constructor
		PCF8574(int bus_ch, int dev_addr) ;
		
		// override
		void init(void);
		void process(Driver *drv);
		int prop_count(void);
		bool prop_name(int index, char *name);
		bool prop_unit(int index, char *unit);
		bool prop_attr(int index, char *attr);
		bool prop_read(int index, char *value);
		bool prop_write(int index, char *value);
		
		// method
		void onPess(KeypadEventCallback cb) ;
		void onRelease(KeypadEventCallback cb) ;
		char getKey() ;
		char* getKeyString() ;
		
		
};

#endif