	.arch msp430g2553

	.text
JT:
	.word default	 
	.word case1
	.word case2
	.word case3
	.word case4

	.global state_advance
state_advance:
	mov.b #5, r13
	mov.b state, r12
	cmp.b r12, r13
	jlo default
	add r12, r12
	mov JT(r12), r0
case1:
	mov.b #1, blinking_state
	call #toggle_leds
	mov #0, song_state
	jmp break
case2:
	mov.b #0, blinking_state
	call #toggle_red
	mov #0, song_state
	jmp break
case3:
	mov.b #0, blinking_state
	call #toggle_green
	mov #0, song_state
	jmp break
case4:
	mov.b #1, blinking_state
	call #toggle_leds
	call #play_song
	jmp break

default:
	
break:
	mov.b #1, led_changed
	call #led_update
	ret
	

