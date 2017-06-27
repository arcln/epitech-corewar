#
# my_champion.s for corewar
#
# Arthur Chaloin
#	
# Sun Feb 26 23:42:21 2017
#
.name "lol"
.comment "the beast"

wall:   or r1, %0, r1
        zjmp %:wall

start:  ld 6, r2
        sti r2, %:wall, %0
        sti r1, %:main, %1
        and r1, %0, r1
        fork %:childmain
        sti r1, %:start, %0

main:   live %42
        zjmp %:main

childmain:  fork %:childmain2
            ldi %:torp, %0, r2
            ld %8, r3
            ld %0, r4
            zjmp %:torp
            
childmain2: ldi %:torp, %4, r2
            ld %8, r3
            ld %4, r4
            zjmp %:torp
            
torp:       sti r2, r3, r4
