;;===============================
;;Name:
;;===============================

.orig x3000

MAIN
LD R6, STACK ;initialize stack pointer
;;=========================================================
;;Call GCD subroutine with correct arguments here
;;Store the result from the subroutine in ANSWER
;;=========================================================

HALT

STACK .fill xF000
N .fill 2688	; input n
M .fill 768		; input m
ANSWER .fill 0  ; save your answer here

GCD
;;=====================
;;Your subroutine here
;;=====================

.end
