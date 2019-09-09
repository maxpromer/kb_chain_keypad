Blockly.JavaScript['kb_chain_keypad_on_pess'] = function(block) {
	var statements_callback = Blockly.JavaScript.statementToCode(block, 'callback');
	var code = 'DEV_I2C1.PCF8574(0, 0x20).onPess([]() { ' + statements_callback + ' });\n';
	return code;
};

Blockly.JavaScript['kb_chain_keypad_on_release'] = function(block) {
	var statements_callback = Blockly.JavaScript.statementToCode(block, 'callback');
	var code = 'DEV_I2C1.PCF8574(0, 0x20).onRelease([]() { ' + statements_callback + ' });\n';
	return code;
};

Blockly.JavaScript['kb_chain_keypad_get_key'] = function(block) {
	var code = 'DEV_I2C1.PCF8574(0, 0x20).getKey()';
	return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['kb_chain_keypad_get_key_string'] = function(block) {
	var code = 'DEV_I2C1.PCF8574(0, 0x20).getKeyString()';
	return [code, Blockly.JavaScript.ORDER_NONE];
};
