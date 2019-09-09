Blockly.Blocks['kb_chain_keypad_on_pess'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.KB_CHAIN_KEYPAD_ON_PESS_MESSAGE,
			"args0": [{
				"type": "input_dummy"
			}, {
				"type": "input_statement",
				"name": "callback"
			}],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 300,
			"tooltip": Blockly.Msg.KB_CHAIN_KEYPAD_ON_PESS_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['kb_chain_keypad_on_release'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.KB_CHAIN_KEYPAD_ON_RELE_MESSAGE,
			"args0": [{
				"type": "input_dummy"
			}, {
				"type": "input_statement",
				"name": "callback"
			}],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 300,
			"tooltip": Blockly.Msg.KB_CHAIN_KEYPAD_ON_RELE_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['kb_chain_keypad_get_key'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.KB_CHAIN_KEYPAD_GET_KEY_MESSAGE,
			"output": "Number",
			"colour": 300,
			"tooltip": Blockly.Msg.KB_CHAIN_KEYPAD_GET_KEY_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['kb_chain_keypad_get_key_string'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.KB_CHAIN_KEYPAD_GET_KEY_STRING_MESSAGE,
			"output": "String",
			"colour": 300,
			"tooltip": Blockly.Msg.KB_CHAIN_KEYPAD_GET_KEY_STRING_TOOLTIP,
			"helpUrl": ""
		});
	}
};
