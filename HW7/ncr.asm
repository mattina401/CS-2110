;;===============================
;;Name: Your name here
;;===============================
.orig x3000

MAIN
LD R6, STACK ;initialize stack pointer
;;=========================================================
;;Call NCR subroutine with correct arguments here
;;Store the result from the subroutine in ANSWER
;;=========================================================
LD R0, N		; load n
LD R1, M		; load r
ADD R6, R6, -2 	; move the stack pointer
STR R0, R6, 1 	; push n into the stack
STR R1, R6, 0	; push r into the stack
JSR NCR		; call NCR
LDR R0, R6, -3	; load answer to R0
ST R0, ANSWER	; store answer
HALT		; stop program

STACK .fill xF000
N .fill 12	; input n
R .fill 4	; input r
ANSWER .fill 0  ; save your answer here

NCR
;;=====================
;;Your subroutine here
;;=====================

	
.end
