DEPS=types.ept
SOURCES=main.ept

compile: heptagon main

main:
	gcc --std=c99 -I. -Itypes_c/ main.c main_c/main.c types_c/types.c externc.c bitrev.c sndio.c -lm

heptagon:
	heptc -target c ${DEPS}
	heptc -c externc.epi
	heptc -c fftc.epi
	heptc -c sndio.epi
	heptc -target c ${SOURCES}
	
clean:
	rm *.epci *mls
