.name		"alive"
.comment	"I AM ALIVE"

start:
	sti		r1, %:alive, %1

alive:
	live	%666
	fork	%:alive
	ld		%0, r2
	zjmp	%:war

war:
	ld		%33554431, r9	# live %0
	st		r9, 500
	ld		%0, r2
	zjmp	%:alive
