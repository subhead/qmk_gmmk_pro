; https://github.com/qmk/qmk_firmware/blob/master/keyboards/1upkeyboards/super16/keymaps/ahk_companion/ahk_companion.ahk
#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
#Singleinstance force
SetFormat, float, 0
#Persistent



;=================================================================
;                      Macro Pad Shortcuts                       ;
;=================================================================

;=================================================================
;                       Layer 0 F13-F24
;;=================================================================
;Row 1

F13::Send a
F14::Send b
F15::Send c
F16::Send d

;Row 2

F17::Send e
F18::Send f
F19::Send g
F20::Send h

;Row 3

F21::Send i
F22::Send j
F23::Send k
F24::Send l


;=================================================================
;                       Layer 1 ALT+F13-F24
;;=================================================================
;Row 1

!F13::Send m
!F14::Send n
!F15::Send o
!F16::Send p

;Row 2

!F17::Send q
!F18::Send r
!F19::Send s
!F20::Send t

;Row 3

!F21::Send u
!F22::Send v
!F23::Send w
!F24::Send x


;=================================================================
;                       Layer 2 SHIFT+F13-F24
;;=================================================================
;Row 1

+F13::Send y
+F14::Send z
+F15::Send A
+F16::Send B

;Row 2

+F17::Send C
+F18::Send D
+F19::Send E
+F20::Send F

;Row 3

+F21::Send G
+F22::Send H
+F23::Send I
+F24::Send J

;=================================================================
;                       Layer 3 CTRL+F13-F24
;;=================================================================
;Row 1

^F13::Send K
^F14::Send L
^F15::Send M
^F16::Send N

;Row 2

^F17::Send O
^F18::Send P
^F19::Send Q
^F20::Send R

;Row 3

^F21::Send S
^F22::Send T
^F23::Send U
^F24::Send V