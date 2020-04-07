	.arch msp430g2553

	.global state
	
	.text
JT:
	.word case0
	.word case1
	.word case2
	.word case3
	.word default

	.global state_advance
state_advance:
	mov.b state, r13
	;; TODO: compare if state is within range
	add r13, r13
	mov JT(r13), r0
case0:
	mov.b #1, blinking_state
	call #toggle_leds
	mov #0, &song_state
	jmp break
case1:
	mov.b #0, blinking_state
	call #toggle_red
	mov #0, &song_state
	jmp break
case2:
	mov.b #0, blinking_state
	call #toggle_green
	mov #0, &song_state
	jmp break
case3:
	mov.b #1, blinking_state
	call #toggle_leds
	call #play_song
	jmp break

default:
	
break:
	mov.b #1, led_changed
	call #led_update
	ret
	

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

