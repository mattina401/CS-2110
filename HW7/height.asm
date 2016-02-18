;;===============================
;;Name:
;;===============================

.orig x3000

MAIN
LD R6, STACK ;initialize stack pointer
;;=========================================================
;;Call HEIGHT subroutine with correct arguments here
;;Store the result from the subroutine in ANSWER
;;=========================================================

HALT

STACK .fill xF000
ARRAY .fill x6000   ; address of the array
INDEX .fill 1       ; starting index
ANSWER .fill 0      ; save your answer here

HEIGHT
;;=====================
;;Your subroutine here
;;=====================

;;===============================================================================================================
;; You should not modify any code beyond this point. (You may add some lines at the bottom after this subroutine)
;;===============================================================================================================
;; A working division/modulo subroutine for positive numbers only.
;;
;; This subroutine takes two arguments in R0 and R1, and has two return values
;; also in R0 and R1. For clarity the argument in R0 will be referred to as X, 
;; and the argument in R1 will be referred to as Y.
;;
;; The result of this subroutine is that R0 will contain X divided by Y using 
;; integer devision and R1 will contain the remainder of that devision.
;; R0 = X/Y
;; R1 = X%Y
;;
;; Preconditions:
;;  R6 is the stack pointer and points to the last used stack location
;;  R0 is between 0 and 32767
;;  R1 is between 1 and 32767
;;
;; Postconditions:
;;  R0 <- R0 / R1
;;  R1 <- R0 % R1
;;
UDIV
.fill x0042
.fill x1DBB
.fill x7F84
.fill x7B83
.fill x7982
.fill x7781
.fill x7580
.fill xEA2E
.fill x947F
.fill x14A1
.fill x56E0
.fill x16FF
.fill x16E1
.fill x1943
.fill x7500
.fill x1482
.fill x09FB
.fill x5260
.fill x1943
.fill x6500
.fill x1480
.fill x0804
.fill x10A0
.fill x1930
.fill x6500
.fill x1242
.fill x16FF
.fill x07F6
.fill x1460
.fill x1220
.fill x10A0
.fill x6580
.fill x6781
.fill x6982
.fill x6B83
.fill x6F84
.fill x1DA5
.fill xC1C0
.fill x0001
.fill x0002
.fill x0004
.fill x0008
.fill x0010
.fill x0020
.fill x0040
.fill x0080
.fill x0100
.fill x0200
.fill x0400
.fill x0800
.fill x1000
.fill x2000
.fill x4000
.fill x8000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.fill x0000
.end

.orig x6000
.fill 0     
.fill 8     ;row 1
.fill 3     ;row 2
.fill 10   
.fill 1     ;row 3
.fill 6
.fill 0
.fill 14
.fill 0     ;row 4
.fill 0
.fill 4
.fill 7
.fill 0
.fill 0
.fill 13
.fill 0
.fill 0     ;row 5
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.fill 0
.end
