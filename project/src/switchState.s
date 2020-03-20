	.arch msp430g2553

	.extern "stateMachines.h"
	.extern	state
    
    .text
	.globl switch_state
switch_state: 
	sub #2, r1
	mov.b r12, 0(r1)
	mov.b 0(r1), state 	; probably cannot do this
	mov.b state, r12
	add #2, r1
	ret	
	
