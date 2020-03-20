	.arch msp430g2553

	.extern "stateMachines.h"
	.extern "switches.h"
	.extern "buzzer.h"
	
	.extern	state

	.extern switch_state_down1
	.extern switch_state_down2
	.extern switch_state_down3
	.extern switch_state_down4

	.extern buzzer_set_period
	
	.text	
	.global update_state
update_state: 
	cmp #0, switch_state_down1
	jz fi
	mov.b #0, state
	call #buzzer_set_period 
	jmp end
fi:	
	cmp #0, switch_state_down2
	jz fi2
	mov.b #1, state
	call #buzzer_set_period
	jmp end
fi2:	
	cmp #0, switch_state_down3
	jz fi3
	mov.b #2, state
	call #buzzer_set_period
	jmp end
fi3:
	cmp #0, switch_state_down4
	jz end
	mov.b #3, state
end:
	ret
	
