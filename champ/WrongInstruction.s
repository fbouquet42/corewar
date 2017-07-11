.name		"jsy"
.comment	"I AM PROOT"

start:
	ld		%33554431, r9	# live %0
	st		r1, 6

alive:
	live	%0
	fork	%:alive
	ld		%0, r2
	zjmp	%:war

war:
	st		r9, %42
	ld		%0, r2
	zjmp	%:alive
