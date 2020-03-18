	.data
	.global state
state: 	.byte 0			
    
    	.text
	.global switch_state
switch_state: 
	sub #2, r1
	mov r12, 0(r1)
	mov 0(r1), state 	; probably cannot do this

	mov state, r12
	add #2, r1
	ret	
	
