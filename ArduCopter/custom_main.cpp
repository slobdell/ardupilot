#include "Copter.h"
#include "custom_main.h"
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_SerialManager/AP_SerialManager.h>
#include <RC_Channel/RC_Channel.h>

const int BAUD = 115200;
const int SERIAL_NUM = 4;
// This is your new main entry point when RUN_CUSTOM_LOOP is true.
void newMain()
{
    // One-time initialization for our debug serial port.
    static bool serial_initialized = false;
    if (!serial_initialized) {
        // Begin the serial port at 115200 baud.
        // The second argument 'false' means we are not using it for MAVLink.
        AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
        if (debug_uart != nullptr) {
            debug_uart->begin(BAUD);
            serial_initialized = true;
        }
    }

    // This function is called at ~400Hz. We need to slow down our printing
    // to avoid flooding the serial port. A static counter is a simple way to do this.
    static uint16_t counter = 0;
	if (!AP::ahrs().healthy()) {
	  counter++;
      if (counter % 100 == 0) {
          AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
          debug_uart->printf("Not arming because AHRS is not healthy.");
      }
      return;
	}

    // Get attitude data
    float roll_rad = 0;
    float pitch_rad = 0;
    AP::vehicle()->get_osd_roll_pitch_rad(roll_rad, pitch_rad);
    float yaw_rad = AP::ahrs().get_yaw();

    // Convert to degrees
    float roll_deg = degrees(roll_rad);
    float pitch_deg = degrees(pitch_rad);
    float yaw_deg = degrees(yaw_rad);
    if (counter % 100 == 0) {

        AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
        debug_uart->printf("Attitude: R:%.1f P:%.1f Y:%.1f\n", roll_deg, pitch_deg, yaw_deg);
        exampleReadInput();
    }

    counter++;
}

void exampleReadInput() {
    AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
	// Read all 16 SBUS channels. get_radio_in() returns a PWM value (e.g., 1000-2000).
	uint16_t sbus_in[16];
	for (int i = 0; i < 16; i++) {
		sbus_in[i] = RC_Channels::get_radio_in(i);
	}

	debug_uart->printf("SBUS: 1:%u 2:%u 3:%u 4:%u 5:%u 6:%u 7:%u 8:%u 9:%u 10:%u 11:%u 12:%u 13:%u 14:%u 15:%u 16:%u\n",
						sbus_in[0], sbus_in[1], sbus_in[2], sbus_in[3],
						sbus_in[4], sbus_in[5], sbus_in[6], sbus_in[7],
						sbus_in[8], sbus_in[9], sbus_in[10], sbus_in[11],
						sbus_in[12], sbus_in[13], sbus_in[14], sbus_in[15]);
}

/**
 * @brief Writes arbitrary, fixed PWM values to the first 4 SBUS output channels.
 *
 * This function is for hardware validation. It allows you to connect an SBUS
 * receiver or parser to the configured SBUS output port and verify that the
 * signal is being generated correctly.
 *
 * Assumes an SBUS output port has been configured via parameters (e.g., SERIAL1_PROTOCOL = 30).
 */
void exampleOutput()
{
    // SRV_Channels are 0-based, so Channel 1 is index 0.
    // The values are standard PWM microseconds.

    SRV_Channels::set_output_pwm_chan(0, 1000);

    // Channel 1: Set to minimum value
    SRV_Channels::set_output_pwm_chan(1, 1000);

    // Channel 2: Set to middle value
    SRV_Channels::set_output_pwm_chan(2, 1500);

    // Channel 3: Set to maximum value
    SRV_Channels::set_output_pwm_chan(3, 2000);

    // Channel 4: Set to a unique, arbitrary value for easy identification
    SRV_Channels::set_output_pwm_chan(4, 1234);

    // Channels 5-16 will default to their trim value (usually 1500) or 0 if not enabled.
}
