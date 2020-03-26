	.arch msp430g2553
	
	.text
	.global update_state
update_state:
	cmp.b #0, switch_state_down1
	jz fi
	mov.b #0, state
	call #buzzer_set_period
fi:
	cmp.b #0, switch_state_down2
	jz fi2
	mov.b #1, state
	call #buzzer_set_period
fi2:
	cmp.b #0, switch_state_down3
	jz fi3
	mov.b #2, state
	call #buzzer_set_period
fi3:
	cmp.b #0, switch_state_down4
	jz end
	mov.b #3, state
end:	
	ret

	.text
	.global state_advance
state_advance:
	cmp.b #0, state
	jz case_0
	cmp.b #1, state
	jz case_1
	cmp.b #2, state
	jz case_2
	cmp.b #3, state
	jz case_3
case_0:
	mov.b #0, blinking_state
	call #toggle_leds
	mov #0, song_state
	jmp break
case_1:
	mov.b #0, blinking_state
	call #toggle_red
	mov #0, song_state
	jmp break
case_2:
	mov.b #0, blinking_state
	call #toggle_green
	mov #0, song_state
	jmp break
case_3:	
	mov.b #1, blinking_state
	call #toggle_leds
	call #play_song
	jmp break
	
break:	mov.b #1, led_changed
	call #led_update
	ret
	
