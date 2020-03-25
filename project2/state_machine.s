	.arch msp430g2553
	.p2align 1,0

jt:	.word case0		;Jump table 
	.word case1
	.word case2
	.word case3

	.text
	.global led_state 	;Symbol for function

led_state:
	mov r12, r13		;functions passed in r12
	cmp #4, r13
	jge done
	add r13, r13
	mov jt(r13), r0

case0:	and.b #0x40, &P1OUT	;turns on green LED
	bic.b #0x01, &P1OUT
	jmp done

case1:	bis.b #0x01, &P1OUT 	;turns on red LED
	bic.b #0x40, &P1OUT
	jmp done

case2:	bis.b #0x01, &P1OUT	;turns on BOTH LED
	bic.b #0x40, &P1OUT
	jmp done

case3:	and.b #0, &P1OUT	;off the LED
	jmp done

done:	ret
