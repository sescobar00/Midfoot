// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

// MIDI CC codes for generic on/off switches (80, 81, 82, 83)
// Off: 0-63
// On:  64-127

#define MIDI_CC_OFF 0
#define MIDI_CC_ON  127

enum custom_keycodes {
    MIDI_CC80 = SAFE_RANGE,
	MIDI_CC81,
	MIDI_CC82,
	MIDI_CC83,
	MIDI_CC84
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
    switch (keycode) {
        case MIDI_CC80:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
            }
            return true;
        case MIDI_CC81:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 81, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 81, MIDI_CC_OFF);
            }
            return true;
        case MIDI_CC82:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 82, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 82, MIDI_CC_OFF);
            }
            return true;
        case MIDI_CC83:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 83, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 83, MIDI_CC_OFF);
            }
            return true;
        case MIDI_CC84:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 84, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 84, MIDI_CC_OFF);
            }
            return true;
	}
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *   ┌───┬───┐
     *   │80 │81 │
     * ┌─┴─┬─┴─┬─┴─┐
     * │82 │83 │84 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
			MIDI_CC80, MIDI_CC81,
		MIDI_CC82, MIDI_CC83, MIDI_CC84
    )
	
};
