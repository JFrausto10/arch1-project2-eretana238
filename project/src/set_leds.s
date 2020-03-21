	.arch msp430g2553

	
	.text	
	.global led_reset
led_reset:
	mov.b #0, red_on
	mov.b #0, green_on
	ret

	.global led_red_on
led_red_on:
	mov.b #1, red_on
	mov.b #0, green_on
	ret
	
	.text
	.global led_green_on
led_green_on:
	mov.b #0, red_on
	mov.b #1, green_on
	ret

	.global toggle_red
toggle_red:
	xor.b #1, red_on
	mov.b #0, green_on
	ret
	
	.global toggle_green
toggle_green:	
	xor.b #1, green_on
	mov.b #0, red_on
	ret

	
