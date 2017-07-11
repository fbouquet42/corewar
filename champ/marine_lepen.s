.name "marine_lepen"
.comment "le plus francais de tous les champions"

#load in r1 my r1 #size 7

live	%1 #say i'm alive size 5

st	r1, -4 #store live size 5

ld	%42991616, r2 # size 7
st	r2, -24 #size 5
ld	%1, r3 #size 7
st r3, -33 #size 5
st	r1, -39 #size 5
####

ld	%24, r10
ld	%-24, r11

####
st r1, 6
live:	live %1
