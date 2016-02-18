;;===============================
;;Name: Jongyeon Kim
;;===============================

.orig x3000

; CODE GOES HERE :)

	LD R1, U	; R1 <- mem[U]
	NOT R1, R1	; not R1
	ADD R1, R1, 1	; R1 = R1 + 1 
	ST R1, ANSWER	; mem[ANSWER] <- R1
	HALT




U       .fill 8
ANSWER  .fill 0
.end

