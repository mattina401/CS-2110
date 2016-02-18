;;===============================
;;Name:Jongyeon Kim
;;===============================

.orig x3000
	
	AND R0, R0, 0	; R0 = R0 AND 0 (Clean R0)
	AND R1, R1, 0	; R1 = R1 AND 0 (Clean R1)

W	LD R0, ARRAY	; R0 <- mem[ARRAY]
	LD R1, LENGTH	; R1 <- mem[LENGTH]

	AND R2, R2, 0	; R2 = R2 AND 0 (clean R2)
	AND R3, R3, 0	; R3 = R3 AND 0 (Clean R3)
	ADD R3, R1, 0 	; R3 = R1 + 0	(LENGTH)
	
	AND R4, R4, 0	; R4 = R4 AND 0 (Clean R4)
	LD R4, ADDRESS	; R4 <- mem[ADDRESS]
	LDR R2, R0, 0	; R2 -> mem[R0 + 0]


L	AND R5, R5, 0	; R5 = R5 AND 0 (Clean R5)
	AND R6, R6, 0	; R6 = R6 AND 0 (Clean R6)
	
	LDR R5, R0, 0	; R5 <- mem[R0 + 0]
	NOT R5, R5	; ~R5
	ADD R5, R5, 1	; R5 = R5 + 1

	ADD R6, R2, R5	; R6 = R2 + R5
	BRzp N		; if R6 is zero or positive, move to N
	ADD R0, R0, 1	; R0 = R0 + 1
	ADD R3, R3, -1	; R3 = R3 - 1
	BRP L		; if R3 is positive, move to L
	BRZ F		; if R3 is zero, move to F

N	NOT R5, R5	; ~R5
	ADD R5, R5, 1	; R5 = R5 + 1
	ADD R2, R5, 0	; R2 = R5 + 0
	
	ST R0, ADDRESS	; R0 -> mem[ADDRESS]
	ADD R0, R0, 1	; R0 = R0 + 1
	ADD R3, R3, -1	; R3 = R3 - 1
	BRP L		; if R3 is positive, move to L
	BRZ F		; if R3 is zero, move to F

F	LD R0, ARRAY	; R0 <- mem[ARRAY]
	LDR R5, R0, 0	; R5 <- mem[R0 + 0]
	STI R5, ADDRESS; R5 -> mem[mem[ADDRESS]]	
	STI R2, ARRAY	; R2 -> mem[mem[ARRAY]]

	ADD R0, R0, 1	; R0 = R0 + 1
	ADD R1, R1, -1	; R1 = R1 - 1
	ST R0, ARRAY	; R0 -> mem[ARRAY]
	ST R1, LENGTH	; R1 -> mem[LENGTH]
	BRP W		; if R1 is positive, move to W
	HALT		; done



ARRAY   .fill x6000
LENGTH  .fill 3

ADDRESS .fill 0

.end

.orig x6000
.fill 4
.fill 6
.fill 60

.end

