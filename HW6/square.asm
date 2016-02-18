;;===============================
;;Name:
;;===============================

.orig x3000

; CODE GOES HERE :)

	LD R0, U
	LD R1, ANSWER

	AND R2, R2, 0	; R2 = sum
	AND R3, R3, 0
A	Add R3, R0, 0
	ADD R0, R0, 0
	BRn N

L	ADD  R3, R3, 0	
	BRnz F
	ADD R2, R2, R0
	ADD R3, R3, -1
	BR L

F	ST R2, ANSWER
	HALT

N	NOT R0, R0
	ADD R0, R0, 1
	BR A

	
	
U       .fill 8
ANSWER  .fill 0
.end

