	.arch msp430g2553

	.text
JT:				; defined jump table
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.global state_advance	; get state advance from stateMachines.h
state_advance:
	mov.b state, r12
	cmp.b #5, state		; range check for state, if 5 or higher goto default
	jc default
	add r12, r12
	mov JT(r12), r0
case1:
	mov.b #1, blinking_state ; toggles leds green and red
	call #toggle_leds
	mov #0, song_state	; stops song if it was active
	jmp break
case2:
	mov.b #0, blinking_state ; dims red led
	call #toggle_red
	mov #0, song_state	; stops song if it was active
	jmp break
case3:
	mov.b #0, blinking_state ; dims green led
	call #toggle_green
	mov #0, song_state	; stops song if it was active
	jmp break
case4:
	mov.b #1, blinking_state 
	call #toggle_leds	; toggles leds green and red
	call #play_song
	jmp break

default:
	
break:
	mov.b #1, led_changed 	; update leds
	call #led_update
	ret
	

