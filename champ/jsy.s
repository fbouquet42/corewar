.name		"jsy"
.comment	"I AM PROOT"

start:
	sti		r1, %:alive, %1

alive:
	live	%0
	fork	%:alive
#	ld		%0, r2
#	zjmp	%:war

war:
	ld		%14764933620, r15
	st		r15, 500
	ld		%0, r2
	zjmp	%:alive
