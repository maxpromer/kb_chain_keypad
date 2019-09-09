#ifndef __PCF8574_CPP__
#define __PCF8574_CPP__

#include "pcf8574.h"

PCF8574::PCF8574(int bus_ch, int dev_addr) {
	channel = bus_ch;
	address = dev_addr;
	polling_ms = 100;
}

void PCF8574::init(void) {
	// clear error flag
	error = true;
	// set initialized flag
	initialized = false;
	
	state = s_detect;
}

int PCF8574::prop_count(void) {
	// not supported
	return 0;
}

bool PCF8574::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool PCF8574::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool PCF8574::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool PCF8574::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool PCF8574::prop_write(int index, char *value) {
	// not supported
	return false;
}
// --------------------------------------

void PCF8574::process(Driver *drv) {
	I2CDev *i2c = (I2CDev *)drv;
	switch (state) {
		case s_detect:
			// detect i2c device
			if (i2c->detect(channel, address) == ESP_OK) {
				state = s_read;
			} else {
				state = s_error;
			}
			break;
	
		case s_read: {
			if (is_tickcnt_elapsed(tickcnt, polling_ms)) {
				tickcnt = get_tickcnt();

				uint8_t reg = 0x00;
				uint8_t data;
				
				uint8_t row = 0, col = 0;

				reg = 0x0F;
				if (i2c->read(channel, address, &reg, 1, &data, 1) != ESP_OK) {
					state = s_error;
				}

				switch(data) {
					case 0x0E : row = 1; break;
					case 0x0D : row = 2; break;
					case 0x0B : row = 3; break;
					case 0x07 : row = 4; break;
					default : row = 0;
				}

				reg = 0xF0;
				if (i2c->read(channel, address, &reg, 1, &data, 1) != ESP_OK) {
					state = s_error;
				}

				switch(data) {
					case 0xE0 : col = 1; break;
					case 0xD0 : col = 2; break;
					case 0xB0 : col = 3; break;
					case 0x70 : col = 4; break;
					default : col = 0;
				}
		
				if(row > 0 && col > 0) {
					if(last_key == 0xFF) {
						last_key = keypad[row-1][col-1];
						if (onPessCallback) onPessCallback();
					}
				} else {
					if(last_key != 0xFF) {
						if (onReleaseCallback) onReleaseCallback();
						last_key = 0xFF;
					}
				}
			}
		}
		
		case s_wait:
			if (error) {
				// wait polling_ms timeout
				if (is_tickcnt_elapsed(tickcnt, polling_ms)) {
					state = s_detect;
				}
			}
			break;

		case s_error:
			last_key = 0;
			
			// set error flag
			error = true;
			// clear initialized flag
			initialized = false;
			// get current tickcnt
			tickcnt = get_tickcnt();
			// goto wait and retry with detect state
			state = s_wait;
			break;

	}
}

// Method
void PCF8574::onPess(KeypadEventCallback cb) {
	onPessCallback = cb;
}

void PCF8574::onRelease(KeypadEventCallback cb) {
	onReleaseCallback = cb;
}

char PCF8574::getKey() {
	return last_key;
}

char* PCF8574::getKeyString() {
	str_key[0] = last_key;
	return str_key;
}

#endif