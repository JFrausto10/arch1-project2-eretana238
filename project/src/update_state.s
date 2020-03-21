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
