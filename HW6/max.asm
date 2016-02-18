;;===============================
;;Name: Jongyeon Kim
;;===============================

.orig x3000

;; CODE GOES HERE :)

	LD R0, ARRAY
	LD R1, LENGTH
	LD R2, MAX

	LDR R2, R0, 0	; R2 <- mem[R0 + 0]
L	ADD R0, R0, 1	; R0 = R0 + 1
	ADD R1, R1, -1	; R1 = R1 - 1
	BRz F		; if R1 is zero, move to F
	LDR R3, R0, 0	; R3 <- mem[R0 + 0]
	NOT R3, R3	; not R3
	ADD R3, R3, 1	; R3 = R3 + 1
	ADD R4, R2, R3	; R4 = R2 + R3
	BRn N		; if R4 is negative, move to N
	BRzp L		; if R4 is zero or positive, move to L
F	ST R2, MAX	; mem[R2] -> MAX
	HALT		; finish
	

N	NOT R3, R3	; not R3
	ADD R3, R3, 1	; R3 = R3 + 1
	ADD R2, R3, 0	; R2 = R3 + 0
	BR L		; move to L

	
ARRAY   .fill x6000
LENGTH  .fill 10
MAX	.fill 0
.end

.orig x6000
.fill 8
.fill 4
.fill 7
.fill 0
.fill -3
.fill 11
.fill 5
.fill -9
.fill 2
.fill 4
.end
